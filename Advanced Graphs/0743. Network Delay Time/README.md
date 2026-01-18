# 743. Network Delay Time

## 📋 Problem Description
**Difficulty:** Medium  
**LeetCode Link:** [Network Delay Time](https://leetcode.com/problems/network-delay-time/)  
**Pattern:** Graph + Dijkstra (Single Source Shortest Path)

You are given a **directed weighted graph** with `n` nodes labeled from `1` to `n`.

- `times[i] = [u, v, w]` means it takes `w` units of time for a signal to travel from node `u` to node `v`
- A signal starts from node `k`
- Return the **minimum time** it takes for **all nodes** to receive the signal
- If any node cannot be reached, return `-1`

---

## 🧪 Examples

### Example 1
**Input**
times = [[2,1,1],[2,3,1],[3,4,1]]
n = 4
k = 2


**Output**
2


**Explanation**  
The signal reaches:
- Node 2 at time 0
- Node 1 at time 1
- Node 3 at time 1
- Node 4 at time 2  

Maximum time = `2`

---

### Example 2
**Input**
times = [[1,2,1]]
n = 2
k = 1


**Output**
1


---

### Example 3
**Input**
times = [[1,2,1]]
n = 2
k = 2


**Output**
-1


**Explanation**  
Node `1` is unreachable from node `2`.

---

## 📏 Constraints
- `1 ≤ n ≤ 100`
- `1 ≤ times.length ≤ 6000`
- `1 ≤ u, v ≤ n`
- `0 ≤ w ≤ 100`
- All edge weights are **non-negative**

---

## 🧠 Approach (Dijkstra’s Algorithm)

This is a **single-source shortest path** problem on a **weighted directed graph**.

### Why Dijkstra
- BFS fails because weights are not uniform
- All weights are non-negative
- We need shortest distances from one source

### Step-by-Step

1. Build an adjacency list:  
   `u → (v, weight)`
2. Initialize a distance array with infinity
3. Set `dist[k] = 0`
4. Use a **min-heap (priority queue)** to always expand the closest node
5. Relax all outgoing edges
6. Skip outdated heap states to avoid redundant work
7. If any node is unreachable, return `-1`
8. Otherwise, return the maximum distance in the array

This guarantees the correct minimum time for all nodes.

---

## ⏱️ Complexity Analysis
- **Time:** `O((V + E) log V)`
- **Space:** `O(V + E)`

---

## ❌ Common Mistakes
- Using BFS instead of Dijkstra
- Forgetting to skip stale priority queue entries
- Returning the last popped value instead of the max distance
- Assuming all nodes are reachable

---

## 📁 Folder Structure
743-network-delay-time/
├── 743-network-delay-time.cpp
└── README.md

---

## 🎯 Key Takeaway
Weighted graph + single source + shortest path  
→ **Dijkstra is mandatory.**  
Anything else is just wrong logic.
