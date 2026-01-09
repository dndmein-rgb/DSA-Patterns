# 1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold

## 📋 Problem Description

**Problem Number**: 1343  
**Difficulty**: Medium  
**LeetCode Link**: [Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold](https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/)  
**Topics**: Array, Sliding Window  

---

### Problem Statement

Given an array of integers `arr` and two integers `k` and `threshold`, return the number of sub-arrays of size `k` and average greater than or equal to `threshold`.

---

### Examples

#### Example 1
**Input**: `arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4`  
**Output**: `3`  
**Explanation**: Sub-arrays [2,5,5], [5,5,5] and [5,5,8] have averages 4, 5 and 6 respectively. All other sub-arrays of size 3 have averages less than 4.

#### Example 2
**Input**: `arr = [11,13,17,23,29,31,7,5,2,3], k = 3, threshold = 5`  
**Output**: `6`  
**Explanation**: The first 6 sub-arrays of size 3 have averages greater than 5.

---

### Constraints

- `1 <= arr.length <= 10^5`
- `1 <= arr[i] <= 10^4`
- `1 <= k <= arr.length`
- `0 <= threshold <= 10^4`

---

## 💡 Approach

### Key Insight

Since we are looking for a contiguous sub-array of a specific length `k`, this is a **Fixed-Size Sliding Window** problem. To avoid floating-point issues and improve efficiency, we convert the average condition:
$\frac{Sum}{k} \ge Threshold \implies Sum \ge Threshold \times k$.



### Algorithm

1. **Initialize**: 
   - `sum`: To maintain the sum of elements in the current window.
   - `count`: To store the number of valid sub-arrays found.
   - `i`: The left pointer of the window.
2. **Expand**: Iterate through the array with a right pointer `j`. Add `arr[j]` to `sum`.
3. **Slide**: 
   - If the window size `j - i + 1` exceeds `k`, remove `arr[i]` from the `sum` and increment `i`.
4. **Evaluate**: 
   - When the window size is exactly `k`, check if `sum >= threshold * k`. If true, increment `count`.
5. **Return**: The final `count`.

---

## ⚡ Complexity Analysis

### Time Complexity: **O(n)**
- We traverse the array once with the right pointer `j`. Every element is added and subtracted exactly once.

### Space Complexity: **O(1)**
- We only use a constant amount of extra space for integer variables.

---

**Pattern**: Sliding Window (Fixed Size)  
**Date Solved**: January 9, 2026
