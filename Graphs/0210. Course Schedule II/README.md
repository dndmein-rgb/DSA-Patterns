# 0210. Course Schedule II

## 📋 Problem Description
**Difficulty**: Medium  
**Pattern**: Graph + Topological Sort (BFS)

You are given `numCourses` courses labeled from `0` to `numCourses - 1`.

Each prerequisite pair `[a, b]` means:
- You must complete course `b` before course `a`.

Return **any valid ordering** of courses that allows you to finish all courses.  
If no such ordering exists, return an empty array.

---

## 🛑 Constraints
- `1 <= numCourses <= 2000`
- `0 <= prerequisites.length <= 5000`
- `prerequisites[i].length == 2`
- All prerequisite pairs are unique

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
[0,1]
```

**Explanation**
Course `0` must be taken before course `1`.

---

### Example 2

**Input**
```
numCourses = 4
prerequisites = [[1,0],[2,0],[3,1],[3,2]]
```

**Output**
```
[0,1,2,3]
```

**Explanation**
Multiple valid orders exist. This is one of them.

---

### Example 3

**Input**
```
numCourses = 2
prerequisites = [[1,0],[0,1]]
```

**Output**
```
[]
```

**Explanation**
Cycle detected. No valid ordering exists.

---

## 🧠 Core Insight
This problem is a **topological sorting** problem on a **directed graph**.

- Courses → nodes
- Prerequisites → directed edges
- A valid ordering exists **only if the graph has no cycle**

---

## 💡 Approach (Kahn’s Algorithm)

1. Build adjacency list (`b → a`)
2. Compute indegree for each course
3. Push all courses with indegree `0` into a queue
4. Process the queue using BFS
5. Reduce indegrees and enqueue new `0` indegree nodes
6. If all courses are processed → valid order
7. Otherwise → cycle exists

---

## ⚙️ Complexity Analysis

| Metric | Complexity |
|------|-----------|
| Time | `O(V + E)` |
| Space | `O(V + E)` |

---

## ✅ Key Takeaways
- This is **cycle detection + ordering**
- BFS avoids recursion depth issues
- Queue can be replaced with min-heap for lexicographically smallest order
- If indegree never hits zero, something depends on itself
- Dependency problems fail for structural reasons, not bad luck
