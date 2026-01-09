# 567. Permutation in String

## 📋 Problem Description

**Problem Number**: 567  
**Difficulty**: Medium  
**LeetCode Link**: [Permutation in String](https://leetcode.com/problems/permutation-in-string/)  
**Topics**: Hash Table, Two Pointers, String, Sliding Window  

---

### Problem Statement

Given two strings `s1` and `s2`, return `true` if `s2` contains a permutation of `s1`, or `false` otherwise.

In other words, return `true` if one of `s1`'s permutations is the substring of `s2`.

---

### Examples

#### Example 1
**Input**: `s1 = "ab", s2 = "eidbaooo"`  
**Output**: `true`  
**Explanation**: `s2` contains one permutation of `s1` ("ba").

#### Example 2
**Input**: `s1 = "ab", s2 = "eidboaoo"`  
**Output**: `false`  

---

### Constraints

- `1 <= s1.length, s2.length <= 10^4`
- `s1` and `s2` consist of lowercase English letters.

---

## 💡 Approach

### Key Insight

A permutation of a string has the exact same character frequencies as the original string. Since we are looking for a **substring** permutation, we can use a **Fixed-Size Sliding Window** of length `s1.length()` and slide it across `s2`.



### Algorithm

1. **Edge Case**: If `s1.length() > s2.length()`, return `false`.
2. **Frequency Arrays**: Create two frequency arrays (size 26) named `need` (for `s1`) and `window` (for the current portion of `s2`).
3. **Slide the Window**:
   - Add the character at the right pointer `j` to the `window` array.
   - If the current window size is greater than `s1.length()`, remove the character at the left pointer `i` from the `window` array and increment `i`.
   - Compare `need` and `window`. If they are identical, return `true`.
4. **Return**: If the loop finishes without a match, return `false`.

---

## ⚡ Complexity Analysis

### Time Complexity: **O(M)**
- We traverse `s2` (length $M$) once.
- Comparing two arrays of size 26 takes $O(26)$, which is constant time $O(1)$.

### Space Complexity: **O(1)**
- We only use two fixed-size arrays of size 26, regardless of the lengths of `s1` or `s2`.

---

**Pattern**: Sliding Window (Fixed Size + Frequency Hashing)  
**Date Solved**: January 8, 2026
