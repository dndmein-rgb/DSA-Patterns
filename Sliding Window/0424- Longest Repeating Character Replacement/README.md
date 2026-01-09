# 424. Longest Repeating Character Replacement

## 📋 Problem Description

**Problem Number**: 424  
**Difficulty**: Medium  
**LeetCode Link**: [Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/)  
**Topics**: Hash Table, String, Sliding Window  

---

### Problem Statement

You are given a string `s` and an integer `k`. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most `k` times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

---

### Examples

#### Example 1
**Input**: `s = "ABAB", k = 2`  
**Output**: `4`  
**Explanation**: Replace the two 'A's with two 'B's or vice versa.

#### Example 2
**Input**: `s = "AABABBA", k = 1`  
**Output**: `4`  
**Explanation**: Replace the middle 'A' with 'B' to form "AABBBBA". The substring "BBBB" has the longest repeating character, which is 4.

---

### Constraints

- `1 <= s.length <= 10^5`
- `s` consists of only uppercase English letters.
- `0 <= k <= s.length`

---

## 💡 Approach

### Key Insight

A window is valid if the number of characters we need to replace is less than or equal to `k`.  
Mathematically: `(Window Length - Frequency of Most Frequent Character) <= k`.



### Algorithm

1. **Frequency Map**: Use a hash map or an array of size 26 to track character counts in the current window.
2. **Track Max Frequency**: Maintain `maxFreq`, the count of the most frequent character seen in the current window.
3. **Sliding Window**:
   - Expand the right pointer `j` and update the frequency of `s[j]`.
   - Update `maxFreq` with `max(maxFreq, freq[s[j]])`.
   - While `(j - i + 1) - maxFreq > k`, the window is invalid. Shrink it by moving the left pointer `i` and decrementing `freq[s[i]]`.
4. **Result**: The answer is the maximum value of `j - i + 1` recorded during the process.

---

## ⚡ Complexity Analysis

### Time Complexity: **O(n)**
- We traverse the string with the right pointer once, and the left pointer moves forward at most $n$ times.

### Space Complexity: **O(1)**
- The frequency map size is capped at 26 (uppercase English letters), which is constant space.

---

**Pattern**: Sliding Window (Variable + Frequency Tracking)  
**Date Solved**: January 8, 2026
