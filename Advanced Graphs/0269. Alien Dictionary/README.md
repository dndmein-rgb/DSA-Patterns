# 269. Alien Dictionary

**Difficulty:** Hard  
**LeetCode:** [Alien Dictionary](https://neetcode.io/problems/foreign-dictionary/question?list=neetcode150/)  
**Pattern:** Graph + Topological Sort (Kahn’s Algorithm)

---

## 📌 Problem Statement

You are given a list of words sorted lexicographically according to an **unknown alien language**.

Your task is to:
- Derive the order of characters in the alien alphabet
- Return **any valid order**
- Return an empty string if the ordering is invalid

---

## 🧠 Core Insight

This is **not string sorting**.  
This is **dependency extraction**.

From two adjacent words:
- The **first differing character** defines a precedence rule  
  ```
  w1[j] → w2[j]
  ```

Collect all such rules and perform a **topological sort**.

If a cycle exists, the dictionary is invalid.

---

## ❗ Critical Edge Case (Prefix Trap)

```
["abc", "ab"]
```

Invalid.

Why?
- `ab` cannot come after `abc` if `ab` is a prefix
- This violates lexicographical ordering rules

You handled this correctly. Miss this and the solution is wrong.

---

## 🛠️ Algorithm

1. Initialize indegree for **all unique characters**
2. Compare adjacent words to build graph edges
3. Detect invalid prefix case early
4. Perform **Kahn’s Algorithm**:
   - Push nodes with indegree `0`
   - Reduce indegrees as edges are removed
5. If all characters are processed → valid order
6. Otherwise → cycle → return empty string

---

## 🧪 Dry Run

```
words = ["wrt","wrf","er","ett","rftt"]
```

Edges:
```
w → e
e → r
r → t
t → f
```

Topological order:
```
"wertf"
```

---

## ⏱️ Complexity

- **Time:** `O(V + E)`
- **Space:** `O(V + E)`

Where:
- `V` = unique characters
- `E` = precedence rules

Efficient and clean.

---

## ✅ Key Takeaways

- Adjacent word comparison is the only valid signal
- Prefix case is a silent killer
- This is a DAG problem, not string magic
- Kahn’s Algorithm is the safest choice here

If you see “unknown alphabet order,” your brain should jump straight to **topological sort** without hesitation.
