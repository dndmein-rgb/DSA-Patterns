# 63. Unique Paths II

## 📋 Problem Description
**Difficulty**: Medium  
**Pattern**: Dynamic Programming (Grid with Obstacles)

### Problem Statement
Similar to Unique Paths I, but now the grid contains **obstacles** (represented by `1`). You cannot walk through obstacles. 

---

## 💡 The "Complex Work" Approach: Handling Constraints

When obstacles are introduced, the "simple" initialization of the first row/column used in Unique Paths I fails. If a cell in the first row is blocked, **every cell after it** in that row also becomes unreachable.



### Decision Logic & State Transition
1. **The Blockage Rule**: If `grid[i][j] == 1`, then `dp[i][j] = 0`. It contributes nothing to future paths.
2. **The Flow Rule**: If `grid[i][j] == 0`, it inherits the sum of its neighbors.

### Visualizing the Obstacle Flow
Imagine a $3 \times 3$ grid with an obstacle at `(1,1)`:
```text
[S][1][1]      (S) Start
[1][X][1]      (X) Obstacle
[1][1][E]      (E) End
