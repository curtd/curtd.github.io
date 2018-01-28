---
layout: post
title:  "Min-max polynomials -- for when built-in libraries just don't cut it"
date:   2018-01-28 00:16:54 -0800
categories: scientific computing
---

# Speeding up those tricky slow transcendental functions
If you're a regular C/C++ programmer who's working on an algorithm that is bottlenecked by calls to transcendental functions like $$\sin(x)$$, $$e^{x}$$, or $$\arccos(x)$$, this blog post is for you! If you're a regular C/C++ programmer who doesn't know where your code is being bottlenecked -- get a profiler (gprof is your friend). This post is mostly targeted at people who work in an environment where external C++ libraries aren't always easy to integrate into your code. In my context at work, I was working on an algorithm that was being called from Python via SWIG, which was running in a Docker container, and it was too much of a pain to try integrate an existing fast implementation of these functions into the image. Alas, we'll do it live.

The standard math library in C++ (aka the C math library) is accurate, albeit painfully slow. Below are some timings of various transcendental functions evaluated on my home setup. 

 

Transcendental functions are expensive to evaluate (especially in the C standard library), but polynomials are fast and easy to program. It makes sense to do some sort of polynomial approximation of these functions and, if the degree of the polynomial is high enough, the approximation should be sufficiently accurate. First year calculus gives us a tool for computing such approximations, the good ol' Taylor series!

$$
f(x) = \displaystyle\sum_{n=0}^{\infty} \dfrac{f^{(n)}(a)}{n!}(x-a)^n.
$$
Here $$x=a$$ is the point around with the series is centered. 

It stands to reason that, for a fixed polynomial degree $$N$$, we should be able to compute some derivatives, pop in some polynomial evaluation with Horner's rule, badda bing, badda boom, we're done. Right?

# Wrong

