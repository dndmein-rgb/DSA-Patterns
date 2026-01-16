# 0210. Course Schedule II

## 📋 Problem Description
**Difficulty**: Medium  
**Pattern**: Graph + Topological Sort  

You are given `numCourses` courses labeled from `0` to `numCourses - 1`.

Each prerequisite pair `[a, b]` means:
- You must complete course `b` before course `a`.

Return **any valid ordering** of courses that allows you to finish all courses.  
If it is impossible, return an empty array.

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

---

## 🧠 Core Idea
This problem is about **topological sorting** in a **directed graph**.

- Courses → nodes
- Prerequisites → directed edges
- A valid ordering exists **only if the graph has no cycle**

Your solution uses **Kahn’s Algorithm (BFS-based topological sort)**.

---

## 💡 Approach Used (BFS / Kahn’s Algorithm)

1. Build adjacency list (`b → a`)
2. Maintain indegree count for each course
3. Push all courses with indegree `0` into a queue
4. Process nodes one by one using BFS
5. Reduce indegrees of neighbors
6. If all courses are processed → valid order
7. Otherwise → cycle exists

---

## 🔁 Alternative Approaches

### 1. DFS-based Topological Sort
- Use recursion and a state array:
  - `0 = unvisited`
  - `1 = visiting`
  - `2 = visited`
- Detect cycle if you revisit a `visiting` node

**Pros**
- Simple conceptually
- Good for cycle detection

**Cons**
- Risk of stack overflow
- Harder to debug
- Less intuitive ordering

---

### 2. Lexicographically Smallest Order
If the problem required the **smallest possible order**:
- Replace `queue` with a **min-heap (priority_queue)**
- Everything else remains the same

---

## ⚙️ Complexity Analysis

| Metric | Complexity |
|------|-----------|
| Time | `O(V + E)` |
| Space | `O(V + E)` |

---

## ✅ Notes
- Your implementation is optimal and correct
- BFS is preferred over DFS here for safety
- Cycle detection is implicit via indegree exhaustion
- Empty result means dependency loop, not bad input
