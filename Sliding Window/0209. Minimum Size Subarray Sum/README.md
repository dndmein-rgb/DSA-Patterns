# 209. Minimum Size Subarray Sum

## 📋 Problem Description

**Problem Number**: 209  
**Difficulty**: Medium  
**LeetCode Link**: [Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/)  
**Topics**: Array, Binary Search, Sliding Window, Prefix Sum  

---

### Problem Statement

Given an array of positive integers `nums` and a positive integer `target`, return the **minimal length** of a contiguous subarray of which the sum is greater than or equal to `target`. If there is no such subarray, return `0` instead.

---

### Examples

#### Example 1
**Input**: `target = 7, nums = [2,3,1,2,4,3]`  
**Output**: `2`  
**Explanation**: The subarray [4,3] has the minimal length under the problem constraint.

#### Example 2
**Input**: `target = 4, nums = [1,4,4]`  
**Output**: `1`

#### Example 3
**Input**: `target = 11, nums = [1,1,1,1,1,1,1,1]`  
**Output**: `0`

---

### Constraints

- `1 <= target <= 10^9`
- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^4`

---

## 💡 Approach

### Key Insight

Since all elements in the array are positive, the window sum increases as we expand the right pointer. This allows us to use a **Variable Size Sliding Window**. We expand the window until the sum meets the target, then contract it as much as possible from the left to find the "minimal" length while still satisfying the condition.



### Algorithm

1. **Initialize**: 
   - `currSum`: Tracks the sum of the current window.
   - `minLen`: Tracks the minimum length found (initialized to `n + 1`).
   - `i`: Left pointer of the window.
2. **Expand**: Move the right pointer `j` from `0` to `n-1`, adding `nums[j]` to `currSum`.
3. **Contract**: While `currSum >= target`:
   - Update `minLen` with `min(minLen, j - i + 1)`.
   - Subtract `nums[i]` from `currSum` and increment `i`.
4. **Result**: If `minLen` remains `n + 1`, no valid subarray was found; return `0`. Otherwise, return `minLen`.

---

## ⚡ Complexity Analysis

### Time Complexity: **O(n)**
- Each element is visited at most twice: once by the right pointer `j` and once by the left pointer `i`.

### Space Complexity: **O(1)**
- We only use constant extra space for pointers and sum variables.

---

**Pattern**: Sliding Window (Variable Size)  
**Date Solved**: January 9, 2026
