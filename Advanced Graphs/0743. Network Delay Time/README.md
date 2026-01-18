# 743. Network Delay Time

**Difficulty:** Medium  
**LeetCode:** [Network Delay Time](https://leetcode.com/problems/network-delay-time/)  
**Pattern:** Graph + Dijkstra (Single Source Shortest Path)

---

## 📌 Problem Statement

You are given a directed weighted graph with `n` nodes labeled `1` to `n`.

- `times[i] = [u, v, w]` means a signal takes `w` time to travel from `u` to `v`
- A signal is sent from node `k`
- Return the **minimum time** for all nodes to receive the signal
- If any node is unreachable, return `-1`

---

## 🧠 Why This Works

- Graph is weighted → BFS is invalid
- We need shortest paths from a single source
- All weights are non-negative

This is exactly what **Dijkstra** is built for.

---

## 🛠️ Algorithm

1. Build adjacency list `u → (v, w)`
2. Initialize all distances as infinity
3. Use a min-heap to always expand the closest node
4. Relax edges
5. Ignore outdated heap states
6. Answer = max distance among all nodes

---

## 🧪 Dry Run

```
times = [[2,1,1],[2,3,1],[3,4,1]]
n = 4, k = 2
```

Final distances:
```
1 → 1
2 → 0
3 → 1
4 → 2
```

Answer = `2`

---

## ⏱️ Complexity

- **Time:** `O((V + E) log V)`
- **Space:** `O(V + E)`

Works comfortably for large constraints.

---

## ✅ Takeaways

- Weighted graph → Dijkstra, no shortcuts
- Min-heap is mandatory
- Skipping stale states prevents TLE
- This filename + structure should now be consistent

End of story.
