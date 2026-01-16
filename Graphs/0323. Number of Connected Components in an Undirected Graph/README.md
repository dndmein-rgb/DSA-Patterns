# 0323. Number of Connected Components in an Undirected Graph

## 📋 Problem Description
**Difficulty**: Medium  
**Pattern**: Graph + DFS  

You are given `n` nodes labeled from `0` to `n - 1` and a list of undirected edges.

Return the **number of connected components** in the graph.

---

## 🛑 Constraints
- `1 <= n <= 2000`
- `0 <= edges.length <= 5000`
- No duplicate edges
- No self-loops

---

## 📌 Examples

### Example 1
**Input**
```
n = 5
edges = [[0,1],[1,2],[3,4]]
```

**Output**
```
2
```

---

### Example 2
**Input**
```
n = 5
edges = [[0,1],[1,2],[2,3],[3,4]]
```

**Output**
```
1
```

---

## 🧠 Core Insight
A **connected component** is a group of nodes where each node is reachable from any other node in the group.

The problem reduces to:
- Count how many times you must start a DFS to visit all nodes

Each DFS traversal covers exactly **one component**.

---

## 💡 Approach Used (DFS)

1. Build adjacency list
2. Maintain a visited array
3. Loop through all nodes
4. If a node is unvisited:
   - Increment component count
   - Run DFS to mark the entire component

---

## 🔁 Alternative Approaches

### 1. BFS
- Same logic as DFS
- Use a queue instead of recursion
- Safer for deep graphs

---

### 2. Union-Find (Disjoint Set)
**Steps**
- Initialize `parent[i] = i`
- Union endpoints of each edge
- Count unique parents

**Pros**
- Very efficient
- No recursion

**Cons**
- Less intuitive
- Extra structure needed

---

## ⚙️ Complexity Analysis

| Metric | Complexity |
|------|-----------|
| Time | `O(N + E)` |
| Space | `O(N + E)` |

---

## ✅ Notes
- Each DFS call corresponds to one component
- Works for disconnected graphs
- Handles isolated nodes naturally
- Union-Find is preferred when edges stream dynamically
