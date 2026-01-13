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
* **Explanation**: From the top-left corner, there are a total of 3 ways to reach the bottom-right:
  1. Right -> Down -> Down
  2. Down -> Down -> Right
  3. Down -> Right -> Down

---

### 📊 Visual Representation
In a $3 \times 3$ grid, the number of ways to reach each cell is calculated as follows:



```text
    1    1    1
    1    2    3
    1    3    6  <-- Result for 3x3
