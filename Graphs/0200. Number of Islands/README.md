# 200. Number of Islands

## 📋 Problem Description
**Difficulty**: Medium | **LeetCode Link**: [Number of Islands](https://leetcode.com/problems/number-of-islands/)
**Pattern**: Graph DFS / Matrix Connectivity

Given an `m x n` binary grid, return the number of islands. An island is formed by connecting adjacent lands ('1's) horizontally or vertically.

---

## 🛑 Constraints
- `m == grid.length`, `n == grid[i].length`
- `1 <= m, n <= 300`
- `grid[i][j]` is `'0'` (water) or `'1'` (land).

---

## 📝 Comprehensive Examples & Logical Explanations

| Example | Input Matrix | Output | Logic |
| :--- | :--- | :--- | :--- |
| **1. Standard** | `11110`, `11010`, `11000`, `00000` | **1** | All 1s are connected via horizontal/vertical neighbors. |
| **2. Scattered** | `11000`, `11000`, `00100`, `00011` | **3** | Top-left block (1), Middle cell (2), Bottom-right pair (3). |
| **3. Diagonal** | `101`, `010`, `101` | **5** | Diagonals don't count. Each '1' is its own separate island. |
| **4. Donut** | `111`, `101`, `111` | **1** | A ring of 1s around a 0 is still one continuous island. |

---

## 💡 Approach: The "Sinking" Strategy (DFS)

### 1. Linear Scan
We iterate through every cell in the grid using nested loops to ensure no land cell is missed.

### 2. Triggering the DFS
When we encounter a `'1'`, it represents the first piece of an island we haven't counted yet. We increment the `count` and launch a Depth First Search (DFS) from that cell.

### 3. Sinking the Island (In-Place)

Instead of using extra memory for a `visited` array, we modify the `grid` directly. As the DFS visits a land cell, it sets it to `'0'`. This "sinks" the entire island, so our main scan won't count the same land twice.

### 4. 4-Way Exploration

The DFS checks strictly **Up, Down, Left, and Right**. It does not check diagonals.

---

## ⚡ Complexity Analysis

| Metric | Complexity | Explanation |
| :--- | :--- | :--- |
| **Time** | **O(N × M)** | Every cell is visited at most twice: once by the scan and once by the DFS. |
| **Space** | **O(N × M)** | No extra array, but the recursion stack can reach N×M in a grid of all land. |

---
**Date Solved**: January 15, 2026
