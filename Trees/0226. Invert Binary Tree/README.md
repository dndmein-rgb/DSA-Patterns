# 226. Invert Binary Tree

**Difficulty:** Easy  
**LeetCode:** [Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/)  
**Pattern:** Tree Traversal (BFS / Level Order)

---

## 📌 Problem Statement

Given the `root` of a binary tree, invert the tree and return its root.

Inversion means:
- For every node, its left and right children are swapped.
- This must happen recursively down the entire tree.



---

## 🧠 Core Insight

This is a **structural transformation**.  
The values of the nodes do not change; only the **pointers** (the links to children) are swapped.

Whether you use DFS (Recursion) or BFS (Queue), the goal is the same:
- Visit every node.
- Swap `node->left` with `node->right`.

---

## ❗ Critical Logic (The Swap)

Many people think you just swap the leaf nodes. You don't.
- You swap the **entire subtrees**.
- When you swap the left and right pointers of a parent, everything attached to those pointers moves with them.
- You must visit every node to ensure their internal children are also mirrored.

---

## 🛠️ Algorithm (Iterative BFS)

1. **Check Base Case**: If root is `nullptr`, return `nullptr`.
2. **Initialize Queue**: Push the `root` into the queue.
3. **Traverse (Level Order)**:
    - Pop the front `node`.
    - **Swap**: `std::swap(node->left, node->right)`.
    - **Expand**: If `node->left` exists, push to queue. If `node->right` exists, push to queue.
4. **Result**: Once the queue is empty, the entire tree is mirrored. Return the `root`.



---

## 🧪 Dry Run

```text
Input: [4, 2, 7, 1, 3, 6, 9]

1. Pop 4: Swap (2, 7) -> Children are now [7, 2]. Queue: [7, 2]
2. Pop 7: Swap (6, 9) -> Children are now [9, 6]. Queue: [2, 9, 6]
3. Pop 2: Swap (1, 3) -> Children are now [3, 1]. Queue: [9, 6, 3, 1]
4. Pop 9, 6, 3, 1: No children to swap.

Result: [4, 7, 2, 9, 6, 3, 1]   


⏱️ Complexity
Time: O(N) — Every node is visited and swapped exactly once.

Space: O(W) — Where W is the maximum width of the tree. In a full binary tree, the queue holds up to N/2 nodes at the lowest level.

✅ Key Takeaways
Binary tree inversion is a classic Level Order Traversal application.

Iterative BFS is often safer than recursion for extremely deep trees to avoid Stack Overflow.

The swap operation in C++ handles the pointer exchange cleanly in O(1) time.

If you see "mirror a tree," your brain should jump straight to swapping child pointers during traversal.
