---
layout: post
title:  "Min-max polynomials for when built-in libraries just don't cut it"
date:   2018-01-28 00:16:54 -0800
categories: scientific computing
---
If you're a regular C/C++ programmer who's working on an algorithm that is bottlenecked by calls to transcendental functions like $$\sin(x)$$, $$e^{x}$$, or $$\arccos(x)$$, this blog post is for you! If you're a regular C/C++ programmer who doesn't know where your code is being bottlenecked -- get a profiler (gprof is your friend). 

Transcendental functions are expensive to evaluate (especially in the C standard library), but polynomials are fast and easy to program. It makes sense to do some sort of polynomial approximation of these functions and, if the degree of the polynomial is high enough, the approximation should be sufficiently accurate. 