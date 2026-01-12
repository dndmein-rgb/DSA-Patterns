# 5. Longest Palindromic Substring

## 📋 Problem Description
**Problem Number**: 5  
**Difficulty**: Medium  
**LeetCode Link**: [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)  
**Pattern**: Dynamic Programming / Two Pointers (Expand Around Center)

---

### Problem Statement
Given a string `s`, return the longest palindromic substring in `s`.

---

## 💡 Implementation Strategies

### 1. Top-Down (Memoization)
We define a subproblem `isPal(i, j)` which checks if the substring from index `i` to `j` is a palindrome.
- **Recurrence**: `isPal(i, j) = (s[i] == s[j]) && isPal(i+1, j-1)`
- **Base Case**: If `i >= j`, it's a palindrome (true).
- **Optimization**: Use a 2D array `t[1001][1001]` to store results of previously checked ranges.



### 2. Expand Around Center (Recommended)
A palindrome mirrors around its center. There are $2n - 1$ such centers (each character and each gap between characters).
- **Odd centers**: `expand(i, i)` — e.g., "aba" centered at 'b'.
- **Even centers**: `expand(i, i+1)` — e.g., "abba" centered between 'b' and 'b'.



**Why is this better?** While both are $O(N^2)$, the center expansion technique uses **$O(1)$ space**, whereas DP requires $O(N^2)$ space to store the table.

---

## ⚡ Complexity Comparison

| Feature | Top-Down DP | Expand Around Center |
| :--- | :--- | :--- |
| **Time Complexity** | $O(N^2)$ | $O(N^2)$ |
| **Space Complexity** | $O(N^2)$ | $O(1)$ |
| **Efficiency** | Slower (Memoization overhead) | Faster (Direct expansion) |

---
**Date Solved**: January 12, 2026
