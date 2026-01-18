# 778. Swim in Rising Water

**Difficulty:** Hard  
**LeetCode:** [Swim in Rising Water](https://leetcode.com/problems/swim-in-rising-water/)  
**Pattern:** Graph + Dijkstra / Minimax Path

---

## 📌 Problem Statement

You are given an `n x n` grid where `grid[i][j]` represents the elevation at cell `(i, j)`.

- At time `t`, you can enter a cell if `grid[i][j] ≤ t`
- You start at `(0,0)` and want to reach `(n-1,n-1)`
- Return the **minimum time** required to reach the destination

---

## 🧠 Core Insight

This is **not shortest path by sum**.  
This is **shortest path by maximum edge cost**.

The cost of a path =  
```
max(elevation along the path)
```

So the goal is to **minimize the maximum elevation encountered**.

That’s classic **Dijkstra with a modified relaxation rule**.

---

## 🛠️ Algorithm (Dijkstra – Minimax)

1. Each cell is a node
2. Moving to a neighbor has cost = `grid[neighbor]`
3. Path cost = `max(current_time, neighbor_height)`
4. Use a min-heap ordered by current path cost
5. Mark cells visited when popped from heap
6. First time you reach `(n-1,n-1)` → optimal answer

---

## 🧪 Dry Run

```
grid =
[
 [0, 2],
 [1, 3]
]
```

Steps:
- Start at (0,0), time = 0
- Move to (1,0): max(0,1) = 1
- Move to (0,1): max(0,2) = 2
- Best path reaches (1,1) with time = 3

Answer:
```
3
```

---

## ⏱️ Complexity

- **Time:** `O(n² log n²)` ≈ `O(n² log n)`
- **Space:** `O(n²)`

Efficient enough for constraints.

---

## ✅ Key Takeaways

- This is **Dijkstra**, not BFS
- Path cost is defined by `max`, not sum
- First arrival at destination is optimal
- Same logic applies to minimax / bottleneck path problems

If you see “minimize the maximum value on a path,” this pattern should fire instantly.
