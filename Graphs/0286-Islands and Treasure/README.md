# 0286. Islands and Treasure (Walls and Gates)

## 📋 Problem Description
**Difficulty**: Medium  
**Pattern**: Multi-Source BFS / Grid Shortest Distance  

You are given an `m x n` grid with three types of cells:

- `-1` → Water (blocked)
- `0` → Treasure chest
- `INF` (`2147483647`) → Land cell

Fill each land cell with the distance to its **nearest treasure chest**.
If a land cell cannot reach any treasure, it must remain `INF`.

Movement is allowed **only in 4 directions**:
- Up
- Down
- Left
- Right

The grid must be modified **in-place**.

---

## 🛑 Constraints
- `1 <= m, n <= 100`
- `grid[i][j] ∈ {-1, 0, 2147483647}`

---

## 🧠 Key Insight
This is **not** a DFS problem.

You want **shortest distance**, which means:
- BFS
- From **all treasures at once**

Running BFS separately from each land cell would be slow and pointless.

---

## 💡 Approach: Multi-Source BFS

### Why BFS?
- Grid edges are unweighted
- BFS guarantees shortest path
- Multiple starting points (treasures)

### Algorithm
1. Push all treasure cells (`0`) into the queue
2. Perform BFS level-by-level
3. For each land cell (`INF`), update distance as:
