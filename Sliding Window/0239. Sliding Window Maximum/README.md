# 239. Sliding Window Maximum

## 📋 Problem Description

**Problem Number**: 239  
**Difficulty**: Hard  
**LeetCode Link**: [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/)  
**Topics**: Array, Queue, Sliding Window, Heap (Priority Queue), Monotonic Deque  

---

### Problem Statement

You are given an array of integers `nums`, there is a sliding window of size `k` which is moving from the very left of the array to the very right. You can only see the `k` numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

---

### Examples

#### Example 1
**Input**: `nums = [1,3,-1,-3,5,3,6,7], k = 3`  
**Output**: `[3,3,5,5,6,7]`

#### Example 2
**Input**: `nums = [1], k = 1`  
**Output**: `[1]`

---

## 💡 Approaches

### 1. Priority Queue (Max-Heap) — O(N log N)
We use a max-heap to keep track of the largest element. Since the heap doesn't support efficient removal of elements that aren't at the top, we use **Lazy Deletion**:
- Store pairs of `{value, index}` in the heap.
- Check the top of the heap; if its index is outside the current window range `(i - k)`, pop it.
- The top element is now guaranteed to be the maximum of the current valid window.

### 2. Monotonic Deque — O(N) [Optimal]
We use a `deque` to maintain indices of elements in **strictly decreasing order**. This allows us to find the maximum in $O(1)$ time.



**The Logic:**
- **Remove Outdated**: If the index at the front of the deque is out of the window range, pop it.
- **Maintain Monotonicity**: Before adding a new element, remove all elements from the back of the deque that are smaller than the new element (as they can never be the maximum again).
- **Result**: The current maximum is always at `nums[dq.front()]`.

---

## ⚡ Complexity Comparison

| Feature | Priority Queue | Monotonic Deque |
|---------|----------------|-----------------|
| **Time Complexity** | $O(N \log N)$ | $O(N)$ |
| **Space Complexity** | $O(N)$ | $O(K)$ |
| **Efficiency** | Slower (Heap overhead) | Optimal (Linear scan) |

---

**Pattern**: Sliding Window (Fixed Size) / Monotonic Queue  
**Date Solved**: January 8, 2026
