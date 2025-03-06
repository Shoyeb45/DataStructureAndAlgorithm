# Sparse Table

- It is data structure for computing minimum of an interval of an array in $O(1)$ time.
- It is 2D data structure 
- `table[i][j]` -> answer to query = [i, i + $2^j$ - 1], where $i + 2^j - 1 <= N$
- Means the length must be power of 2

- We'll use Dynammic programming to build the table
- $dp_{i, j}$ -> Information starting at index $i$, of length $2^{j- 1}$.
- So we can say that :
$$dp_{i, j} = dp_{i, j - 1} + dp_{i + 2^j, j - 1}$$
Base case : 
$$dp_{i, 0} = arr[i]$$
