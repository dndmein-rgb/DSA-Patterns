# 🕸️ Graph Traversal Hierarchy: From Flood Fill to Cycle Detection

This roadmap represents the mental progression required to master **graph problems**—from simple connectivity to directed cycles and state propagation.  
If DP is about *state*, graphs are about *reachability*.

---

## 🧱 Level 1: Grid DFS/BFS – Flood Fill (The Foundation)
**The Focus:**  
Learn to traverse a grid. No tricks. Just directions, bounds, and visited tracking.

If you can’t do these, graphs will feel impossible.

* [0200. Number of Islands](./0200.%20Number%20of%20Islands)  
  Count connected components in a grid. This is ground zero.
* [0695. Max Area of Island](./0695.%20Max%20Area%20of%20Island)  
  Same traversal, but now you accumulate state.
* [0130. Surrounded Regions](./0130.%20Surrounded%20Regions)  
  Boundary-based flood fill. Learn what **not** to flip.
* [0994. Rotting Oranges](./0994.%20Rotting%20Oranges)  
  First exposure to **multi-source BFS** and time simulation.

---

## 🌊 Level 2: Multi-Source BFS – Distance Propagation
**The Focus:**  
Start BFS from *many* sources at once. Distance spreads like a wave.

This is where BFS stops being “just a queue”.

* [0286. Islands and Treasure](./0286-Islands-and-Treasure)  
  Classic multi-source BFS. Nearest distance problem.
* [0127. Word Ladder](./0127.%20Word%20Ladder)  
  BFS on an implicit graph. Each word is a node.
* [0417. Pacific Atlantic Water Flow](./0417.%20Pacific%20Atlantic%20Water%20Flow)  
  Reverse thinking. Flow **from** oceans, not to them.

---

## 🧩 Level 3: Graph Construction + Traversal
**The Focus:**  
The graph isn’t given explicitly. You must build it correctly.

Mistakes here cause invisible bugs.

* [0133. Clone Graph](./0133.%20Clone%20Graph)  
  Graph copying + visited mapping. Pointer discipline test.
* [0323. Number of Connected Components in an Undirected Graph](./0323.%20Number%20of%20Connected%20Components%20in%20an%20Undirected%20Graph)  
  Same idea as islands, minus the grid training wheels.

---

## 🔗 Level 4: Tree Properties & Cycle Detection (Undirected)
**The Focus:**  
Understand what makes a graph a **tree**:  
connected + acyclic.

* [0261. Graph Valid Tree](./0261.%20Graph%20Valid%20Tree)  
  DFS + parent tracking or Union-Find.
* [0684. Redundant Connection](./0684.%20Redundant%20Connection)  
  Detect the exact edge that creates a cycle. Union-Find shines here.

---

## 🎓 Level 5: Directed Graphs – Dependencies & Order
**The Focus:**  
Direction matters. Cycles are fatal. Order is the output.

This is where graphs become interview-critical.

* [0207. Course Schedule](./0207.%20Course%20Schedule)  
  Can you finish all courses? Cycle detection in DAGs.
* [0210. Course Schedule II](./0210.%20Course%20Schedule%20II)  
  Same graph, but now you must return the order.
  Topological sort is non-negotiable here.

---

## 🧠 Mental Model Summary

| Concept | What You’re Learning |
|------|---------------------|
| Flood Fill | Reachability |
| Multi-Source BFS | Distance & time |
| Graph Construction | Correct adjacency modeling |
| Undirected Cycles | Tree vs non-tree |
| Directed Cycles | Dependency resolution |
| Topological Sort | Ordering constraints |

---

## ⚠️ Common Failure Points
- Forgetting to mark visited early (causes infinite loops)
- Mixing up BFS vs DFS use cases
- Not resetting visited for per-edge checks
- Treating directed graphs like undirected ones
- Avoiding Union-Find when it’s clearly the right tool

---

## 🎯 Final Advice
If DP teaches you **how states evolve**,  
Graphs teach you **what can reach what**.

Master this roadmap and graph problems stop being scary—they become repetitive.

That’s the goal.
