# 239. Sliding Window Maximum

## 📋 Problem Description

**Problem Number**: 239  
**Difficulty**: Hard  
**LeetCode Link**: [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/)  
**Topics**: Array, Queue, Sliding Window, Heap (Priority Queue), Monotonic Queue  

---

### Problem Statement

You are given an array of integers `nums`, there is a sliding window of size `k` which is moving from the very left of the array to the very right. You can only see the `k` numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

---

### Examples

#### Example 1
**Input**: `nums = [1,3,-1,-3,5,3,6,7], k = 3`  
**Output**: `[3,3,5,5,6,7]`  
**Explanation**: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

#### Example 2
**Input**: `nums = [1], k = 1`  
**Output**: `[1]`

---

### Constraints

- `1 <= nums.length <= 10^5`
- `-10^4 <= nums[i] <= 10^4`
- `1 <= k <= nums.length`

---

## 💡 Approach

### Key Insight

To efficiently find the maximum in a sliding window, we need a way to track both the value and the index of elements. Using a **Priority Queue (Max-Heap)** allows us to always access the largest element at the top. However, since the window slides, the current maximum in the heap might actually be outside the window boundaries. We solve this by "lazily" removing elements from the top of the heap only when their index is no longer within the range `[i - k + 1, i]`.



### Algorithm

1. **Initialize**: Use a max-priority queue to store pairs of `{value, index}`.
2. **Iterate**: Loop through the array from `i = 0` to `n - 1`.
   - Push the current element `{nums[i], i}` into the priority queue.
   - **Lazy Deletion**: While the index of the element at the top of the heap is outside the current window (`top.second <= i - k`), pop the top element.
   - **Capture Maximum**: Once the loop index `i` reaches at least `k - 1`, the top of the heap is guaranteed to be the maximum for the current window. Append it to the result.

---

## ⚡ Complexity Analysis

### Time Complexity: **O(N log N)**
- In the worst case, we push every element into the priority queue. Each push/pop operation takes $O(\log N)$ time.

### Space Complexity: **O(N)**
- The priority queue can store up to $N$ elements in the worst case (e.g., an array sorted in ascending order).

---

**Pattern**: Sliding Window (Fixed Size) / Heap  
**Date Solved**: January 8, 2026
