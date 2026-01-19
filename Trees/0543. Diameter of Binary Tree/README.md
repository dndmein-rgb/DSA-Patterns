# 543. Diameter of Binary Tree

**Problem Link:** [LeetCode – Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/)

---

## 🧩 Problem Description

Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path
between any two nodes in the tree.

This path may or may not pass through the root.

The length is measured by the number of **edges** between nodes.

---

## 📥 Examples

### Example 1

Input:
    1
   / \
  2   3
 / \
4   5

Output:
3

Explanation:
The longest path is 4 → 2 → 1 → 3.
This path contains 3 edges.

---

### Example 2

Input:
    1
     \
      2

Output:
1

---

## 🧠 Core Idea

At every node, the longest path that passes through it is:

depth(left subtree) + depth(right subtree)

The diameter of the tree is the maximum such value across all nodes.

So we:
- Use DFS to compute subtree heights
- Update a global diameter while unwinding recursion

---

## 🔍 Approach (DFS)

1. If the node is null, return height 0
2. Recursively compute left subtree height
3. Recursively compute right subtree height
4. Update diameter using `left + right`
5. Return height as `1 + max(left, right)`

Height is returned upward.
Diameter is tracked globally.

---

## ⏱️ Complexity Analysis

- Time Complexity: O(n)
  Every node is visited once.

- Space Complexity: O(h)
  Due to recursion stack, where h is the height of the tree.
  Worst case O(n) for a skewed tree.

---

## 🚨 Common Mistakes

- Returning number of nodes instead of edges
- Updating diameter with `1 + left + right`
- Trying to compute diameter only at the root
- Confusing height with diameter

---

## ✅ Final Takeaway

This problem tests whether you understand the difference between:
- Height (returned upward)
- Diameter (global best)

If you mix those up, you fail.
You didn’t.

This is a correct, interview-grade solution.
