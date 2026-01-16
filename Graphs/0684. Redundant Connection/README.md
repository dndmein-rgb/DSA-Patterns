# 0684. Redundant Connection

## 📋 Problem Description
**Difficulty**: Medium  
**Pattern**: Graph + Cycle Detection  

You are given a graph that started as a tree with `n` nodes.
One extra edge was added, creating a cycle.

Return the edge that can be removed so that the resulting graph is a tree again.

If multiple answers exist, return the one that appears **last** in the input.

---

## 🛑 Constraints
- `3 <= edges.length <= 1000`
- Nodes are labeled from `1` to `n`
- Graph is undirected
- Exactly one extra edge exists

---

## 📌 Examples

### Example 1
**Input**
```
edges = [[1,2],[1,3],[2,3]]
```

**Output**
```
[2,3]
```

---

### Example 2
**Input**
```
edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
```

**Output**
```
[1,4]
```

---

## 🧠 Core Insight
A tree:
- Is connected
- Has no cycles

Adding an edge that connects two **already connected nodes** creates a cycle.
That edge is redundant.

---

## 💡 Approach Used (DFS Path Check)

1. Start with an empty graph
2. Process edges one by one
3. Before adding an edge `(u, v)`:
   - Check if a path already exists from `u` to `v`
4. If yes → this edge creates a cycle → return it
5. Otherwise, add the edge to the graph

---

## 🔁 Alternative Approaches

### 1. Union-Find (Disjoint Set) — Preferred
**Steps**
- Initialize parent array
- For each edge:
  - If both nodes have same root → redundant edge
  - Otherwise union them

**Pros**
- Much faster
- No DFS per edge

**Cons**
- Slightly more setup

---

### 2. DFS / BFS (Current Approach)
**Pros**
- Very intuitive
- Easy to reason about

**Cons**
- Time complexity is higher (`O(N²)` worst case)
- Repeated DFS calls

---

## ⚙️ Complexity Analysis

| Approach | Time | Space |
|--------|------|-------|
| DFS (this) | `O(N²)` | `O(N)` |
| Union-Find | `O(N α(N))` | `O(N)` |

---

## ✅ Notes
- DFS checks connectivity before edge insertion
- Fresh `visited` array avoids stale state
- Works because only one extra edge exists
- Union-Find is the go-to in interviews, but this is logically solid
