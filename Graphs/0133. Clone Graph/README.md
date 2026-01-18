# 133. Clone Graph

## 📋 Problem Description
**Difficulty**: Medium  
**LeetCode Link**: [Clone Graph](https://leetcode.com/problems/clone-graph/)  
**Pattern**: Graph DFS / Hash Map  

You are given a reference to a node in a **connected undirected graph**.  
Each node contains a value (`val`) and a list of its neighbors.

Your task is to return a **deep copy (clone)** of the entire graph.

A deep copy means:
- Every node is newly created
- No original node references are reused

---

## 🛑 Constraints
- The number of nodes in the graph is in the range `[0, 100]`
- `1 <= Node.val <= 100`
- Node values are unique
- The graph is undirected and connected

---

## 🧠 Key Insight
Graphs can contain **cycles**.  
If you blindly DFS without tracking visited nodes, you’ll recurse forever and deserve what happens next.

So:
- Use a hash map to remember already-cloned nodes
- Original node → Cloned node mapping prevents duplication and infinite loops

---

## 💡 Approach: DFS + Hash Map

### 1. Use DFS to Traverse
- Start from the given node
- Recursively visit all neighbors

### 2. Clone on First Visit
- If a node hasn’t been cloned:
  - Create a new node with the same value
  - Store it in a map: `original → clone`

### 3. Reuse Existing Clones
- If the node is already in the map:
  - Return the cloned version immediately

This guarantees:
- Each node is cloned exactly once
- Cycles are handled safely

---

## 🔁 Algorithm Steps
1. If the input node is `NULL`, return `NULL`
2. If node is already cloned, return it from the map
3. Create a clone of the node
4. Recursively clone all neighbors
5. Attach cloned neighbors to the cloned node
6. Return the cloned node

---

## ⚙️ Complexity Analysis

| Metric | Complexity | Explanation |
|------|-----------|-------------|
| Time | `O(V + E)` | Each node and edge visited once |
| Space | `O(V)` | Hash map + recursion stack |

---

## ✅ Key Takeaways
- This is **not** a tree problem, stop treating it like one
- Hash map is mandatory because of cycles
- DFS and BFS both work; DFS is simpler here
- Deep copy means zero shared memory with original graph
