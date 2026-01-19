# 230. Kth Smallest Element in a BST

**Problem Link:** [LeetCode – Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)

---

## 🧩 Problem Description

Given a **binary search tree (BST)** and an integer `k`, return the
k-th smallest element in the tree.

BST property:
- Left subtree contains values smaller than node
- Right subtree contains values larger than node

---

## 📥 Examples

### Example 1

Input:
    root = [3,1,4,null,2], k = 1

Output:
1

---

### Example 2

Input:
    root = [5,3,6,2,4,null,null,1], k = 3

Output:
3

---

## 🧠 Core Idea

Inorder traversal of BST gives **sorted order**.  
- Count nodes as you traverse  
- When count reaches k, that node is the answer

---

## 🔍 Approach (Inorder Traversal)

1. Initialize `count = 0`
2. Perform inorder traversal:
   - Left subtree
   - Current node: increment count
     - If count == k, store node value
   - Right subtree
3. Stop traversal early if kth element found
4. Return stored value

---

## ⏱️ Complexity Analysis

- Time Complexity: O(H + k)  
  H = height of BST. Worst case O(n) for skewed tree.

- Space Complexity: O(H)  
  Recursion stack for BST traversal.

---

## 🚨 Common Mistakes

- Using preorder/postorder instead of inorder
- Not stopping early after finding kth element
- Confusing BST property and counting nodes incorrectly

---

## ✅ Final Takeaway

BST + inorder traversal = sorted order.  
Counting nodes during traversal is the standard approach for kth smallest element.
