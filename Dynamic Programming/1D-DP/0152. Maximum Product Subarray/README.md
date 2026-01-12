# 152. Maximum Product Subarray

## 📋 Problem Description
**Problem Number**: 152  
**Difficulty**: Medium  
**LeetCode Link**: [Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/)  
**Pattern**: Dynamic Programming / Kadane's Algorithm

---

### Problem Statement
Given an integer array `nums`, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

---

### 📝 Examples

**Example 1:**
* **Input**: `nums = [2, 3, -2, 4]`
* **Output**: `6`
* **Explanation**: `[2, 3]` has the largest product `6`.

**Example 2:**
* **Input**: `nums = [-2, 0, -1]`
* **Output**: `0`
* **Explanation**: The result cannot be `2` because `[-2, -1]` is not a contiguous subarray.

---

## 💡 Implementation Strategies

### 1. Brute Force ($O(N^2)$)
Check every possible subarray `(i, j)` and calculate its product.
* **Logic**: Use a nested loop where the outer loop marks the start and the inner loop calculates the product to the end.
* **Drawback**: Inefficient for large arrays; recalculates products repeatedly.

### 2. Optimized DP ($O(N)$)
We maintain both a `maxProduct` and a `minProduct` ending at the current position. 



* **The Swap Trick**: When we encounter a negative number, the `maxProduct` becomes a very small number and the `minProduct` (if negative) becomes a very large number. We **swap** them before multiplying to keep the tracking accurate.
* **Decisions**: At each element, we decide to either start a new subarray (`x`) or extend the existing one (`x * maxProd`).



---

## ⚡ Complexity Comparison

| Feature | Brute Force | Optimized DP |
| :--- | :--- | :--- |
| **Time Complexity** | $O(N^2)$ | $O(N)$ |
| **Space Complexity** | $O(1)$ | $O(1)$ |
| **Efficiency** | Low (Potential TLE) | High (Optimal) |

---
**Date Solved**: January 12, 2026
