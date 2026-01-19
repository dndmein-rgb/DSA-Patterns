# 105. Construct Binary Tree from Preorder and Inorder Traversal

**Problem Link:** [LeetCode – Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

---

## 🧩 Problem Description

Given two integer arrays `preorder` and `inorder` where `preorder` is the preorder traversal
of a binary tree and `inorder` is the inorder traversal, construct and return the binary tree.

---

## 📥 Examples

### Example 1

Input:
preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]

Output:
Root of the tree:
        3
       / \
      9  20
         / \
        15  7

---

### Example 2

Input:
preorder = [-1], inorder = [-1]

Output:
Root of the tree: -1

---

## 🧠 Core Idea

- Preorder gives the **root** of the subtree
- Inorder divides the tree into **left and right subtrees**
- Use recursion to construct left and right

To speed up lookup of root in inorder, use a **hash map**.

---

## 🔍 Approach (Recursive with Hash Map)

1. Build a hash map of value → index for inorder
2. For a subtree:
   - Root = preorder[preorderStart]
   - Index of root in inorder = map[root]
   - Number of nodes in left subtree = inRoot - inorderStart
3. Recursively build left and right subtrees with correct indices
4. Return constructed root

---

## ⏱️ Complexity Analysis

- Time Complexity: O(n)  
  Each node is processed once, O(1) lookup in hash map

- Space Complexity: O(n)  
  Hash map + recursion stack (O(n) worst case)

---

## 🚨 Common Mistakes

- Using `find()` on inorder instead of hash map → O(n²)
- Incorrect indices for left/right subtrees
- Forgetting base case for recursion
- Miscounting nodes in left subtree

---

## ✅ Final Takeaway

This is a **classic tree construction problem**:

- Preorder gives root
- Inorder partitions tree
- Hash map avoids linear search
- Recursion builds subtrees cleanly
