# Shortest Path in Binary Matrix

You are given an `n × m` binary matrix where:

- `0` represents an open cell
- `1` represents a blocked cell

You can move in **8 directions** (horizontal, vertical, and diagonal).

Find the **length of the shortest path** from the top-left cell `(0,0)`  
to the bottom-right cell `(n-1,m-1)`.  
If no such path exists, return `-1`.

---

## Key Observation

- Each cell can be treated as a node in a graph
- Each valid move has equal cost `1`
- The problem reduces to finding the shortest path in an unweighted graph
- BFS naturally guarantees the shortest path

---

## Approach

### Idea

- Model the grid as an unweighted graph
- Use **Breadth First Search (BFS)** starting from `(0,0)`
- Explore neighbors level by level
- The first time the destination is reached gives the shortest distance

---

### Steps

1. If the starting or ending cell is blocked (`1`), return `-1`
2. Initialize a visited matrix to avoid revisiting cells
3. Push the starting cell `(0,0)` into a queue with distance `1`
4. Use direction arrays to move in all 8 possible directions
5. While the queue is not empty:
   - Pop the front element
   - If the destination is reached, return the distance
   - Push all valid unvisited neighbors with `distance + 1`
6. If BFS completes without reaching the destination, return `-1`

---

## Key Points

- BFS ensures shortest path due to level-wise traversal
- Each cell is visited only once
- Direction arrays simplify diagonal movement
- No priority queue is required

---

## Why This Approach Works

| BFS | Dijkstra |
|-----|----------|
| All moves have equal cost | Designed for variable weights |
| Uses simple queue | Uses priority queue |
| `O(n × m)` time | `O(n × m log(n × m))` |
| Optimal here | Overkill |

Since all edges have weight `1`, **BFS is strictly better than Dijkstra**.

---

## Time and Space Complexity

- **Time Complexity:** `O(n × m)`  
  Each cell is processed once.

- **Space Complexity:** `O(n × m)`  
  Visited matrix and BFS queue.

---

## Key Takeaway

When all moves have equal cost in a grid,
**BFS is the most optimal and clean solution**.
