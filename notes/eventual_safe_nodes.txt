# Eventual Safe States

A node in a directed graph is called **safe** if every possible path starting
from that node eventually leads to a terminal node (a node with no outgoing edges).
If a node can reach a cycle, it is **not safe**.

---

## Approach 1: DFS + Cycle Detection

### Idea
- Use DFS to detect cycles in the graph
- Maintain:
  - `vis[]` → whether a node has been visited
  - `pathVis[]` → whether a node is in the current DFS recursion stack
- If during DFS we encounter a node already in `pathVis`, a cycle exists
- Nodes that do not lead to any cycle are marked as safe

### Steps
1. Run DFS from every unvisited node
2. If a cycle is detected, mark the path nodes as unsafe
3. If DFS finishes without finding a cycle, mark the node as safe

### Time & Space
- **Time Complexity:** `O(V + E)`
- **Space Complexity:** `O(V)`

---

## Approach 2: Kahn’s Algorithm (Topological Sort)

### Idea
- Reverse all edges in the graph
- Nodes with indegree `0` in the reversed graph are safe
- Use Kahn’s BFS-based topological sorting

### Steps
1. Reverse the graph
2. Compute indegree of each node
3. Push nodes with indegree `0` into a queue
4. Process nodes using BFS and reduce indegrees
5. All processed nodes are safe

### Time & Space
- **Time Complexity:** `O(V + E)`
- **Space Complexity:** `O(V + E)`

---

## Comparison

| DFS Approach | Kahn’s Algorithm |
|--------------|-----------------|
| Recursive | Iterative |
| Good for understanding cycles | Cleaner & safer |
| Stack overflow risk | No recursion |
| More bookkeeping | More intuitive for DAG logic |

**Preferred in interviews:** Kahn’s Algorithm

---

## Key Takeaway
A node is safe **if and only if** it does not reach any cycle.
Both DFS cycle detection and topological sorting can be used
to identify such nodes efficiently.

