# 438. Find All Anagrams in a String

## 📋 Problem Description

**Problem Number**: 438  
**Difficulty**: Medium  
**LeetCode Link**: [Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string/)  
**Topics**: Hash Table, String, Sliding Window  

---

### Problem Statement

Given two strings `s` and `p`, return an array of all the start indices of `p`'s **anagrams** in `s`. You may return the answer in **any order**.

---

### Examples

#### Example 1
**Input**: `s = "cbaebabacd", p = "abc"`  
**Output**: `[0,6]`  
**Explanation**:
- The substring with start index = 0 is "cba", which is an anagram of "abc".
- The substring with start index = 6 is "bac", which is an anagram of "abc".

#### Example 2
**Input**: `s = "abab", p = "ab"`  
**Output**: `[0,1,2]`  
**Explanation**:
- The substring with start index = 0 is "ab", which is an anagram of "ab".
- The substring with start index = 1 is "ba", which is an anagram of "ab".
- The substring with start index = 2 is "ab", which is an anagram of "ab".

---

### Constraints

- `1 <= s.length, p.length <= 3 * 10^4`
- `s` and `p` consist of lowercase English letters.

---

## 💡 Approach

### Key Insight

Since an anagram is simply a permutation of a string, two strings are anagrams if and only if their character frequencies are identical. Because we are looking for anagrams of `p` within `s`, the window size is **fixed** to `p.length()`.



### Algorithm

1. **Requirement Mapping**: Create a frequency array `need` for string `p`.
2. **Fixed Window**: 
   - Use a `window` frequency array to track characters in the current segment of `s`.
   - Iterate with pointer `j`. Increment `window[s[j]]`.
3. **Slide and Shrink**:
   - If the current window size `j - i + 1` exceeds `p.length()`, decrement the count of `s[i]` in the `window` array and increment `i`.
4. **Comparison**:
   - When the window size exactly matches `p.length()`, compare the `need` array with the `window` array.
   - If `need == window`, the current window is an anagram; push the start index `i` into the result vector.

---

## ⚡ Complexity Analysis

### Time Complexity: **O(N)**
- We traverse string `s` once. The vector comparison `need == window` takes $O(256)$, which is a constant time operation $O(1)$.

### Space Complexity: **O(1)**
- We use two fixed-size frequency arrays of size 256, which does not grow with the input size.

---

**Pattern**: Sliding Window (Fixed Size)  
**Date Solved**: January 9, 2026
