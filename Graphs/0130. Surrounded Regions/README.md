# 0130. Surrounded Regions

## 📋 Problem Description
**Difficulty**: Medium  
**LeetCode**: [Surrounded Regions](https://leetcode.com/problems/surrounded-regions/)  
**Pattern**: BFS / Boundary Flood Fill  

You are given an `m x n` board containing `'X'` and `'O'`.

Capture all regions surrounded by `'X'` by flipping all `'O'`s into `'X'`s **in-place**.

A region is captured if:
- It is completely surrounded by `'X'`
- It is **not connected to the boundary**

---

## 🛑 Constraints
- `1 <= m, n <= 200`
- `board[i][j] ∈ {'X', 'O'}`

---

## 📌 Examples

### Example 1

**Input**
```
[
 ["X","X","X","X"],
 ["X","O","O","X"],
 ["X","X","O","X"],
 ["X","O","X","X"]
]
```

**Output**
```
[
 ["X","X","X","X"],
 ["X","X","X","X"],
 ["X","X","X","X"],
 ["X","O","X","X"]
]
```

---

### Example 2

**Input**
```
[
 ["X"]
]
```

**Output**
```
[
 ["X"]
]
```

---

## 🧠 Key Insight
Only `'O'` regions **connected to the boundary** survive.

So instead of finding surrounded regions:
- Find **non-surrounded** ones
- Protect them
- Flip the rest

---

## 💡 Approach: Boundary BFS

### Steps
1. Traverse the boundary
2. Start BFS from every boundary `'O'`
3. Mark all reachable `'O'`s as safe (`'#'`)
4. Flip remaining `'O'` → `'X'`
5. Convert `'#'` back to `'O'`

---

## 🧭 Direction Handling
```
Up    (-1, 0)
Down  (+1, 0)
Left  (0, -1)
Right (0, +1)
```

---

## ⚙️ Complexity Analysis

| Metric | Complexity | Explanation |
|------|-----------|-------------|
| Time | `O(m × n)` | Each cell visited once |
| Space | `O(m × n)` | Queue in worst case |

---

## ✅ Key Takeaways
- Boundary-connected regions are immune
- BFS avoids recursion depth issues
- Marking first, flipping later simplifies logic
- Classic grid flood-fill problem
