
# 115. Distinct Subsequences

## 📋 Problem Description
**Problem Number**: 115  
**Difficulty**: Hard  
**LeetCode Link**: [Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/)  
**Pattern**: Dynamic Programming (String Subsequences)

---

### Problem Statement
Given two strings `s` and `t`, return the number of distinct **subsequences** of `s` which equals `t`.

A string subsequence is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the remaining characters' relative positions.

---

### 📝 Examples

**Example 1:**
* **Input**: `s = "rabbbit", t = "rabbit"`
* **Output**: `3`
* **Explanation**: 
  - **rabb**b**it**
  - **rab**b**bit**
  - **ra**b**bbit**
  (Bold characters represent the chosen subsequence).

---

## 💡 Approach: Top-Down DP (Memoization)

This problem is a "Counting Ways" variation of string matching. Unlike **Longest Common Subsequence**, where we find a length, here we sum up all possible valid paths.

### 1. The Decision Logic
At any state `(i, j)` where `s[i]` and `t[j]` are the current characters:

- **If `s[i] == t[j]`**:
    - **Choice A (Use it)**: We use this character to match `t[j]`. Now we look for `t[j+1]` in the remainder of `s`.
    - **Choice B (Ignore it)**: Even though it matches, we ignore this specific character in `s` and try to find the **entire** target `t[j...]` later in string `s`.
    - **Total Ways** = `solve(i+1, j+1)` + `solve(i+1, j)`.

- **If `s[i] != t[j]`**:
    - We have no choice but to skip `s[i]`.
    - **Total Ways** = `solve(i+1, j)`.



### 2. Base Cases
- `j == m`: If the pointer for `t` reaches the end, we've successfully formed one valid subsequence. Return `1`.
- `i == n`: If `s` is exhausted but `t` isn't, this path is invalid. Return `0`.



---

## ⚡ Complexity Analysis
* **Time Complexity**: $O(N \times M)$ — Every combination of indices $(i, j)$ is computed once.
* **Space Complexity**: $O(N \times M)$ — Memoization table size.

---
**Date Solved**: January 13, 2026
