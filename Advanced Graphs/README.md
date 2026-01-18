# 🌐 Graph Algorithms Hierarchy: From BFS Intuition to Advanced Constraints

This roadmap represents the mental progression required to stop guessing in graph problems and start **recognizing patterns on sight**.

---

## 🧱 Level 1: Graph Traversal Basics (Reachability first)

**The Focus**: Stop panicking. Learn how nodes are visited and marked.

* [0787. Cheapest Flights Within K Stops](./0787-Cheapest-Flights-Within-K-Stops)  
  BFS with levels. Constraints break classic shortest path. Learn why.

---

## 🧭 Level 2: Shortest Path (Weighted graphs, real decisions)

**The Focus**: When edges have weights, BFS lies to you.

* [0743. Network Delay Time](./0743-Network-Delay-Time)  
  Single-source shortest path. Pure Dijkstra. No tricks.

* [0778. Swim in Rising Water](./0778-Swim-in-Rising-Water)  
  Dijkstra with a **minimax cost function**. Path cost ≠ sum.

---

## 🧠 Level 3: Structural Graph Problems (Ordering & paths)

**The Focus**: Graphs are not always about distance.

* [0269. Alien Dictionary](./0269-Alien-Dictionary)  
  Dependency extraction + topological sort. Prefix edge case matters.

* [0332. Reconstruct Itinerary](./0332-Reconstruct-Itinerary)  
  Eulerian path with lexicographical constraints. DFS post-order or fail.

---

## 🌉 Level 4: Spanning Trees (Global optimal structure)

**The Focus**: Connect everything as cheaply as possible.

* [1584. Min Cost to Connect All Points](./1584-Min-Cost-to-Connect-All-Points)  
  Minimum Spanning Tree using Prim’s Algorithm on a complete graph.

---

## 🧠 Core Patterns You Must Recognize

### Pattern 1: BFS with Constraints
- Levels matter
- Stops / steps / hops are limited
- **Example**: 787

### Pattern 2: Dijkstra (Shortest Path)
- Non-negative weights
- Min-heap is mandatory
- **Example**: 743

### Pattern 3: Minimax Path
- Path cost = max edge on path
- Still Dijkstra, different relaxation
- **Example**: 778

### Pattern 4: Topological Sort
- Ordering constraints
- Detect cycles
- **Example**: 269

### Pattern 5: Eulerian Path
- Use every edge exactly once
- Post-order DFS (Hierholzer)
- **Example**: 332

### Pattern 6: Minimum Spanning Tree
- Connect all nodes with minimum cost
- Global optimality, not paths
- **Example**: 1584

---

## 🛠️ Core Dijkstra Template

```cpp
priority_queue<P, vector<P>, greater<P>> pq;
pq.push({0, src});
dist[src] = 0;

while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (d > dist[u]) continue;

    for (auto [v, w] : adj[u]) {
        if (dist[v] > d + w) {
            dist[v] = d + w;
            pq.push({dist[v], v});
        }
    }
}
```

---

## 🛠️ Core BFS-with-Levels Template

```cpp
queue<pair<int,int>> q;
q.push({src, cost});
int level = 0;

while (!q.empty() && level <= k) {
    int sz = q.size();
    while (sz--) {
        auto [u, d] = q.front(); q.pop();
        for (auto [v, w] : adj[u]) {
            relax(v, d + w);
        }
    }
    level++;
}
```

---

## 🛠️ Core Topological Sort Template (Kahn)

```cpp
queue<char> q;
for (auto [node, deg] : indegree)
    if (deg == 0) q.push(node);

while (!q.empty()) {
    char u = q.front(); q.pop();
    for (char v : adj[u]) {
        if (--indegree[v] == 0)
            q.push(v);
    }
}
```

---

## 🎯 Learning Path Recommendation

1. **Start with 787** – Understand why BFS sometimes works and sometimes doesn’t  
2. **Move to 743** – Learn proper Dijkstra mechanics  
3. **Then 778** – Break the “sum of weights” mental model  
4. **Study 269** – Ordering without distances  
5. **Then 332** – Edge-usage problems are different  
6. **Finish with 1584** – Global optimal structures (MST)

---

## 🔥 Common Mistakes to Avoid

- Using BFS on weighted graphs
- Forgetting stale-state checks in Dijkstra
- Ignoring prefix invalid cases (Alien Dictionary)
- Thinking Eulerian Path is backtracking
- Confusing MST with shortest path

---

## 📁 Repository Structure

```
Graph/
├── 0269-Alien-Dictionary/
├── 0332-Reconstruct-Itinerary/
├── 0743-Network-Delay-Time/
├── 0778-Swim-in-Rising-Water/
├── 0787-Cheapest-Flights-Within-K-Stops/
├── 1584-Min-Cost-to-Connect-All-Points/
└── README.md
```

---

## 🎓 Progress Check

If you can:
- Explain **why BFS fails in 743**
- Explain **why Dijkstra still works in 778**
- Explain **why post-order DFS is required in 332**

You are no longer “learning graphs”.  
You’re **recognizing them**.
