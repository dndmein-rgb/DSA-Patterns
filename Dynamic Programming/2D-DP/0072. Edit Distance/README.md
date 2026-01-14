# 72. Edit Distance

## 📋 Problem Description
**Problem Number**: 72  
**Difficulty**: Hard  
**LeetCode Link**: [Edit Distance](https://leetcode.com/problems/edit-distance/)  
**Pattern**: Dynamic Programming (Two Strings)

---

### Problem Statement
Given two strings `word1` and `word2`, return the minimum number of operations required to convert `word1` to `word2`.

You have the following three operations permitted on a word:
1.  **Insert** a character
2.  **Delete** a character
3.  **Replace** a character

---

### 📝 Examples

**Example 1:**
* **Input**: `word1 = "horse", word2 = "ros"`
* **Output**: `3`
* **Explanation**: 
  horse -> rorse (replace 'h' with 'r')
  rorse -> rose (remove 'r')
  rose -> ros (remove 'e')

---

## 💡 Approach: Top-Down DP (Memoization)

The "Edit Distance" (or Levenshtein Distance) problem is the classic "Final Boss" of two-string matching problems.

### 1. Decision State Machine
At any indices $(i, j)$, if the characters do not match, we have three distinct choices to explore:



* **Insert**: We act as if we added a character. Pointer `j` moves because the requirement in `word2` is satisfied, but `i` stays because we still need to match `word1[i]`.
* **Delete**: We discard `word1[i]`. Pointer `i` moves forward, while `j` stays at the same position.
* **Replace**: We swap `word1[i]` for `word2[j]`. Both pointers move forward.

### 2. Base Case Logic
* If `i == n`, `word1` is empty. We must **insert** all remaining characters of `word2`. Cost: `m - j`.
* If `j == m`, `word2` is empty. We must **delete** all remaining characters of `word1`. Cost: `n - i`.

---

## 📊 Complexity Analysis

| Type | Complexity | Reason |
| :--- | :--- | :--- |
| **Time** | **$O(N \times M)$** | There are $N \times M$ unique states in the DP table. |
| **Space** | **$O(N \times M)$** | For the 2D memoization table `t[501][501]`. |



---
**Date Solved**: January 13, 2026
