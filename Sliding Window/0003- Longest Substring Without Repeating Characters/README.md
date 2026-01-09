# 3. Longest Substring Without Repeating Characters

## 📋 Problem Description

**Problem Number**: 3  
**Difficulty**: Medium  
**LeetCode Link**: [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)  
**Topics**: Hash Table, String, Sliding Window  

---

### Problem Statement

Given a string `s`, find the length of the **longest substring** without repeating characters.

---

### Examples

#### Example 1
**Input**: `s = "abcabcbb"`  
**Output**: `3`  
**Explanation**: The answer is "abc", with the length of 3.

#### Example 2
**Input**: `s = "bbbbb"`  
**Output**: `1`  
**Explanation**: The answer is "b", with the length of 1.

---

### Constraints

- `0 <= s.length <= 5 * 10^4`
- `s` consists of English letters, digits, symbols and spaces.

---

## 💡 Approach

### Key Insight

This is a **Variable Size Sliding Window** problem. By storing the last seen index of each character, we can "jump" the left pointer `i` forward efficiently whenever a duplicate is encountered within the current window.



### Algorithm

1. **Initialize**: Use a vector `last` (size 256) set to -1 to store character indices.
2. **Expand**: Move the right pointer `j` across the string.
3. **Validate**: If `s[j]` was seen at an index $\ge i$, it means the character is a duplicate within the current window. Move `i` to `last[s[j]] + 1`.
4. **Update**: Update `last[s[j]]` to the current index and calculate `maxLen = max(maxLen, j - i + 1)`.

---

## ⚡ Complexity Analysis

### Time Complexity: **O(n)**
- We traverse the string exactly once with the right pointer.

### Space Complexity: **O(1)**
- We use a fixed-size auxiliary array (256 characters), which does not scale with input size.

---

**Pattern**: Sliding Window (Variable)  
**Date Solved**: January 8, 2026
