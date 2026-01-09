# 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit

## 📋 Problem Description

**Problem Number**: 1438  
**Difficulty**: Medium  
**LeetCode Link**: [Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit](https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/)  
**Topics**: Array, Queue, Sliding Window, Deque, Monotonic Queue, Heap  

---

### Problem Statement

Given an array of integers `nums` and an integer `limit`, return the size of the longest **non-empty** subarray such that the absolute difference between any two elements of this subarray is less than or equal to `limit`.

---

### Examples

#### Example 1
**Input**: `nums = [8,2,4,7], limit = 4`  
**Output**: `2`  
**Explanation**: All subarrays are: 
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4. 
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[7] with maximum absolute diff |7-7| = 0 <= 4. 
The maximum length is 2.

#### Example 2
**Input**: `nums = [10,1,2,4,7,2], limit = 5`  
**Output**: `4`  
**Explanation**: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |7-2| = 5 <= 5.

---

### Constraints

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^9`
- `0 <= limit <= 10^9`

---

## 💡 Approaches

### 1. Monotonic Deque (Optimal)
To keep track of the maximum and minimum elements in the current sliding window efficiently, we use two deques:
- **`maxDQ`**: Stores indices of elements in a strictly decreasing order.
- **`minDQ`**: Stores indices of elements in a strictly increasing order.



**Algorithm**:
1. Expand the right pointer `j` and update both deques.
2. If `nums[maxDQ.front()] - nums[minDQ.front()] > limit`, the window is invalid.
3. Shrink the window by moving the left pointer `i` and popping from deques if the front index matches `i`.
4. The maximum `j - i + 1` is the result.

### 2. Priority Queue (Heaps)
- Use a Max-Heap and a Min-Heap to store `{value, index}`.
- Use **Lazy Deletion**: Pop the top of the heaps if their indices are smaller than the current left pointer `i`.
- Shrink `i` until the difference between the top of both heaps $\le$ `limit`.

---

## ⚡ Complexity Analysis

| Feature | Monotonic Deque | Priority Queue |
|---------|----------------|----------------|
| **Time Complexity** | $O(N)$ | $O(N \log N)$ |
| **Space Complexity** | $O(N)$ | $O(N)$ |

---

**Pattern**: Sliding Window (Variable Size) / Monotonic Queue  
**Date Solved**: January 9, 2026
