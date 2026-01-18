# 778. Swim in Rising Water

## 📋 Problem Description
**Difficulty:** Hard  
**LeetCode Link:** [Swim in Rising Water](https://leetcode.com/problems/swim-in-rising-water/)  
**Pattern:** Minimax Path  
- Graph + Dijkstra  
- Binary Search + DFS

You are given an `n x n` grid where `grid[i][j]` represents the elevation at cell `(i, j)`.

- At time `t`, you may enter any cell with elevation `≤ t`
- You start at `(0, 0)` and must reach `(n-1, n-1)`
- Movement is allowed in 4 directions
- Return the **minimum time** required to reach the destination

---

## 🧪 Examples

### Example 1
**Input**
```
grid = [[0,2],[1,3]]
```

**Output**
```
3
```

**Explanation**  
The path must pass through elevation `3`, so the minimum required time is `3`.

---

### Example 2
**Input**
```
grid =
[[0,1,2,3,4],
 [24,23,22,21,5],
 [12,13,14,15,16],
 [11,17,18,19,20],
 [10,9,8,7,6]]
```

**Output**
```
16
```

---

## 📏 Constraints
- `n == grid.length`
- `1 ≤ n ≤ 50`
- `0 ≤ grid[i][j] < n²`
- All values are unique

---

## 🧠 Core Insight

This is **not** a shortest-path-by-sum problem.

The cost of a path is defined as:
```
max(elevation along the path)
```

Goal:
```
Minimize the maximum elevation encountered
```

This allows **two valid approaches**:

1. Dijkstra (minimax path)
2. Binary Search on time + DFS feasibility check

---

## 🛠️ Approach 1: Dijkstra (Minimax Path)

### Idea
- Treat each cell as a node
- Moving to a neighbor has cost = `grid[neighbor]`
- Path cost = `max(current_cost, neighbor_height)`
- Always expand the path with the **lowest maximum elevation so far**

This is classic **Dijkstra with a modified relaxation rule**.

### Steps
1. Push `(grid[0][0], 0, 0)` into a min-heap
2. Pop the cell with the smallest current max elevation
3. For each neighbor:
   ```
   nextCost = max(currentCost, grid[neighbor])
   ```
4. First time `(n-1, n-1)` is popped → answer

### Complexity
- **Time:** `O(n² log n)`
- **Space:** `O(n²)`

---

## 🛠️ Approach 2: Binary Search + DFS (Your Solution)

### Idea
The answer lies between:
```
grid[0][0] and n² - 1
```

Binary search on time `t`.

For each `t`, check:
> Is there a path from `(0,0)` to `(n-1,n-1)` using only cells with `grid[i][j] ≤ t`?

This becomes a **DFS reachability problem**.

---

### DFS Feasibility Check
For a given `t`:
- Block all cells with elevation `> t`
- Run DFS from `(0,0)`
- If destination is reachable → `t` is feasible

---

### Binary Search Steps
1. `low = grid[0][0]`, `high = n² - 1`
2. While `low ≤ high`:
   - `mid = (low + high) / 2`
   - If DFS can reach destination:
     - store answer
     - search left
   - Else:
     - search right
3. Return the smallest feasible `t`

---

### Why This Works
- Reachability is **monotonic**
- If you can reach at time `t`, you can reach at all `t' > t`
- That makes binary search valid

---

### Complexity
- **Time:** `O(n² log n²)` ≈ `O(n² log n)`
- **Space:** `O(n²)` (DFS visited array)

---

## ⚖️ Comparison

| Method | Pros | Cons |
|------|-----|-----|
| Dijkstra | One pass, elegant | Harder to intuit |
| Binary + DFS | Very intuitive | Extra log factor |

Both are **fully correct**.

---

## ❌ Common Mistakes
- Treating this as BFS
- Minimizing sum instead of max
- Marking visited too early in Dijkstra
- Forgetting monotonicity in binary search
- Using DFS without resetting `visited`

---

## 📁 Folder Structure
```
0778-swim-in-rising-water/
├── 0778-swim-in-rising-water.cpp
└── README.md
```

---

## 🎯 Final Takeaway

This problem is about **minimizing the worst step**, not the total cost.

If you see:
> “minimum time such that a path exists”

Think:
- **Binary Search + Reachability**
- or **Dijkstra with max-based relaxation**

Same truth. Different tools.
