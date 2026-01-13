# 62. Unique Paths

## 📋 Problem Description
**Problem Number**: 62  
**Difficulty**: Medium  
**LeetCode Link**: [Unique Paths](https://leetcode.com/problems/unique-paths/)  
**Pattern**: Dynamic Programming (Grid)

---

### Problem Statement
There is a robot on an `m x n` grid. The robot is initially located at the **top-left corner** (`grid[0][0]`). The robot tries to move to the **bottom-right corner** (`grid[m - 1][n - 1]`). The robot can only move either **down** or **right** at any point in time.

Given the two integers `m` and `n`, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

---

### 📝 Examples

**Example 1:**
* **Input**: `m = 3, n = 7`
* **Output**: `28`

**Example 2:**
* **Input**: `m = 3, n = 2`
* **Output**: `3`

---

## 💡 Approach: Dynamic Programming (Tabulation)

### 1. Understanding the Decision Space
At any given cell $(i, j)$, the robot could have only arrived from two possible locations:
1.  The cell **directly above it** $(i-1, j)$ — by moving **Down**.
2.  The cell **directly to its left** $(i, j-1)$ — by moving **Right**.



### 2. State Transition
The total number of ways to reach a cell is the sum of the ways to reach its neighbors:
$$dp[i][j] = dp[i-1][j] + dp[i][j-1]$$



### 3. Base Cases & Initialization
* **First Row**: Any cell in the first row can only be reached by moving right repeatedly from $(0,0)$. Thus, `dp[0][j] = 1`.
* **First Column**: Any cell in the first column can only be reached by moving down repeatedly from $(0,0)$. Thus, `dp[i][0] = 1`.



---

## 📊 Trace Walkthrough ($3 \times 3$ Grid)
We start by filling the boundaries with `1`, then compute the interior:

| | Col 0 | Col 1 | Col 2 |
| :--- | :---: | :---: | :---: |
| **Row 0** | **1** | 1 | 1 |
| **Row 1** | 1 | **2** ($1+1$) | **3** ($2+1$) |
| **Row 2** | 1 | **3** ($1+2$) | **6** ($3+3$) |

**Final Result**: `6`

---

## ⚡ Complexity Analysis
* **Time Complexity**: $O(M \times N)$ — We iterate through every cell once.
* **Space Complexity**: $O(M \times N)$ — We maintain a 2D table. (Note: This can be optimized to $O(N)$ as we only need the previous row).

---
**Date Solved**: January 13, 2026
