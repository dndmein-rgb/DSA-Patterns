# 647. Palindromic Substrings

## 📋 Problem Description
**Problem Number**: 647  
**Difficulty**: Medium  
**LeetCode Link**: [Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings/)  
**Pattern**: Two Pointers / Expand Around Center

---

### Problem Statement
Given a string `s`, return the number of **palindromic substrings** in it.
A string is a **palindrome** when it reads the same backward as forward.

---

## 💡 Approach: Expand Around Center

Instead of checking every possible substring ($O(N^3)$), we iterate through every possible "center" of a palindrome.



### Logic Overview
1.  **Centers**: A string of length $N$ has $2N-1$ possible centers (each character and the space between characters).
2.  **Expansion**: For each center, we expand outwards as long as the left and right characters match.
3.  **Counting**: Every time we find a match during expansion, it counts as one unique palindromic substring.

### Two Scenarios for Expansion
* **Odd-Length**: Start `left = i, right = i`. This finds palindromes like "aba".
* **Even-Length**: Start `left = i, right = i + 1`. This finds palindromes like "abba".



---

## ⚡ Complexity Analysis
* **Time Complexity**: $O(N^2)$ — We check $O(N)$ centers, and each expansion takes $O(N)$ in the worst case.
* **Space Complexity**: $O(1)$ — No extra space or DP table required.

---
**Date Solved**: January 12, 2026
