# 904. Fruit Into Baskets

## 📋 Problem Description

**Problem Number**: 904  
**Difficulty**: Medium  
**LeetCode Link**: [Fruit Into Baskets](https://leetcode.com/problems/fruit-into-baskets/)  
**Topics**: Array, Hash Table, Sliding Window  

---

### Problem Statement

You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array `fruits` where `fruits[i]` is the **type** of fruit the $i^{th}$ tree produces.

You have **two baskets**, and each basket can only hold a **single type** of fruit. There is no limit on the amount of fruit each basket can hold.

Starting from any tree of your choice, you must pick **exactly one fruit** from every tree (including the start tree) while moving to the right. The picking process must stop when you reach a tree with a fruit type that cannot fit in your baskets.

Return the **maximum** number of fruits you can pick.

---

### Examples

#### Example 1
**Input**: `fruits = [1,2,1]`  
**Output**: `3`  
**Explanation**: We can pick from all 3 trees.

#### Example 2
**Input**: `fruits = [0,1,2,2]`  
**Output**: `3`  
**Explanation**: We can pick from trees [1,2,2]. If we had started at tree 0, we would only pick [0,1].

---

### Constraints

- `1 <= fruits.length <= 10^5`
- `0 <= fruits[i] < fruits.length`

---

## 💡 Approach

### Key Insight

This problem is a variation of the **Longest Substring with at most K Distinct Characters**, where $K=2$. We need to find the longest contiguous subarray that contains at most two unique integers.



### Algorithm

1. **Frequency Tracking**: Use an `unordered_map` to store the types of fruits currently in our baskets and their respective counts.
2. **Expand Window**: Move the right pointer `j` to include the next tree. Increment its count in the map.
3. **Shrink Window**: If the number of unique fruit types (map size) exceeds 2:
   - Decrement the count of the fruit at the left pointer `i`.
   - If that fruit's count reaches 0, remove it from the map.
   - Increment `i` until the map size is back to 2.
4. **Update Result**: At each step where the window is valid (size $\le 2$), update `maxLen` with `j - i + 1`.

---

## ⚡ Complexity Analysis

### Time Complexity: **O(n)**
- Both pointers `i` and `j` travel across the array at most once.

### Space Complexity: **O(1)**
- Although we use a map, it stores a maximum of 3 key-value pairs at any given time, which is constant space.

---

**Pattern**: Sliding Window (Variable Size)  
**Date Solved**: January 9, 2026
