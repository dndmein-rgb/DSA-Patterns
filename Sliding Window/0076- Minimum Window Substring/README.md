# 76. Minimum Window Substring

## 📋 Problem Description

**Problem Number**: 76  
**Difficulty**: Hard  
**LeetCode Link**: [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/)  
**Topics**: Hash Table, String, Sliding Window  

---

### Problem Statement

Given two strings `s` and `t` of lengths `m` and `n` respectively, return the **minimum window substring** of `s` such that every character in `t` (including duplicates) is included in the window. If there is no such substring, return the empty string `""`.

The testcases will be generated such that the answer is **unique**.

---

### Examples

#### Example 1
**Input**: `s = "ADOBECODEBANC", t = "ABC"`  
**Output**: `"BANC"`  
**Explanation**: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

#### Example 2
**Input**: `s = "a", t = "a"`  
**Output**: `"a"`

#### Example 3
**Input**: `s = "a", t = "aa"`  
**Output**: `""`  
**Explanation**: Both 'a's from t must be included in the window. Since the window has only one 'a', it is return "".

---

### Constraints

- `m == s.length`, `n == t.length`
- `1 <= m, n <= 10^5`
- `s` and `t` consist of uppercase and lowercase English letters.

---

## 💡 Approach

### Key Insight

This is a **Variable Size Sliding Window** problem using an "Expand and Contract" strategy. We expand the window until it contains all necessary characters from `t`, then contract it from the left to find the smallest possible valid window.



### Algorithm

1. **Map Requirements**: Use a frequency array `need` to store counts of characters in `t`.
2. **Expand**: Move the right pointer `j`. Increment the frequency of `s[j]` in a `window` map. If `window[s[j]] == need[s[j]]`, we have satisfied the requirement for one unique character.
3. **Contract**: While the window is "desirable" (contains all characters of `t` with required frequencies):
   - Update the minimum length and starting index.
   - Remove `s[i]` from the window and increment the left pointer `i`.
   - If the count of `s[i]` drops below `need[s[i]]`, the window is no longer desirable; stop contracting and return to the expand step.

---

## ⚡ Complexity Analysis

### Time Complexity: **O(M + N)**
- We traverse string `t` once to build the frequency map ($O(N)$).
- We traverse string `s` with two pointers, `i` and `j`. Each character is visited at most twice ($O(M)$).

### Space Complexity: **O(K)**
- We use frequency arrays of size 256. Since the character set $K$ is constant, this is effectively **O(1)**.

---

**Pattern**: Sliding Window (Variable Size + Frequency Requirement)  
**Date Solved**: January 8, 2026
