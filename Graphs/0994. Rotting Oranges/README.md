# 0994. Rotting Oranges

## 📋 Problem Description
**Difficulty**: Medium  
**LeetCode Link**: [Rotting Oranges](https://leetcode.com/problems/rotting-oranges/)  
**Pattern**: Multi-Source BFS / Grid Level Traversal

You are given an `m x n` grid where:
- `0` → Empty cell
- `1` → Fresh orange
- `2` → Rotten orange

Every minute, a rotten orange rots all **4-directionally adjacent** fresh oranges.

Return the **minimum number of minutes** needed so that no fresh orange remains.  
If this is impossible, return `-1`.

---

## 🛑 Constraints
- `1 <= m, n <= 10`
- `grid[i][j] ∈ {0, 1, 2}`

---

## 📌 Examples

### Example 1

**Input**
```
[
  [2,1,1],
  [1,1,0],
  [0,1,1]
]
```

**Output**
```
4
```

---

### Example 2

**Input**
```
[
  [2,1,1],
  [0,1,1],
  [1,0,1]
]
```

**Output**
```
-1
```

---

### Example 3

**Input**
```
[
  [0,2]
]
```

**Output**
```
0
```

---

## 💡 Approach: Multi-Source BFS

- Each rotten orange is a BFS source
- Each BFS level represents one minute
- Fresh oranges rot as BFS expands

### Algorithm
1. Count all non-empty cells
2. Push all rotten oranges into a queue
3. Perform BFS level-by-level
4. Convert fresh oranges to rotten
5. Track elapsed minutes
6. If all oranges rot, return minutes; else return `-1`

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
- This is a classic **multi-source BFS**
- Each BFS layer corresponds to one minute
- DFS does not guarantee minimum time
- In-place updates avoid extra memory
