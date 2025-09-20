# 2-SAT Problem


## What is **2-SAT**?

The **2-SAT problem** is a special case of the **Boolean satisfiability problem (SAT)** where:

* You have a set of **Boolean variables** (like $x_1, x_2, x_3, \dots$) which can be either **true** or **false**.
* The constraints (called **clauses**) are of the form:
  $(a \lor b)$
  where $a$ and $b$ are either a variable (like $x_1$) or its negation (like $\lnot x_2$).
* The question is: **Is there an assignment of True/False values to all variables that makes all the clauses true?**

---

## Example

Suppose you have variables $x$ and $y$, and clauses:

1. $(x \lor y)$
2. $(\lnot x \lor y)$
3. $(\lnot y \lor x)$

We need to find if we can assign True/False to $x$ and $y$ so that all 3 are satisfied.

 If we pick $x = \text{True}, y = \text{True}$:

* Clause 1: $(T \lor T) = T$
* Clause 2: $(F \lor T) = T$
* Clause 3: $(F \lor T) = T$

So all are satisfied → **YES**.



## Why is it interesting?

* General SAT is **NP-complete** (hard in general).
* But **2-SAT can be solved in polynomial time (linear in practice)** using graph algorithms.


## Implication Graph
- Suppose we have following example:
$$(a \lor \lnot b) \land (\lnot a \lor b) \land (\lnot a \lor \lnot b) \land (a \lor \lnot c)$$

- First we need to convert the problem to a different form, the so-called implicative normal form.
* A clause like $(a \lor b)$ means:

  * If $\lnot a$, then $b$ must be true. ($\lnot a \implies b$)
  * If $\lnot b$, then $a$ must be true. ($\lnot b \implies a$)

- We now construct a directed graph of these implications: for each variable $x$  there will be two vertices $v_x$ and $v_{\lnot x}$ . The edges will correspond to the implications.

- The edges:
$$\begin{array}{cccc}
\lnot a \Rightarrow \lnot b & a \Rightarrow b & a \Rightarrow \lnot b & \lnot a \Rightarrow \lnot c\\
b \Rightarrow a & \lnot b \Rightarrow \lnot a & b \Rightarrow \lnot a & c \Rightarrow a
\end{array}$$


⚡ Important property: if there’s an edge $a \to b$, then there’s also an edge $\lnot b \to \lnot a$. (That’s because the clause is symmetric.)


---

##  Unsatisfiability Criterion

Now the key idea:

If a variable $x$ and its negation $\lnot x$ are **both reachable from each other** in the implication graph, then they are in the same **strongly connected component (SCC)**.

That means:

* If you assume $x = \text{True}$, the graph forces $\lnot x = \text{True}$.
* If you assume $x = \text{False}$, the graph forces $x = \text{True}$.
  Either way, **contradiction**. 🚫

So:

$$
\text{2-SAT is satisfiable iff for every variable } x, \; x \text{ and } \lnot x \text{ are in different SCCs.}
$$

That’s the **necessary and sufficient condition**.

---

## Finding a Solution (if it exists)

Suppose no variable $x$ and $\lnot x$ are in the same SCC. Then the formula is satisfiable. But how do we actually assign values?

We use **topological order of the SCC condensation graph** (the DAG of SCCs).

* Think of SCCs as "super-nodes".
* Topologically sort them (i.e., if there’s an edge $A \to B$, then $A$ comes before $B$).

Now, for each variable $x$:

* If $\text{comp}[x] > \text{comp}[\lnot x]$ (meaning the SCC of $x$ comes **after** that of $\lnot x$), we assign:

  $$
  x = \text{True}
  $$
* Otherwise:

  $$
  x = \text{False}
  $$

---

## Why this assignment works (the proof idea)

- Let’s say we assign $x = \text{True}$.

- That means $\text{comp}[x]$ comes **after** $\text{comp}[\lnot x]$. So in the topological order, $\lnot x$ cannot reach $x$. This prevents contradictions like "$x \Rightarrow \lnot x$".

- Similarly, if some other variable $y$ had both $y$ and $\lnot y$ reachable from $x$, then by graph symmetry, we’d eventually get $x \Rightarrow \lnot x$, which we already ruled out.

So whichever assignment we pick from the rule above, it’s always **consistent and contradiction-free** .

---

