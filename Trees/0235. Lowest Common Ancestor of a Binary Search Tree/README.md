# 235. Lowest Common Ancestor of a Binary Search Tree

**Problem Link:** [LeetCode – Lowest Common Ancestor of a BST](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)

---

## 🧩 Problem Description

Given a binary search tree (BST), find the lowest common ancestor (LCA)
of two given nodes `p` and `q`.

The lowest common ancestor is defined as the lowest node in the tree
that has both `p` and `q` as descendants (where a node can be a
descendant of itself).

---

## 📥 Examples

### Example 1

Input:
root = [6,2,8,0,4,7,9,null,null,3,5]
p = 2
q = 8

Output:
6

---

### Example 2

Input:
root = [6,2,8,0,4,7,9,null,null,3,5]
p = 2
q = 4

Output:
2

---

## 🧠 Core Idea

This problem works because the tree is a **Binary Search Tree**.

In a BST:
- Left subtree values < root value
- Right subtree values > root value

So:
- If both `p` and `q` are smaller than the current node,
  LCA must be in the left subtree
- If both are larger, LCA must be in the right subtree
- Otherwise, the current node is the split point — the LCA

---

## 🔍 Approach (BST Property)

1. Start from the root
2. Compare `p->val` and `q->val` with current node value
3. Move left if both are smaller
4. Move right if both are larger
5. If they diverge, current node is the LCA

This avoids unnecessary traversal.

---

## ⏱️ Complexity Analysis

- Time Complexity: O(h)
  Where h is the height of the BST

- Space Complexity: O(h)
  Due to recursion stack
  Worst case O(n) for a skewed tree

---

## 🚨 Common Mistakes

- Using this approach for a non-BST (it will fail)
- Traversing both subtrees unnecessarily
- Forgetting that a node can be its own ancestor
- Confusing BST LCA with general binary tree LCA

---

## ✅ Final Takeaway

This problem is trivial **only if** you respect the BST property.

You did:
- Correct comparisons
- Correct stopping condition
- Correct recursion

This is exactly how BST problems should be solved.
