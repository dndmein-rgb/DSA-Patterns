# 1584. Min Cost to Connect All Points

**Difficulty:** Medium  
**LeetCode:** [Min Cost to Connect All Points](https://leetcode.com/problems/min-cost-to-connect-all-points/)  
**Pattern:** Graph + Minimum Spanning Tree (Prim’s Algorithm)

---

## 📌 Problem Statement

You are given `n` points in a 2D plane.

- Cost to connect two points = Manhattan distance  
  `|x1 - x2| + |y1 - y2|`
- Connect all points such that the **total cost is minimum**
- All points must be connected (directly or indirectly)

---

## 🧠 Core Idea

This is a **Minimum Spanning Tree** problem.

- Each point = vertex
- Edge weight = Manhattan distance
- Graph is **complete** (every point connects to every other)

Finding the MST guarantees:
- All points connected
- Minimum total cost

We use **Prim’s Algorithm**.

---

## 🛠️ Algorithm (Prim’s)

1. Build a graph where:
   - Each point is a node
   - Edge weight = Manhattan distance
2. Start from any node (0)
3. Use a min-heap to always pick the smallest edge
4. Add the node if it’s not already in the MST
5. Repeat until all nodes are included

---

## 🧪 Dry Run (Small Example)

```
points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
```

Edges are weighted by Manhattan distance.  
Prim’s gradually picks the cheapest edge that expands the MST.

Final MST cost:
```
20
```

---

## ⏱️ Complexity

- **Time:** `O(V^2 log V)`
  - Complete graph construction dominates
- **Space:** `O(V^2)`
  - Adjacency list stores all edges

This passes constraints comfortably.

---

## ✅ Key Takeaways

- “Connect all nodes with minimum cost” → MST
- Manhattan distance doesn’t change the MST logic
- Prim’s works well when starting from a single node
- Using a min-heap is mandatory

This is MST 101. If you see “connect all points cheaply,” your brain should jump here instantly.
