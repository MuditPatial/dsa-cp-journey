# Alien Dictionary (Topological Sort)

We are given a list of words sorted according to an unknown (alien) language.
Our task is to determine the **order of characters** used in that language.
If no valid ordering exists, we return an empty string.

---

## Core Idea (in simple terms)

The character order is **hidden in the differences between adjacent words**.

Example:
["abc", "abd"]

Here, `'c'` comes before `'d'` because that is the first position where the
two words differ.

So instead of comparing all words, we only compare **adjacent pairs**.

---

## Step 1: Collect all unique characters

We first collect every character that appears in the dictionary.

Why?
- Even characters with no ordering constraints must appear in the final answer.

Example:
["baa", "abcd"] → {b, a, c, d}


---

## Step 2: Map characters to indices

Since characters are not numeric, we map them to integers:

'a' → 0, 'b' → 1, 'c' → 2, ...


This allows us to represent the problem as a **graph**.

---

## Step 3: Build the dependency graph

For each adjacent word pair:
words[i] and words[i+1]


We compare them character by character:
- The **first mismatch** gives a rule:
a[j] → b[j]

Meaning character `a[j]` must come before `b[j]`.

# Important edge case:
If one word is a prefix of the other but appears later:
"abcd", "ab"

This is invalid → return empty string.

---

## Step 4: Topological Sort (Kahn’s Algorithm)

Once the graph is built:
- Compute indegree of each character
- Push all characters with indegree `0` into a queue
- Repeatedly:
  - Remove a character from the queue
  - Add it to the answer
  - Reduce indegree of its neighbors
  - Push new zero-indegree characters

This ensures the final order respects all constraints.

---

## Step 5: Validate result

If the number of characters in the result is **less than total unique characters**,
a cycle exists → no valid ordering → return empty string.

---

## Why this approach works

- The dictionary is already sorted
- Adjacent words reveal direct ordering constraints
- Topological sorting produces a valid linear order if possible

---

## Time & Space Complexity

- **Time Complexity:** `O(N × L + K)`
  - `N` = number of words
  - `L` = average word length
  - `K` = number of unique characters

- **Space Complexity:** `O(K + E)`
  - Graph + indegree array

---

## Key Takeaways

- Compare **only adjacent words**
- Use **first mismatching character**
- Handle prefix edge case carefully
- This is a classic **graph + topological sort** problem

---

## When to use this pattern

Use this approach when:
- Order is implicit
- Dependencies are between symbols/characters
- Input is already sorted by unknown rules
