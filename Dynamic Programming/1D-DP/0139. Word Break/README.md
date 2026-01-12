# 139. Word Break

## 📋 Problem Description
**Problem Number**: 139  
**Difficulty**: Medium  
**LeetCode Link**: [Word Break](https://leetcode.com/problems/word-break/)  
**Pattern**: Dynamic Programming (String Partitioning)

---

### Problem Statement
Given a string `s` and a dictionary of strings `wordDict`, return `true` if `s` can be segmented into a space-separated sequence of one or more dictionary words.

**Note**: The same word in the dictionary may be reused multiple times in the segmentation.

---

## 💡 Approach: Top-Down DP (Memoization)

This problem requires us to determine if a string can be split into valid parts. This is a **Linear DP** problem where the state depends on the suffix of the string.



### Logic
1. **State**: `t[i]` represents whether the substring `s[i...n-1]` can be segmented into valid dictionary words.
2. **Transitions**: At index `i`, we try all possible split points `j`. If the substring `s[i...j]` exists in our dictionary, we recursively check if the remaining substring `s[j+1...n-1]` is also valid.
3. **Memoization**: Since many suffixes will be checked multiple times (overlapping subproblems), we store the result of `solve(i)` in an array.
4. **Optimization**: Using an `unordered_set` for the dictionary allows for $O(1)$ average time complexity for word lookups.



---

## ⚡ Complexity Analysis
* **Time Complexity**: $O(N^3)$ — There are $N$ states. For each state, we iterate $N$ times to find a split, and string operations (like building the substring) take $O(N)$.
* **Space Complexity**: $O(N + M)$ — $O(N)$ for the memoization array and recursion stack, and $O(M)$ for the dictionary set.

---
**Date Solved**: January 12, 2026
