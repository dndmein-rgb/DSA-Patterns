# Best Time to Buy and Sell Stock

## 📋 Problem Description

**Problem Number**: 121  
**Difficulty**: Easy  
**LeetCode Link**: [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)  
**Topics**: Array, Dynamic Programming, Sliding Window  

---

### Problem Statement

You are given an array `prices` where `prices[i]` is the price of a given stock on the `ith` day.

You want to **maximize your profit** by choosing a **single day** to buy one stock and choosing a **different day in the future** to sell that stock.

Return the **maximum profit** you can achieve from this transaction. If you cannot achieve any profit, return `0`.

---

### Examples

#### Example 1
```
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
```

#### Example 2
```
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
```

---

### Constraints

- `1 <= prices.length <= 10^5`
- `0 <= prices[i] <= 10^4`

---

## 💡 Approach

### Key Insight

This is a **Sliding Window** problem where we dynamically adjust the start of our window (the buy day).

To maximize **Profit = Sell Price - Buy Price**, we need to:
- Keep the **Buy Price** as low as possible
- Check the profit for every subsequent **Sell Price**

### Algorithm (One-Pass Solution)

1. **Initialize Variables**:
   - `minVal`: Set to infinity (or a very large value) to track the lowest price seen so far
   - `maxPro`: Set to 0 to track the maximum profit found

2. **Iterate Through Prices**:
   - For each price:
     - Update `minVal` if the current price is lower than our current "buy" price
     - Calculate potential profit: `currentPrice - minVal`
     - Update `maxPro` if this profit is higher than any previously recorded profit

3. **Return Result**: 
   - The window effectively slides its starting point whenever a new minimum is found

---

## 🔍 Step-by-Step Walkthrough

**Input**: `prices = [7, 1, 5, 3, 6, 4]`

| Step | Price | minVal | Calculation | maxPro | Explanation |
|------|-------|--------|-------------|--------|-------------|
| 1 | 7 | 7 | 7 - 7 = 0 | 0 | First day, no profit yet |
| 2 | 1 | 1 | 1 - 1 = 0 | 0 | New minimum found! |
| 3 | 5 | 1 | 5 - 1 = 4 | 4 | Profit if we sell today |
| 4 | 3 | 1 | 3 - 1 = 2 | 4 | Lower profit, keep max |
| 5 | 6 | 1 | 6 - 1 = 5 | 5 | New maximum profit! |
| 6 | 4 | 1 | 4 - 1 = 3 | 5 | Lower profit, keep max |

**Result**: Maximum profit = 5 (Buy at 1, Sell at 6)

---

## ⚡ Complexity Analysis

### Time Complexity: **O(n)**
- We traverse the price array exactly once
- Each operation inside the loop takes O(1) time

### Space Complexity: **O(1)**
- We only use two integer variables (`minVal` and `maxPro`) regardless of input size
- No additional data structures are needed

---

## 🎯 Why This is a Sliding Window Problem

The **"window"** in this problem represents:
- **Left boundary**: The minimum price seen so far (best day to buy)
- **Right boundary**: The current price we're evaluating (potential day to sell)

The window **"slides"** because:
- The left boundary moves forward whenever we find a new minimum price
- The right boundary always moves forward as we iterate through the array
- We calculate profit for every valid window and keep track of the maximum

---

## 🔗 Related Problems

- [122. Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/) (Multiple Transactions)
- [123. Best Time to Buy and Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/) (At Most 2 Transactions)
- [188. Best Time to Buy and Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/) (At Most K Transactions)
- [309. Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)

---

## ⚠️ Common Mistakes

1. **Not handling the case where no profit is possible** - Always initialize `maxPro` to 0
2. **Trying to sell before buying** - The minimum must be updated before calculating profit
3. **Using nested loops** - This would result in O(n²) complexity, which is inefficient
4. **Not updating minimum correctly** - Always update `minVal` with the current price if it's lower

---

## 🏢 Companies

This problem has been asked by: **Amazon**, **Google**, **Microsoft**, **Facebook**, **Apple**, **Bloomberg**

---

**Pattern**: Sliding Window  
**Date Solved**: January 8, 2026

[← Back to Sliding Window](../README.md) | [View Solution Code](./solution.cpp)
