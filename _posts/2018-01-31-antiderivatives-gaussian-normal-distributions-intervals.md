---
layout: post
title:  "Integrals of some Gaussian functions"
date:   2018-01-31 00:00:00 -0800
categories: calculus statistics
---

# Integrals of some Gaussian functions
In this blog post, we're going to explicitly calculate some analytical expressions for integrals of gaussian functions. Why? Because math! Also these expressions came up in my work recently in the context of the [Lloyd-Max Algorithm](https://en.wikipedia.org/wiki/Quantization_(signal_processing)#Neglecting_the_entropy_constraint:_Lloyd%E2%80%93Max_quantization) for quantizing a signal and I couldn't find these explicit expressions around the internet. They're pretty straightforward, albeit tedious, to derive, so hopefully this post saves you some time. Onwards!

## Notation
Let 
\\[
\phi(x) = \dfrac{1}{\sqrt{2\pi}} e^{-x^2/2}
\\]
is the probability density function (pdf) of a Gaussian random variable (r.v.) with mean $$0$$ and variance $$1$$ 

and a Gaussian r.v. with mean $$\mu$$ and variance $$\sigma$$ has pdf 
\\[
\phi_{\mu, \sigma}(x) = \dfrac{1}{\sigma}\phi\left(\dfrac{x-\mu}{\sigma}\right).
\\]

The cumulative distribution function is 
\\[
\Phi(x) = \int_{-\infty}^{x} \phi(t)dt.
\\]

## Integral identities 

We have that

\\[
\begin{equation}
\label{eq1}
\int_{-\infty}^{b} (x-y)^2 \phi_{\mu, \sigma}(x) dx = \Phi(z) (\mu_s^2 + \sigma^2) - (2\mu_s \sigma + \sigma^2 z)\phi(z)
\end{equation}
\\]

where 

\\[
\mu_s = \mu - y, \quad z = \dfrac{b-y-\mu_s}{\sigma}
\\]

and 

\\[
\begin{equation}
\label{eq2}
\int_{-\infty}^{b} x \phi_{\mu, \sigma}(x) dx = \mu \Phi(z) - \sigma \phi(z)
\end{equation}
\\]

where 
\\[
    z = \dfrac{b-\mu}{\sigma}
\\]


## Proof

Some useful identities are 

\begin{align}
\int_{-\infty}^{x} t \phi(t)dt &= -\phi(x) \notag \\\
\int_{-\infty}^{x} t^2 \phi(t)dt &= \Phi(x) - x\phi(x)\notag
\end{align}


We use the substitution $$t = x-y$$ in $$\eqref{eq1}$$ to yield

\\[
\int_{-\infty}^{b-y} t^2 \phi_{\mu,\sigma}(t+y)dt
\\]

and $\phi_{\mu, \sigma}(t+y) = \phi_{\mu-y,\sigma}(t)$, so we merely need to compute

\\[
\int_{-\infty}^{b'} t^2 \phi_{\mu',\sigma}(t)dt
\\]

with $b' = b-y$, $\mu'=\mu-y$. 


