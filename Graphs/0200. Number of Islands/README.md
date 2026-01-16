# 0200. Number of Islands

## 📋 Problem Description
**Difficulty**: Medium  
**LeetCode**: [Number of Islands](https://leetcode.com/problems/number-of-islands/)  
**Pattern**: Graph DFS / Matrix Connectivity  

Given an `m x n` binary grid, return the number of islands.

An island is formed by connecting adjacent lands ('1') horizontally or vertically.
Water cells are represented by '0'.

---

## 🛑 Constraints
- m == grid.length, n == grid[i].length
- 1 <= m, n <= 300
- grid[i][j] is '0' or '1'

---

## 📝 Examples (Visual Matrix)

Example 1: Standard

Input
1 1 1 1 0  
1 1 0 1 0  
1 1 0 0 0  
0 0 0 0 0  

Output  
1

Explanation  
All land cells are connected via horizontal or vertical neighbors.

---

Example 2: Scattered

Input  
1 1 0 0 0  
1 1 0 0 0  
0 0 1 0 0  
0 0 0 1 1  

Output  
3

Explanation  
Top-left block is one island, the middle single cell is one island, and the bottom-right pair is one island.

---

Example 3: Diagonal Only

Input  
1 0 1  
0 1 0  
1 0 1  

Output  
5

Explanation  
Diagonal connections do not count, so every land cell is isolated.

---

Example 4: Donut Shape

Input  
1 1 1  
1 0 1  
1 1 1  

Output  
1

Explanation  
All land cells form a single continuous island despite the hole in the center.

---

## 💡 Approach (DFS – Sink the Island)

1. Traverse the entire grid.
2. When a '1' is found, increment the island count.
3. Run DFS from that cell.
4. During DFS, mark visited land as '0' to avoid revisiting.
5. Explore only up, down, left, and right.

---

## ⚡ Complexity Analysis
Time Complexity: O(m × n)  
Space Complexity: O(m × n) due to recursion stack in the worst case.

---

Date Solved: January 15, 2026
