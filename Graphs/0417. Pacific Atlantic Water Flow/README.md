# 0417. Pacific Atlantic Water Flow

## 📋 Problem Description
**Difficulty**: Medium  
**Pattern**: Multi-Source BFS / Reverse Flow  

You are given an `m x n` matrix of heights representing a continent.
Water can flow from a cell to another if the destination cell has **height ≤ current cell**.

There are two oceans:
- **Pacific Ocean**: touches the top and left borders
- **Atlantic Ocean**: touches the bottom and right borders

Return all coordinates where water can flow to **both oceans**.

---

## 🛑 Constraints
- `1 <= m, n <= 200`
- `0 <= heights[i][j] <= 10^5`

---

## 📌 Examples

### Example 1

**Input**
```
[
 [1,2,2,3,5],
 [3,2,3,4,4],
 [2,4,5,3,1],
 [6,7,1,4,5],
 [5,1,1,2,4]
]
```

**Output**
```
[[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
```

---

### Example 2

**Input**
```
[[1]]
```

**Output**
```
[[0,0]]
```

---

## 🧠 Key Insight
Instead of flowing **from cells to oceans**, reverse the logic:

- Start BFS **from the oceans**
- Move inward to cells that are **higher or equal**
- A cell reachable from both BFS runs is the answer

---

## 💡 Approach: Reverse Multi-Source BFS

### Steps
1. Run BFS from all Pacific-border cells
2. Run BFS from all Atlantic-border cells
3. Only move to cells with height ≥ current
4. Mark reachable cells for each ocean
5. Take the intersection of both visited matrices

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
| Time | `O(m × n)` | Each cell visited at most twice |
| Space | `O(m × n)` | Visited matrices + BFS queues |

---

## ✅ Key Takeaways
- Reverse thinking simplifies the problem
- BFS guarantees correct reachability
- DFS also works but BFS is safer for depth
- Two oceans = two BFS passes
