# 1143. Longest Common Subsequence

## 📋 Problem Description
**Problem Number**: 1143  
**Difficulty**: Medium  
**LeetCode Link**: [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/)  
**Pattern**: Dynamic Programming (Two Strings)

---

### Problem Statement
Given two strings `text1` and `text2`, return the length of their **longest common subsequence**. If there is no common subsequence, return `0`.

A **subsequence** of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

---

### 📝 Examples

**Example 1:**
* **Input**: `text1 = "abcde", text2 = "ace"` 
* **Output**: `3`  
* **Explanation**: The longest common subsequence is "ace" and its length is 3.

**Example 2:**
* **Input**: `text1 = "abc", text2 = "def"`
* **Output**: `0`

---

## 💡 Approach: Top-Down DP (Memoization)

This problem involves comparing two strings character by character. At any two indices $(i, j)$, we are faced with a choice based on whether the characters match.

### 1. Decision Logic
- **If characters match** (`text1[i] == text2[j]`):
  We found a common character! We add `1` to our count and move both pointers forward to look for the next match.
- **If characters do not match**:
  We have two possibilities:
  1. Skip the current character of `text1` and keep `text2` pointer same.
  2. Skip the current character of `text2` and keep `text1` pointer same.
  We take the **maximum** result from these two paths.



### 2. Memoization Table
Because we have many overlapping subproblems (e.g., skipping `text1[i]` then `text2[j]` leads to the same state as skipping `text2[j]` then `text1[i]`), we store the results in a 2D array `t[1001][1001]`.



---

## ⚡ Complexity Analysis
* **Time Complexity**: $O(N \times M)$ — Each state $(i, j)$ is computed only once.
* **Space Complexity**: $O(N \times M)$ — To store the memoization table and recursion stack.

---
**Date Solved**: January 13, 2026
