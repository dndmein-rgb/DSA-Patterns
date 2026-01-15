# 329. Longest Increasing Path in a Matrix

## 📋 Problem Description
**Problem Number**: 329  
**Difficulty**: Hard  
**LeetCode Link**: [Longest Increasing Path in a Matrix](https://leetcode.com/problems/longest-increasing-path-in-a-matrix/)  
**Pattern**: DP (Grid) + DFS

---

### Problem Statement
Given an `m x n` integers `matrix`, return the length of the **longest increasing path** in the matrix. You can move up, down, left, or right to a cell with a **strictly greater** value.

---

### 📝 Examples

**Example 1:**

* **Input**: `matrix = [[9,9,4],[6,6,8],[2,1,1]]`
* **Output**: `4`
* **Explanation**: The longest increasing path is `[1, 2, 6, 9]`.

**Example 2:**
* **Input**: `matrix = [[3,4,5],[3,2,6],[2,2,1]]`
* **Output**: `4`
* **Explanation**: The longest increasing path is `[3, 4, 5, 6]`. Moving diagonally is not allowed.

---

## 💡 Approach: DFS + Memoization

This problem is solved using Depth First Search with Memoization. Since we only move to strictly increasing values, the graph is a **DAG (Directed Acyclic Graph)**, which guarantees no infinite recursion cycles.

### Comparison of Implementations

| Feature | Approach 1 (Explicit Vars) | Approach 2 (Compact 'Best') |
| :--- | :--- | :--- |
| **Initial Value** | `top/bottom = 0` | `best = 1` |
| **Logic** | Calculates neighbor paths and adds 1 at the end. | Includes the current cell in the recursive step. |
| **Storage** | `t[i][j]` stores relative path length. | `t[i][j]` stores absolute path length. |



### 📊 State Transition Diagram
For any cell $(i, j)$:
$$LIP(i, j) = 1 + \max \begin{cases} LIP(i-1, j) & \text{if } mat[i-1][j] > mat[i][j] \\ LIP(i+1, j) & \text{if } mat[i+1][j] > mat[i][j] \\ LIP(i, j-1) & \text{if } mat[i][j-1] > mat[i][j] \\ LIP(i, j+1) & \text{if } mat[i][j+1] > mat[i][j] \\ 0 & \text{otherwise} \end{cases}$$



---

## ⚡ Complexity Analysis
* **Time Complexity**: $O(N \times M)$ — Every cell is processed and cached once.
* **Space Complexity**: $O(N \times M)$ — Memoization table + recursion stack.

---
**Date Solved**: January 13, 2026
