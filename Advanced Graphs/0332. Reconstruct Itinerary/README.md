# 332. Reconstruct Itinerary

**Difficulty:** Medium  
**LeetCode:** [Reconstruct Itinerary](https://leetcode.com/problems/reconstruct-itinerary/)  
**Pattern:** Graph + Eulerian Path (Hierholzer’s Algorithm)

---

## 📌 Problem Statement

You are given airline tickets where  
`tickets[i] = [from, to]`.

- All tickets must be used **exactly once**
- The itinerary must start from `"JFK"`
- If multiple valid itineraries exist, return the **lexicographically smallest** one

---

## 🧠 Core Insight

This is **not a shortest path problem**.  
This is **not backtracking brute force** either unless you enjoy TLE.

This is an **Eulerian Path** problem in a directed graph:
- Every edge must be used exactly once
- Lexicographical order matters

So we use **Hierholzer’s Algorithm**, with a twist:
- Store outgoing edges in a **min-heap** to enforce lexicographical order

---

## 🛠️ Algorithm

1. Build adjacency list:
   ```
   from → min-heap(to)
   ```
2. Start DFS from `"JFK"`
3. While the current airport has outgoing edges:
   - Always take the smallest lexical destination
   - Remove the edge and recurse
4. Append airport to result **after** exhausting its edges
5. Reverse the result at the end

This post-order insertion is the key. Miss it and the solution collapses.

---

## 🧪 Dry Run

```
tickets = [
  ["JFK","SFO"],
  ["JFK","ATL"],
  ["SFO","ATL"],
  ["ATL","JFK"],
  ["ATL","SFO"]
]
```

Traversal order (simplified):
```
JFK → ATL → JFK → SFO → ATL → SFO
```

Result (after reverse):
```
["JFK","ATL","JFK","SFO","ATL","SFO"]
```

---

## ⏱️ Complexity

- **Time:** `O(E log E)`
  - Each edge pushed and popped once from a heap
- **Space:** `O(E + V)`

Efficient enough. No drama.

---

## ✅ Key Takeaways

- Using all edges exactly once → think Eulerian Path
- Lexicographical constraint → min-heap
- Post-order DFS is non-negotiable
- Reverse at the end or fail quietly

This pattern shows up whenever “use every ticket exactly once” appears. Memorize it.
