# 91. Decode Ways

## 📋 Problem Description
**Problem Number**: 91  
**Difficulty**: Medium  
**LeetCode Link**: [Decode Ways](https://leetcode.com/problems/decode-ways/)  
**Pattern**: Dynamic Programming (Linear / String Partitioning)

---

### Problem Statement
A message containing letters from A-Z can be encoded into numbers using the following mapping:
'A' -> "1", 'B' -> "2", ..., 'Z' -> "26".

Given a string `s` containing only digits, return the **number of ways** to decode it.

---

## 💡 Approach: Top-Down DP (Memoization)

The problem asks for the total number of ways to partition a string into valid segments (1-26). This is a classic "decision-making" DP.



### The Decision Logic
At any index `i`, we have two choices:
1. **Take 1 Digit**: If `s[i]` is not '0', it can represent a letter (1-9). We move to `i + 1`.
2. **Take 2 Digits**: If the number formed by `s[i]` and `s[i+1]` is between `10` and `26`, it represents a letter (J-Z). We move to `i + 2`.

### Key Constraints (The '0' Problem)
- A standalone '0' is invalid (no letter maps to 0).
- A '0' can only exist as part of "10" or "20".
- If a substring starts with '0' (like "06"), it cannot be decoded.



---

## ⚡ Complexity Analysis
* **Time Complexity**: $O(N)$ — Each index from $0$ to $N$ is computed exactly once due to memoization.
* **Space Complexity**: $O(N)$ — We use an array of size 101 and the recursion stack depth is $N$.

---
**Date Solved**: January 12, 2026
