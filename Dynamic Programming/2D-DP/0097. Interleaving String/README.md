# 97. Interleaving String

## 📋 Problem Description
**Problem Number**: 97  
**Difficulty**: Medium  
**LeetCode Link**: [Interleaving String](https://leetcode.com/problems/interleaving-string/)  
**Pattern**: Dynamic Programming (Two Strings)

---

### Problem Statement
Given strings `s1`, `s2`, and `s3`, find whether `s3` is formed by an **interleaving** of `s1` and `s2`.

An interleaving of two strings `s` and `t` is a configuration where they are divided into non-empty substrings such that:
* `s = s1 + s2 + ... + sn`
* `t = t1 + t2 + ... + tm`
* The interleaving is `s1 + t1 + s2 + t2 + ...` or `t1 + s1 + t2 + s2 + ...`

---

### 📝 Examples

**Example 1:**
* **Input**: `s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"`
* **Output**: `true`

**Example 2:**
* **Input**: `s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"`
* **Output**: `false`

---

## 💡 Approach: Top-Down DP (Two Pointers + Memoization)

We use two pointers `i` and `j` to track our progress in `s1` and `s2`. The current position in `s3` is implicitly `i + j`.

### 1. Decision Logic
At any state `(i, j)`, we have two possible moves:
1. If `s1[i]` matches `s3[i+j]`, move pointer `i` forward.
2. If `s2[j]` matches `s3[i+j]`, move pointer `j` forward.

If both characters match, we branch into two recursive calls. If either call returns `true`, then the strings can be interleaved.



### 2. State Mapping (The Grid)
This problem can be visualized as finding a path from the top-left to the bottom-right of a 2D grid. Each "Right" move represents taking a character from `s2`, and each "Down" move represents taking a character from `s1`.



### 3. Edge Case
If `s1.length() + s2.length() != s3.length()`, it is mathematically impossible to form `s3`, so we return `false` immediately.

---

## ⚡ Complexity Analysis
* **Time Complexity**: $O(N \times M)$ — Where $N$ and $M$ are lengths of `s1` and `s2`. We compute each $(i, j)$ state once.
* **Space Complexity**: $O(N \times M)$ — To store the memoization table.

---
**Date Solved**: January 13, 2026
