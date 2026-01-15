# 695. Max Area of Island

## 📋 Problem Description
**Difficulty**: Medium | **LeetCode Link**: [Max Area of Island](https://leetcode.com/problems/max-area-of-island/)
**Pattern**: Graph DFS / Matrix Connectivity

You are given an `m x n` binary matrix `grid`. An **island** is a group of `1`'s (representing land) connected **4-directionally**. The **area** of an island is the total number of cells in that island. Return the maximum area found.

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
