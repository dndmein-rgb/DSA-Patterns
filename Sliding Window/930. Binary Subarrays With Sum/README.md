# 930. Binary Subarrays With Sum

## 📋 Problem Description

**Problem Number**: 930  
**Difficulty**: Medium  
**LeetCode Link**: [Binary Subarrays With Sum](https://leetcode.com/problems/binary-subarrays-with-sum/)  
**Level**: 🧪 Level 5: Non-obvious sliding window (The "At Most K" Trick)

---

### Problem Statement

Given a binary array `nums` and an integer `goal`, return the number of non-empty subarrays with a sum equal to `goal`.

---

### Examples

#### Example 1
**Input**: `nums = [1,0,1,0,1], goal = 2`  
**Output**: `4`  
**Explanation**: The 4 subarrays are:
- `[1,0,1]`, 0
- `[1,0,1,0]`
- `[0,1,0,1]`
- `[1,0,1]` (starting at index 2)

#### Example 2
**Input**: `nums = [0,0,0,0,0], goal = 0`  
**Output**: `15`

---

## 💡 Approach: The "At Most K" Trick

In binary arrays, the sum of a subarray is simply the count of `1`s it contains. This makes the problem identical in logic to **992** (Distinct Integers) and **1248** (Nice Subarrays).



### Why use the "At Most" trick?
When `goal = 0` or when there are many zeros in the array, a simple sliding window struggles because moving the left pointer `i` might not change the sum (if `nums[i] == 0`). This "zero-latency" makes counting "Exactly K" directly very messy.

By using the subtraction method, we simplify the logic:
$$\text{Exactly}(\text{Goal}) = \text{AtMost}(\text{Goal}) - \text{AtMost}(\text{Goal} - 1)$$

### Mechanics
1. **Expand**: Add `nums[j]` to `sum`.
2. **Contract**: If `sum > goal`, shrink the window from the left until `sum <= goal`.
3. **Count**: Add the window size `j - i + 1` to the total. This represents all subarrays ending at `j` that satisfy the `atMost` condition.

---

## ⚡ Complexity Analysis

* **Time Complexity**: $O(N)$ — The array is traversed twice.
* **Space Complexity**: $O(1)$ — No extra data structures like HashMaps are needed since we only track the sum.

---

**Pattern**: Sliding Window (Variable Size) + Counting Trick  
**Date Solved**: January 10, 2026
