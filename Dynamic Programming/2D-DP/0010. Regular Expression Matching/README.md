# 10. Regular Expression Matching

## 📋 Problem Description
**Problem Number**: 10  
**Difficulty**: Hard  
**LeetCode Link**: [Regular Expression Matching](https://leetcode.com/problems/regular-expression-matching/)  
**Pattern**: Dynamic Programming (String Matching)

---

### Problem Statement
Given an input string `s` and a pattern `p`, implement regular expression matching with support for `.` and `*` where:
* `.` Matches any single character.​​​​
* `*` Matches zero or more of the preceding element.

The matching should cover the **entire** input string (not partial).

---

### 📝 Examples
**Example 1:**
* **Input**: `s = "aa", p = "a*"`
* **Output**: `true` (The '*' means zero or more of 'a')

**Example 2:**
* **Input**: `s = "ab", p = ".*"`
* **Output**: `true` ('.' matches 'a', '*' makes it repeat, second '.' matches 'b')

---

## 💡 Approach: Top-Down DP (Memoization)

This is one of the most intricate string DP problems because of the **non-deterministic** nature of the `*` wildcard.

### 1. The '*' Wildcard Decision Tree
When we encounter a `*` (at `pattern[j+1]`), we face a branching path:
1.  **Skip the asterisk**: Treat `char*` as empty. Move to `pattern[j+2]`.
2.  **Use the asterisk**: If the current character matches (`first_match`), we consume one character from `text` (`i+1`) but keep the pattern pointer at `j` to allow the `*` to match more characters later.



### 2. Matching Logic
- **`.` (Dot)**: Simply acts as a wildcard for any single character. It's handled inside the `first_match` boolean.
- **Base Case**: If we run out of pattern characters, the only way to return `true` is if we also ran out of text characters.



---

## ⚡ Complexity Analysis

| Type | Complexity | Reason |
| :--- | :--- | :--- |
| **Time** | **$O(N \times M)$** | $N$ is text length, $M$ is pattern length. Each state $(i, j)$ is visited once. |
| **Space** | **$O(N \times M)$** | For the `t[21][21]` memoization table and recursion stack. |

---
**Date Solved**: January 13, 2026
