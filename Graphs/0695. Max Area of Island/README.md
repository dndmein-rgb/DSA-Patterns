Here is the complete, consolidated README.md for 695. Max Area of Island in a single copy-paste block.Markdown# 695. Max Area of Island

## 📋 Problem Description
**Difficulty**: Medium | **LeetCode Link**: [Max Area of Island](https://leetcode.com/problems/max-area-of-island/)
**Pattern**: Graph DFS / Matrix Connectivity

You are given an `m x n` binary matrix `grid`. An **island** is a group of `1`'s (representing land) connected **4-directionally** (horizontal or vertical). The **area** of an island is the total number of cells in that island. Return the maximum area found.

---

## 🛑 Constraints
- `m == grid.length`, `n == grid[i].length`
- `1 <= m, n <= 50`
- `grid[i][j]` is either `0` or `1`.

---

## 📝 Visual Examples & Logic

#### **Example 1: Multiple Distinct Islands**
**Input Matrix**:
```text
┌───┬───┬───┬───┬───┐
│ 0 │ 0 │ 1 │ 0 │ 0 │
├───┼───┼───┼───┼───┤
│ 0 │ 1 │ 1 │ 1 │ 0 │
├───┼───┼───┼───┼───┤
│ 0 │ 0 │ 1 │ 0 │ 0 │
├───┼───┼───┼───┼───┤
│ 1 │ 1 │ 0 │ 1 │ 1 │
└───┴───┴───┴───┴───┘
Logic:Island 1 (The Cross): Cells at (0,2), (1,1), (1,2), (1,3), (2,2) → Area = 5Island 2 (Bottom Left): Cells at (3,0), (3,1) → Area = 2Island 3 (Bottom Right): Cells at (3,3), (3,4) → Area = 2Output: 5Example 2: Diagonal IsolationInput Matrix:Plaintext┌───┬───┬───┐
│ 1 │ 0 │ 1 │
├───┼───┼───┤
│ 0 │ 1 │ 0 │
├───┼───┼───┤
│ 1 │ 0 │ 1 │
└───┴───┴───┘
Logic:Since diagonals do not connect, there are 5 separate islands.Each island has an Area of 1.Output: 1💡 Approach: Flood Fill (DFS)1. Recursive AccumulationThe DFS function is designed to return an integer representing the total area:It starts with 1 to count the current cell.It recursively calls itself for neighbors in 4 directions and adds their returned values to the total.2. Sinking the IslandTo avoid infinite loops and the need for a visited matrix, we "sink" the land by setting grid[r][c] = 0 as soon as we visit it. This ensures each cell is only processed once.3. Directional Search PatternThe algorithm strictly follows a 4-way connectivity ruleset (Up, Down, Left, Right).⚡ Complexity AnalysisMetricComplexityExplanationTimeO(N × M)Each cell is processed by the nested loops and visited by the DFS at most once.SpaceO(N × M)In the worst case (e.g., all land), the recursion stack depth reaches the total number of cells
