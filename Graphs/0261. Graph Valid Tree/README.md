# 0261. Graph Valid Tree

## 📋 Problem Description

**Difficulty**: Medium  
**LeetCode Link**: [Graph Valid Tree](https://neetcode.io/problems/valid-tree/question?list=neetcode150)  
**Pattern**: Graph + DFS


You are given `n` nodes labeled from `0` to `n - 1` and a list of undirected edges.

Return `true` if the edges form a **valid tree**, otherwise return `false`.

A valid tree must satisfy:
1. It is fully connected
2. It has no cycles

---

## 🛑 Constraints
- `1 <= n <= 2000`
- `0 <= edges.length <= 5000`
- No self-loops
- No duplicate edges

---

## 📌 Examples

### Example 1
**Input**
```
n = 5
edges = [[0,1],[0,2],[0,3],[1,4]]
```

**Output**
```
true
```

---

### Example 2
**Input**
```
n = 5
edges = [[0,1],[1,2],[2,3],[1,3],[1,4]]
```

**Output**
```
false
```

**Explanation**
Cycle exists.

---

## 🧠 Core Conditions for a Valid Tree

An undirected graph is a tree **if and only if**:
1. It has exactly `n - 1` edges
2. It is connected
3. It has no cycles

Your solution checks **all three**.

---

## 💡 Approach Used (DFS)

1. Check edge count (`n - 1`)
2. Build adjacency list
3. Run DFS to detect cycles
4. Ensure all nodes are visited (connectivity)

Cycle detection works by:
- Tracking parent node
- Revisiting a non-parent visited node ⇒ cycle

---

## 🔁 Alternative Approaches

### 1. Union-Find (Disjoint Set)
**Steps**
- Initialize parent array
- For each edge:
  - If both nodes have same parent → cycle
  - Otherwise union them
- Ensure exactly `n - 1` edges

**Pros**
- Very fast
- No recursion

**Cons**
- Less intuitive
- Doesn’t explicitly show connectivity traversal

---

### 2. BFS-Based Cycle Detection
- Similar to DFS
- Use queue and parent tracking
- Slightly more verbose, same complexity

---

## ⚙️ Complexity Analysis

| Metric | Complexity |
|------|-----------|
| Time | `O(N + E)` |
| Space | `O(N + E)` |

---

## ✅ Notes
- Edge count check is a powerful early exit
- DFS ensures both cycle detection and connectivity
- Parent tracking is mandatory in undirected graphs
- If even one node is unreachable → not a tree
