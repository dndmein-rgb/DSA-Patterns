# 1448. Count Good Nodes in Binary Tree

**Problem Link:** [LeetCode – Count Good Nodes in Binary Tree](https://leetcode.com/problems/count-good-nodes-in-binary-tree/)

---

## 🧩 Problem Description

Given a binary tree `root`, a node is **good** if in the path from the root
to that node there are no nodes with a **value greater than the node itself**.

Return the number of good nodes in the binary tree.

---

## 📥 Examples

### Example 1

Input:
    3
   / \
  1   4
 /   / \
3   1   5

Output:
4

Explanation:
The good nodes are 3 (root), 3, 4, 5

---

### Example 2

Input:
root = [3,3,null,4,2]

Output:
3

---

### Example 3

Input:
root = [1]

Output:
1

---

## 🧠 Core Idea

A node is good if its value ≥ the maximum value along the path from root.

- Keep track of the current path maximum while traversing
- If current node ≥ max, increment count
- Recurse into left and right subtrees with updated max

---

## 🔍 Approach (DFS)

1. Start DFS from the root
2. Pass along the current max value in the path
3. If node's value ≥ max, count it as good
4. Update max if necessary
5. Recursively check left and right children
6. Sum counts and return

---

## ⏱️ Complexity Analysis

- Time Complexity: O(n)  
  Each node is visited once.

- Space Complexity: O(h)  
  Recursion stack, where h is tree height. Worst case O(n) for skewed tree.

---

## 🚨 Common Mistakes

- Resetting max incorrectly for child nodes
- Forgetting to count the root
- Counting nodes where path has larger values already

---

## ✅ Final Takeaway

This problem is a **path-aware DFS** problem.

Track maximum along the path, count when condition satisfies,
and propagate correctly. Your solution does exactly that.
