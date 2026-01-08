# Shortest Path in a Directed Acyclic Graph (DAG)

## Problem
Given a directed graph with weighted edges that forms a **DAG**, find the
shortest distance from the source node (node `0`) to all other nodes.
If a node is not reachable from the source, its distance should be `-1`.

---

## Hints
1. Since the graph is acyclic, nodes can be arranged in a topological order.
2. Once a node is processed, its shortest distance will never change.
3. Relaxing edges in topological order guarantees correct distances.

---

## Logic
The solution uses **topological sorting followed by edge relaxation**.
A DFS is used to generate a topological order of the nodes, which is stored
in a stack. After computing the order, distances are initialized with a
large value except for the source node, which is set to zero.

Nodes are then processed in topological order, and for each node, all its
outgoing edges are relaxed. Because the graph has no cycles, each node is
visited only after all possible shorter paths to it have already been
considered. Finally, nodes that remain unreachable are assigned a distance
of `-1`.

---

## Time and Space Complexity
- **Time Complexity:** `O(V + E)`
- **Space Complexity:** `O(V + E)`
