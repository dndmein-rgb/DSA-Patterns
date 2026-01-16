# 695. Max Area of Island

## 📋 Problem Description
**Difficulty**: Medium  
**LeetCode**: [Max Area of Island](https://leetcode.com/problems/max-area-of-island/)**Pattern**: Graph DFS / Matrix Connectivity  

You are given an `m x n` binary matrix `grid`.  
An **island** is a group of `1`s (land) connected **4-directionally** (up, down, left, right).  
The **area** of an island is the total number of cells in that island.

Return the **maximum area** of any island in the grid.  
If there is no land, return `0`.

---

## 🛑 Constraints
- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 50`
- `grid[i][j]` is either `0` or `1`

---

## 🧠 Examples & Figures

### Example 1: Multiple Distinct Islands

**Input Grid**
```
┌───┬───┬───┬───┬───┐
│ 0 │ 0 │ 1 │ 0 │ 0 │
├───┼───┼───┼───┼───┤
│ 0 │ 1 │ 1 │ 1 │ 0 │
├───┼───┼───┼───┼───┤
│ 0 │ 0 │ 1 │ 0 │ 0 │
├───┼───┼───┼───┼───┤
│ 1 │ 1 │ 0 │ 1 │ 1 │
└───┴───┴───┴───┴───┘
```

**Island Breakdown**
- Island 1 (cross shape):  
  Cells → `(0,2), (1,1), (1,2), (1,3), (2,2)`  
  Area = **5**
- Island 2 (bottom-left):  
  Cells → `(3,0), (3,1)`  
  Area = **2**
- Island 3 (bottom-right):  
  Cells → `(3,3), (3,4)`  
  Area = **2**

**Output**
```
5
```

---

### Example 2: Diagonal Cells Are NOT Connected

**Input Grid**
```
┌───┬───┬───┐
│ 1 │ 0 │ 1 │
├───┼───┼───┤
│ 0 │ 1 │ 0 │
├───┼───┼───┤
│ 1 │ 0 │ 1 │
└───┴───┴───┘
```

**Explanation**
- Diagonal adjacency does **not** count
- Each `1` is isolated
- Total islands = 5
- Maximum area = **1**

**Output**
```
1
```

---

## 💡 Approach: Flood Fill using DFS

### 1. Recursive Area Accumulation
- When a land cell (`1`) is found, start DFS
- Count the current cell as `1`
- Recursively explore all 4 directions
- Add the returned areas together

### 2. Sink the Island
- Mark visited land as water: `grid[r][c] = 0`
- Prevents revisits
- Removes the need for a separate `visited` matrix

### 3. Directional Rules
- Allowed directions:
  - Up
  - Down
  - Left
  - Right
- Diagonals are intentionally ignored

---

## ⚙️ Complexity Analysis

| Metric | Complexity | Explanation |
|------|-----------|-------------|
| Time | `O(m × n)` | Each cell is visited once |
| Space | `O(m × n)` | Worst-case recursion stack |

---

## ✅ Key Takeaways
- Classic DFS flood-fill
- In-place grid mutation simplifies logic
- Each island is explored exactly once
- BFS is an equivalent alternative
