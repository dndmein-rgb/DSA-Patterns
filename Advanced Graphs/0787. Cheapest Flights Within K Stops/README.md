# 787. Cheapest Flights Within K Stops

**Difficulty:** Medium  
**LeetCode:** [Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/)  
**Pattern:** Graph + BFS (Level-Limited Relaxation)

---

## 📌 Problem Statement

You are given:
- `n` cities labeled `0` to `n-1`
- `flights[i] = [from, to, price]`
- Source city `src`, destination `dst`
- Maximum allowed stops `k`

Return the **minimum cost** to reach `dst` from `src` using **at most `k` stops**.  
If it’s not possible, return `-1`.

---

## 🧠 Core Insight

This problem **looks like Dijkstra**, but isn’t.

Why?
- There’s a **hard limit on stops**
- Standard Dijkstra ignores path length constraints

Instead, we do:
- **BFS by levels**, where each level = one more stop
- Relax edges level by level, up to `k` stops

Think of it as **Bellman-Ford limited to `k + 1` iterations**, implemented with BFS.

---

## 🛠️ Algorithm

1. Build adjacency list
2. Maintain a `distance[]` array for cheapest cost found so far
3. Use a queue storing `{node, current_cost}`
4. Process BFS **level by level**
5. For each level:
   - Relax outgoing edges
   - Update distances only if cheaper
6. Stop after `k` levels

---

## 🧪 Dry Run

```
n = 4
flights = [[0,1,100],[1,2,100],[2,3,100],[0,3,500]]
src = 0, dst = 3, k = 1
```

Levels:
- Level 0: 0 → 1 (100), 0 → 3 (500)
- Level 1: 1 → 2 (200) ❌ exceeds stop limit for dst

Cheapest valid:
```
0 → 3 = 500
```

Answer = `500`

---

## ⏱️ Complexity

- **Time:** `O(k * E)`
- **Space:** `O(V + E)`

Efficient because `k` is small.

---

## ✅ Key Takeaways

- Stop constraint breaks classic Dijkstra
- BFS by levels enforces stop limits cleanly
- This is Bellman-Ford thinking in BFS clothing
- Distance array must not reset per level

If you see “at most K stops,” do **not** blindly reach for Dijkstra. This pattern is the correct reflex.
