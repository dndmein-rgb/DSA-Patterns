# 0286. Islands and Treasure (Walls and Gates)

## 📋 Problem Description
**Difficulty**: Medium  
**Pattern**: Multi-Source BFS / Grid Shortest Distance  

You are given an `m x n` grid with three possible values:

- `-1` → Water cell (blocked, cannot be traversed)
- `0` → Treasure chest
- `INF` (`2147483647`) → Land cell

Fill each land cell with the distance to its **nearest treasure chest**.
If a land cell cannot reach any treasure, its value should remain `INF`.

Movement is allowed **only in 4 directions**:
- Up
- Down
- Left
- Right

The grid must be modified **in-place**.

---

## 🛑 Constraints
- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 100`
- `grid[i][j] ∈ {-1, 0, 2147483647}`

---

## 🧠 Key Insight
This is a **shortest-path-in-grid** problem.

- Shortest path ⇒ BFS
- Multiple treasure chests ⇒ multi-source BFS
- DFS is incorrect for shortest distances

---

## 📌 Examples

### Example 1

**Input**
```
[
  [2147483647, -1, 0, 2147483647],
  [2147483647, 2147483647, 2147483647, -1],
  [2147483647, -1, 2147483647, -1],
  [0, -1, 2147483647, 2147483647]
]
```

**Output**
```
[
  [3, -1, 0, 1],
  [2, 2, 1, -1],
  [1, -1, 2, -1],
  [0, -1, 3, 4]
]
```

---

### Example 2

**Input**
```
[
  [0, -1],
  [2147483647, 2147483647]
]
```

**Output**
```
[
  [0, -1],
  [1, 2]
]
```

---

## 💡 Approach: Multi-Source BFS

1. Push all treasure cells (`0`) into a queue
2. Perform BFS
3. For each neighboring land cell (`INF`), update:
   ```
   grid[next] = grid[current] + 1
   ```
4. Ignore water and already-visited cells

---

## 🧭 Direction Handling
```
Up    (-1, 0)
Down  (+1, 0)
Left  (0, -1)
Right (0, +1)
```

---

## ⚙️ Complexity Analysis

| Metric | Complexity | Explanation |
|------|-----------|-------------|
| Time | `O(m × n)` | Each cell processed once |
| Space | `O(m × n)` | Queue in worst case |

---

## ✅ Key Takeaways
- Multi-source BFS guarantees shortest distance
- Start BFS from treasures, not land
- Modify grid in-place to avoid extra memory
