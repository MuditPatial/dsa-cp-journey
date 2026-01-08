# Shortest Path in an Unweighted Graph (BFS)

## Problem
Given an undirected, unweighted graph and a source node `src`, find the
shortest distance from the source to all other vertices. If a vertex is
not reachable from the source, its distance should be `-1`.

---

## Hints
1. In an unweighted graph, the shortest path depends only on the number of edges.
2. Breadth First Search (BFS) explores nodes level by level.
3. The first time a node is visited in BFS gives its shortest distance.

---

## Logic
The graph is first converted into an adjacency list for efficient traversal.
Breadth First Search (BFS) is then performed starting from the source node.

A queue is used to process nodes level by level, where each level represents
the distance from the source. When a node is visited for the first time, its
distance is fixed and it is marked as visited to avoid reprocessing. Since
all edges have equal weight, BFS guarantees that the shortest path to each
node is found.

Nodes that are never visited during BFS are unreachable and are assigned
a distance of `-1`.

---

## Time and Space Complexity
- **Time Complexity:** `O(V + E)`
- **Space Complexity:** `O(V + E)`
