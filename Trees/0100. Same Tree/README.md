# 100. Same Tree

**Problem Link:** [LeetCode – Same Tree](https://leetcode.com/problems/same-tree/)

---

## 🧩 Problem Description

Given the roots of two binary trees `p` and `q`, determine whether
they are the same.

Two binary trees are considered the same if:
- They have the same structure
- Corresponding nodes have the same values

---

## 📥 Examples

### Example 1

Input:
    p = [1,2,3]
    q = [1,2,3]

Output:
true

---

### Example 2

Input:
    p = [1,2]
    q = [1,null,2]

Output:
false

---

### Example 3

Input:
    p = [1,2,1]
    q = [1,1,2]

Output:
false

---

## 🧠 Core Idea

Two trees are the same if:
- Both nodes are null, or
- Both nodes are non-null, have the same value, and
  their left subtrees are the same and their right subtrees are the same

This definition maps directly to a recursive solution.

---

## 🔍 Approach (DFS)

At each step:
1. If either node is null, return whether both are null
2. If values differ, return false
3. Recursively compare left children
4. Recursively compare right children

If all checks pass, the trees are identical.

---

## ⏱️ Complexity Analysis

- Time Complexity: O(n)
  Each node in both trees is visited once.

- Space Complexity: O(h)
  Due to recursion stack, where h is the height of the tree.
  Worst case O(n) for a skewed tree.

---

## 🚨 Common Mistakes

- Comparing only values and ignoring structure
- Returning true when one node is null and the other is not
- Forgetting to recurse on both left and right subtrees

---

## ✅ Final Takeaway

This problem is a pure structural comparison.

If you:
- Check nulls correctly
- Compare values
- Recurse symmetrically

You solve it.

Your solution does exactly that.
