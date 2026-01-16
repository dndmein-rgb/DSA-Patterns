# 0127. Word Ladder

## Problem
Given two words `beginWord` and `endWord`, and a dictionary `wordList`,
return the length of the shortest transformation sequence from `beginWord`
to `endWord`.

Rules:
- Only one letter can be changed at a time
- Each transformed word must exist in `wordList`
- All words have the same length
- Return `0` if no transformation is possible

---

## Approach: Breadth-First Search (BFS)

This solution models the problem as a graph:
- Each word is a node
- An edge exists between two words if they differ by exactly one character

BFS is used because:
- All edges have equal weight
- BFS guarantees the shortest path in an unweighted graph

---

## Algorithm Steps

1. Insert all dictionary words into an `unordered_set` for O(1) lookup
2. Start BFS from `beginWord`
3. For each word:
   - Change one character at a time (`a` to `z`)
   - If the new word exists in the set, push it into the queue
   - Remove it from the set to avoid revisiting
4. Increase level count after each BFS layer
5. Return the level when `endWord` is found

---

## Example

### Input
