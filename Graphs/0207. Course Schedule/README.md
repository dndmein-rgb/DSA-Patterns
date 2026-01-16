# 0207. Course Schedule

## 📋 Problem Description
**Difficulty**: Medium  
**Pattern**: Graph + Topological Sort (Kahn’s Algorithm)

You are given `numCourses` courses labeled from `0` to `numCourses - 1`.

Each prerequisite pair `[a, b]` means:
- To take course `a`, you must first take course `b`.

Return `true` if you can finish **all courses**, otherwise return `false`.

---

## 🛑 Constraints
- `1 <= numCourses <= 2000`
- `0 <= prerequisites.length <= 5000`
- `prerequisites[i].length == 2`
- No duplicate prerequisite pairs

---

## 📌 Examples

### Example 1

**Input**
```
numCourses = 2
prerequisites = [[1,0]]
```

**Output**
```
true
```

**Explanation**
Course `0` → Course `1`  
No cycle exists.

---

### Example 2

**Input**
```
numCourses = 2
prerequisites = [[1,0],[0,1]]
```

**Output**
```
false
```

**Explanation**
Cycle detected: `0 → 1 → 0`  
You’re stuck forever.

---

## 🧠 Core Insight
This is **cycle detection in a directed graph**.

- If a cycle exists → impossible to finish
- If no cycle → all courses can be completed

Topological sorting exposes cycles cleanly.

---

## 💡 Approach (Kahn’s Algorithm)

1. Build adjacency list
2. Compute indegree of every node
3. Push all nodes with indegree `0` into queue
4. Remove nodes one by one, reducing indegrees
5. Count how many nodes are processed
6. If processed count == total courses → no cycle

---

## ⚙️ Complexity Analysis

| Metric | Complexity |
|------|-----------|
| Time | `O(V + E)` |
| Space | `O(V + E)` |

---

## ✅ Key Takeaways
- Courses = nodes
- Prerequisites = directed edges
- Indegree never reaching zero = cycle
- BFS beats DFS here when you want clarity
- If planning fails, it’s probably circular dependency, not fate
