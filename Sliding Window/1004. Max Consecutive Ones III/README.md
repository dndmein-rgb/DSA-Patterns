# 1004. Max Consecutive Ones III

## 📋 Problem Description

**Problem Number**: 1004  
**Difficulty**: Medium  
**LeetCode Link**: [Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii/)  
**Topics**: Array, Binary Search, Sliding Window, Prefix Sum  

---

### Problem Statement

Given a binary array `nums` and an integer `k`, return the maximum number of consecutive `1`'s in the array if you can flip at most `k` `0`'s.

---

### Examples

#### Example 1
**Input**: `nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2`  
**Output**: `6`  
**Explanation**: [1,1,1,0,0,**1,1,1,1,1,1**]  
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

#### Example 2
**Input**: `nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3`  
**Output**: `10`  
**Explanation**: [0,0,**1,1,1,1,1,1,1,1,1,1**,0,0,0,1,1,1,1]  
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

---

### Constraints

- `1 <= nums.length <= 10^5`
- `nums[i]` is either `0` or `1`.
- `0 <= k <= nums.length`

---

## 💡 Approach

### Key Insight

The problem asks for the longest subarray containing at most `k` zeros. We can use a **Variable Size Sliding Window** to maintain a window that covers as many `1`s as possible while keeping the count of `0`s within the limit of `k`.



### Algorithm

1. **Initialize**: 
   - `i`, `j`: Left and right pointers for the sliding window.
   - `zeros`: Count of zeros currently inside the window.
   - `maxLen`: Maximum length of a valid window found so far.
2. **Expand**: Move the right pointer `j`. If `nums[j]` is `0`, increment the `zeros` count.
3. **Contract**: If `zeros` exceeds `k`, move the left pointer `i`. If `nums[i]` was a `0`, decrement the `zeros` count. Continue until `zeros <= k`.
4. **Update**: At each step, update `maxLen = max(maxLen, j - i + 1)`.
5. **Return**: The final `maxLen`.

---

## ⚡ Complexity Analysis

### Time Complexity: **O(n)**
- Each element is processed at most twice (once by the right pointer and once by the left pointer).

### Space Complexity: **O(1)**
- We only use a constant amount of extra space for counters and pointers.

---

**Pattern**: Sliding Window (Variable Size)  
**Date Solved**: January 9, 2026
