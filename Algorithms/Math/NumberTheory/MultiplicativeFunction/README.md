# Multiplicative Function

There is one specific kind of function that shows importance in the study of number theory — the multiplicative function. By definition, A function $f(x)$ defined on all positive integers is multiplicative if it satisfies the following condition:

For every co-prime pair of integers $p$ and $q$, $f(pq) = f(p)f(q)$.
Great question — multiplicative functions are a really important concept in number theory, and the blog you shared gives a good start. Let’s build this step by step, so you not only understand the definition but also see why they’re so powerful.



## Consequence for ( f(1) )

From the definition, if you plug in $q=1$:

$
f(n) = f(n \cdot 1) = f(n) f(1).
$

So unless $f(n)=0$ for all $n$, we must have:

$
f(1) = 1.
$

That’s why in all standard multiplicative functions you’ll see $f(1)=1$.

---

## Prime power representation

A really neat fact:
If you know how  $f$ behaves on prime powers  $p^k$, then you know it everywhere.

Why? Every number can be uniquely factored as:

$
n = p_1^{a_1} p_2^{a_2} \cdots p_r^{a_r}.
$

Since the prime powers are coprime to each other, we get:

$
f(n) = f(p_1^{a_1}) f(p_2^{a_2}) \cdots f(p_r^{a_r}).
$

💡 So: *multiplicative functions are completely determined by their values on prime powers.*

---

## Common examples

Here are some classics (exactly like in your blog):

1. **Constant function**
   $$
   I(n) = 1.
   $$

2. **Power function**
   $$
   Id_a(n) = n^a.
   $$

3. **Unit function**
   $
   \varepsilon(n) = [n=1$.
   $
   (Kronecker delta: 1 if (n=1), else 0)

4. **Divisor function** (generalized sigma function):
   $$
   \sigma_a(n) = \sum_{d|n} d^a.
   $$

5. **Möbius function**
- For prime powers:
$$
\mu(n) =
\begin{cases}
1 & \text{if } n=1 \\
(-1)^k & \text{if } n = p_1 p_2 \cdots p_k \text{ where } p_i \text{ are distinct primes} \\
0 & \text{if } p^2 \mid n \text{ for some prime } p
\end{cases}
$$

6. **Euler’s totient function**
   $$
   \varphi(p^k) = p^k - p^{k-1}.
   $$

---


## Examples



### 1. **Identity function**

$
f(n) = n
$
Check: $ f(6) = 6 $.
Factor $6 = 2 \cdot 3$, with $\gcd(2,3)=1$.
$
f(6) = 6, \quad f(2)f(3) = 2 \cdot 3 = 6.
$
✅ Works.

---

### 2. **Euler’s totient function**

$
\varphi(n) = \text{\# of integers } \leq n \text{ coprime to } n.
$

- Prime power rule:
$$
\varphi(p^k) = p^k - p^{k-1}.
$$

Example: $ n=12=2^2 \cdot 3 $.
$$
\varphi(12) = \varphi(2^2) \cdot \varphi(3) = (4-2)(3-1) = 2 \cdot 2 = 4.
$$
And indeed, numbers coprime to 12 are (1,5,7,11).

---

### 3. **Divisor sum function**

$
\sigma(n) = \sum_{d|n} d
$

Example: $n=18 = 2 \cdot 3^2$.
$$
\sigma(18) = \sigma(2)\sigma(3^2) = (1+2)(1+3+9) = 3 \cdot 13 = 39.
$$
Check divisors directly: (1+2+3+6+9+18 = 39.) ✅

---

### 4. **Möbius function**

$$
\mu(n) =
\begin{cases}
1 & \text{if } n=1 \\
(-1)^k & \text{if } n = p_1 p_2 \cdots p_k \text{ where } p_i \text{ are distinct primes} \\
0 & \text{if } p^2 \mid n \text{ for some prime } p
\end{cases}
$$

Examples:

* $\mu(1) = 1$
* $\mu(6=2\cdot 3) = (-1)^2 = 1$
* $\mu(12=2^2\cdot 3) = 0$

---

### 5. **Constant function**

$$
I(n) = 1
$$
No matter what (n) is, always 1. Clearly multiplicative because (1 \cdot 1 = 1).

---

### 6. **Unit function**

$
\varepsilon(n) = [n = 1]
$
Also multiplicative.

---



## Multiplicative Function Using Sieve

### Euler's Totient Function


In the **linear sieve**, every number (x) is processed exactly once, as the product of some smallest prime (p) and another number (i).
This makes it efficient for computing not just primes, but also values of multiplicative functions.

---

### The three cases for ($x = i \cdot p$):

When you’re generating multiples in the sieve:

1. **Case 1: (x) is prime**

   * If (x) itself is prime, you can compute $f(x)$ directly (since prime powers are the building blocks).
   * Example: $\varphi(p) = p-1$.

2. **Case 2: ($x = i \cdot p$) and ($p \nmid i$)**

   * Then $\gcd(i,p)=1$.
   * By multiplicativity:
     $$
     f(x) = f(i \cdot p) = f(i) \cdot f(p).
     $$

3. **Case 3: ($x = i \cdot p$) and ($p \mid i$)**

   * Then we’re in a prime power situation, not coprime.
   * We need a special relation between (f(i)) and (f(i \cdot p)).
   * Example (Euler’s totient):
     $$
     \varphi(i \cdot p) = p \cdot \varphi(i).
     $$
     Because adding another (p) just multiplies the totient by (p).


> Algebraic proof 

Write $i$ as $i = p^k \cdot m$ where $k\ge 1$ and $p\nmid m$. (This is possible because $p$ divides $i$.)

We use two facts:

1. $\varphi$ is multiplicative on coprime factors, so
   $$
   \varphi(i)=\varphi(p^k),\varphi(m).
   $$
2. The totient of a prime power:
   $$
   \varphi(p^t)=p^t-p^{t-1}=p^{t-1}(p-1).
   $$

Now compute:
$$
\varphi(i)=\varphi(p^k)\varphi(m)=p^{k-1}(p-1),\varphi(m),
$$
and
$$
\varphi(i\cdot p)=\varphi(p^{k+1})\varphi(m)=p^{k}(p-1),\varphi(m).
$$
Comparing the two,
$$
\varphi(i\cdot p)=p\cdot\big(p^{k-1}(p-1),\varphi(m)\big)=p\cdot\varphi(i).
$$

Hence, $\varphi(ip)=p\varphi(i)$.


---

### Example: Linear sieve for totient $\varphi(n)$

> [C++ code for Totient Function](./TotientFunctionUsingSieve.cpp)


### Note

* The linear sieve isn’t just for primes.
* Because multiplicative functions are **prime-power driven**, you can adapt the sieve to compute **any multiplicative function** efficiently up to (n).
* The only tricky part is **Case 3** — where (p) divides (i). For each multiplicative function, you need to figure out the relation.


## Multiplicative of any function using sieve

- Well, it might not always be possible to find out a formula when $p$ divides $i$. For instance, I can write some random multiplicative function $f(p^k) = k$ which is difficult to infer a formula with.
- However, there is still a way to apply the linear sieve on such function. 


- Define `cnt[i]` = the **exponent of the smallest prime factor** of $i$.
* Example:

  * `cnt[12]` = 2 (since smallest prime factor is 2, and $12 = 2^2 \cdot 3$)
  * `cnt[18]` = 1 (since $18 = 2 \cdot 3^2$, smallest prime = 2 with exponent 1)

This gives you a handle on how to extend values when multiplying by the same smallest prime.

---

### ⚙️ How it fits in the sieve

When building up numbers $x = i \cdot p$ in the sieve:

1. **Case 1: (x) is prime**

   * Compute $f(p)$ directly.
   * Set `cnt[p] = 1`.

2. **Case 2: ($p \nmid i$)** (coprime case)

   * Multiplicativity works:
     $4
     f(x) = f(i) \cdot f(p).
     $$
   * Also set `cnt[x] = 1` (since (p) is the new smallest prime for x).

3. **Case 3: ($p \mid i$)**

   * Now the smallest prime of (i) is also (p).
   * So $x = i \cdot p$ has smallest prime (p) with exponent increased:
     $$
     \text{cnt}[x] = \text{cnt}[i] + 1.
     $$
   * Then use your function’s definition on prime powers to extend.
     For example, if $f(p^k)=k$, then:
     $$
     f(x) = f(\frac{i} { p^{\text{cnt}[i]}}) \cdot f(p^{\text{cnt}[i]+1}).
     $$

### Why that Work?


$$
f(x) = f\Big(\tfrac{i}{p^{\text{cnt}[i]}}\Big) \cdot f(p^{\text{cnt}[i]+1})
$$



#### Step 1. Recall the structure of a multiplicative function

A multiplicative function is determined entirely by its values on **prime powers**:
$$
f(n) = \prod_{q^k ,|, n} f(q^k).
$$
That is, factor (n) into prime powers, apply (f) on each prime power, then multiply.

---

#### Step 2. Factorize (i) using its smallest prime (p)

Suppose
$$
i = p^{\text{cnt}[i]} \cdot m
$$
where (m) is the remaining part of (i) and $\gcd(m, p) = 1$.

So:
$$
f(i) = f(p^{\text{cnt}[i]}) \cdot f(m).
$$

---

#### Step 3. Multiply (i) by (p)

Now look at
$$
x = i \cdot p = p^{\text{cnt}[i]+1} \cdot m.
$$

So the prime power of (p) has its exponent increased by 1.

---

#### Step 4. Apply multiplicativity again

By definition,
$$
f(x) = f(p^{\text{cnt}[i]+1}) \cdot f(m).
$$

But notice $f(m) = f(i / p^{\text{cnt}[i]})$ (since (m) is exactly that quotient).

So:
$$
f(x) = f\Big(\tfrac{i}{p^{\text{cnt}[i]}}\Big) \cdot f(p^{\text{cnt}[i]+1}).
$$



### 📝 Example with (f(p^k)=k)

* (f(2)=1), (f(2^2)=2), (f(2^3)=3), …
* (f(3)=1), (f(3^2)=2), …
* Suppose (i=12=2^2 \cdot 3). Smallest prime is 2, `cnt[12]=2`.
* Now (x=12 \cdot 2 = 24 = 2^3 \cdot 3).

  * Update `cnt[24] = cnt[12]+1 = 3`.
  * Then compute:
    [
    f(24) = f(3) \cdot f(2^3) = 1 \cdot 3 = 3.
    ]

So it works neatly!

