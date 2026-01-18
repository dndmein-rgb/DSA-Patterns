# 🧠 Graph Algorithms Hierarchy: From BFS Constraints to Global Optimization

This roadmap represents the mental progression required to solve **graph problems deliberately** instead of pattern-guessing.

Graphs are not about “using BFS or DFS”.  
They are about **what property the problem is asking you to preserve**: distance, order, feasibility, or global cost.

---

## 🧱 Level 1: BFS with Constraints (Traversal is not enough)

**The Focus:**  
BFS works only when the problem allows it.  
Here, constraints twist BFS just enough to punish shallow understanding.

* [0787. Cheapest Flights Within K Stops](./0787-Cheapest-Flights-Within-K-Stops)  
  BFS with levels. The stop limit breaks classic shortest-path logic.
  Learn why plain BFS and plain Dijkstra both fail without modification.

---

## 🧭 Level 2: Shortest Path – Dijkstra Proper (Weighted Graph Reality)

**The Focus:**  
Once edges have weights, BFS lies.  
You must respect accumulated cost and prune stale states.

* [0743. Network Delay Time](./0743-Network-Delay-Time)  
  Canonical Dijkstra. Single-source shortest path with no tricks.
  If this feels hard, your fundamentals are weak.

* [0778. Swim in Rising Water](./0778-Swim-in-Rising-Water)  
  Dijkstra with a **minimax cost function**.
  Path cost is the maximum edge, not the sum.
  Same algorithm, different mental model.

---

## 🧠 Level 3: Structural Graph Problems (Order > Distance)

**The Focus:**  
Graphs are not always about cost.
Sometimes the output is **structure**.

* [0269. Alien Dictionary](./0269-Alien-Dictionary)  
  Build dependencies from word order.
  Topological sort with a brutal prefix edge case.

* [0332. Reconstruct Itinerary](./0332-Reconstruct-Itinerary)  
  Eulerian path with lexicographical constraints.
  Post-order DFS (Hierholzer) or guaranteed failure.

---

## 🌉 Level 4: Global Optimization (Minimum Spanning Tree)

**The Focus:**  
This is not shortest path.
This is **global connectivity at minimum cost**.

* [1584. Min Cost to Connect All Points](./1584-Min-Cost-to-Connect-All-Points)  
  Minimum Spanning Tree using Prim’s Algorithm.
  Greedy works only because the cut property holds.

---

## 🧠 Mental Model Summary

| Concept | What You’re Learning |
|------|---------------------|
| BFS with Levels | Constraints break naïve traversal |
| Dijkstra | Weighted shortest paths |
| Minimax Path | Cost ≠ sum of edges |
| Topological Sort | Ordering from dependencies |
| Eulerian Path | Edge-usage guarantees |
| Minimum Spanning Tree | Global cost minimization |

---

## ⚠️ Common Failure Points

- Using BFS on weighted graphs
- Forgetting stale-state checks in Dijkstra
- Missing prefix-invalid cases (Alien Dictionary)
- Treating Eulerian Path like backtracking
- Confusing MST with shortest path problems

---

## 🎯 Final Advice

If BFS teaches you **how traversal works**,  
and Dijkstra teaches you **how cost accumulates**,  
then structural problems teach you **what must exist**, not how to reach it.

Once you recognize **what property the graph must satisfy**,  
the algorithm choice becomes obvious.

That’s when graphs stop being hard.
