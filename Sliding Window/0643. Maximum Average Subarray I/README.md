# 643. Maximum Average Subarray I

## 📋 Problem Description

**Problem Number**: 643  
**Difficulty**: Easy  
**LeetCode Link**: [Maximum Average Subarray I](https://leetcode.com/problems/maximum-average-subarray-i/)  
**Topics**: Array, Sliding Window  

---

### Problem Statement

You are given an integer array `nums` consisting of `n` elements, and an integer `k`.

Find a contiguous subarray whose **length is equal to `k`** that has the maximum average value and return this value. Any answer with a calculation error less than $10^{-5}$ will be accepted.

---

### Examples

#### Example 1
**Input**: `nums = [1,12,-5,-6,50,3], k = 4`  
**Output**: `12.75000`  
**Explanation**: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75.

#### Example 2
**Input**: `nums = [5], k = 1`  
**Output**: `5.00000`

---

### Constraints

- `n == nums.length`
- `1 <= k <= n <= 10^5`
- `-10^4 <= nums[i] <= 10^4`

---

## 💡 Approach

### Key Insight

This is a classic **Fixed-Size Sliding Window** problem. To find the maximum average of a window of size `k`, we only need to find the **maximum sum** of a window of size `k`, as the divisor `k` remains constant. Using a sliding window allows us to calculate the sum of the next window in $O(1)$ time by adding the new element and removing the old one.



### Algorithm

1. **Initialize**: 
   - `sum`: To store the current window's sum.
   - `maxSum`: To store the highest sum encountered (initialized to a very small value).
2. **Expand and Slide**:
   - Iterate through the array with a right pointer `j`.
   - Add `nums[j]` to the current `sum`.
   - Once the window size exceeds `k`, subtract `nums[i]` (the element leaving the window) and increment the left pointer `i`.
   - Whenever the window size equals `k`, update `maxSum`.
3. **Calculate Average**: Return `maxSum` divided by `k` as a double.

---

## ⚡ Complexity Analysis

### Time Complexity: **O(n)**
- We traverse the array exactly once. Each element is added to and subtracted from the sum at most once.

### Space Complexity: **O(1)**
- We only use a few integer variables regardless of the input array size.

---

**Pattern**: Sliding Window (Fixed Size)  
**Date Solved**: January 9, 2026
