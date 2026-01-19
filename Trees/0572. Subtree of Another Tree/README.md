# 572. Subtree of Another Tree

**Problem Link:** [LeetCode – Subtree of Another Tree](https://leetcode.com/problems/subtree-of-another-tree/)

---

## 🧩 Problem Description

Given the roots of two binary trees `root` and `subRoot`,
return true if there is a subtree of `root` that has the same
structure and node values as `subRoot`.

A subtree of a binary tree is a tree consisting of a node in `root`
and all of its descendants.

---

## 📥 Examples

### Example 1

Input:
root = [3,4,5,1,2]
subRoot = [4,1,2]

Output:
true

---

### Example 2

Input:
root = [3,4,5,1,2,null,null,null,null,0]
subRoot = [4,1,2]

Output:
false

---

## 🧠 Core Idea

To check whether `subRoot` is a subtree of `root`:

- Traverse every node in `root`
- At each node, check if the subtree rooted there is **identical**
  to `subRoot`

This reduces the problem to:
- Tree traversal
- Tree equality check

---

## 🔍 Approach (DFS + Tree Comparison)

1. Traverse `root` using DFS
2. At each node:
   - Check if the current subtree is identical to `subRoot`
3. If not identical:
   - Recursively check left and right subtrees
4. If any match is found, return true

Tree comparison is done using a recursive equality check.

---

## ⏱️ Complexity Analysis

- Time Complexity: O(n × m) in the worst case  
  Where:
  - `n` = number of nodes in `root`
  - `m` = number of nodes in `subRoot`

- Space Complexity: O(h)
  Recursion stack, where h is the height of `root`

---

## 🚨 Common Mistakes

- Comparing only values and ignoring structure
- Forgetting to check every node in `root`
- Returning true when only partial structure matches
- Treating this as a string problem prematurely

---

## ✅ Final Takeaway

This problem is about **composition**:
- Use one function to compare trees
- Use another to traverse and apply the comparison

Your solution does exactly that.

There are faster approaches (serialization, hashing),
but this one is the correct foundation.
