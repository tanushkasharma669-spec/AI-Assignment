1) Problem Description

The Missionaries and Cannibals problem consists of 3 missionaries and 3 cannibals on the left side of a river. A boat with capacity 2 must transport all to the right side. At no point can cannibals outnumber missionaries on either side.

2) State Representation
(M_left, C_left, Boat_position)
Boat_position = 0 → boat on left bank
Boat_position = 1 → boat on right bank

3) Initial State
(3,3,Left)

4) Goal State
(0,0,Right)

5) Operators (Possible Moves)

Boat can carry:

(1M)

(2M)

(1C)

(2C)

(1M,1C)

6) State Space

Each state is represented as:

(M_left, C_left, Boat_position)

Where:
M_left = number of missionaries on left
C_left = number of cannibals on left
Boat_position = 0 (left) or 1 (right)

Total possible combinations: 4 × 4 × 2 = 32 states

7) Methods used to solve the problem

i) BFS

Uses Queue (FIFO)
Explores level by level
Guarantees shortest path
Higher memory usage

ii) DFS

Uses Stack / Recursion
Goes deep first
May not give shortest path
Uses less memory

iii) IDDFS
Iterative Deepening Depth First Search
Performs DFS with increasing depth limits
Combines advantages of BFS and DFS
Uses less memory while still finding optimal solution

## Performance Comparison

| Feature         | BFS      | DFS                | IDDFS              |
|-----------------|----------|--------------------|--------------------|
| Data Structure  | Queue    | Stack/Recursion    |DFS + Depth limit   |
| Complete        | Yes      | Yes (finite space) |Yes                 |
| Optimal         | Yes      | No                 |Yes                 |
| Memory Usage    | High     | Low                |Medium              |
| Solution Length | 11 moves | May vary           |11 moves            |

BFS guarantees optimal solution because it explores level-wise. DFS may explore deep unnecessary paths.

8) Time & Space Complexity

Since state space is small:

Total possible states = 4 × 4 × 2 = 32 states

So:

Time Complexity ≈ O(V + E)

Here V ≈ 32 (small finite space)

9) Algorithm Overview

BFS Algorithm

1. Start from the initial state (3,3,Left).
2. Add the state to a queue.
3. Generate all valid successor states.
4. Mark visited states to avoid repetition.
5. Continue exploring level by level until the goal state (0,0,Right) is reached.

DFS Algorithm

1. Start from the initial state.
2. Explore the deepest possible state first using recursion.
3. Backtrack when a state becomes invalid or already visited.
4. Continue until the goal state is found.


10) Sample Output

BFS
Steps: 11 | Nodes explored: ...

Step-by-step solution:
Left[3M 3C] <boat> ~~~~ Right[0M 0C]
Left[3M 1C] ~~~~ <boat> Right[0M 2C]
...

DFS
Steps: ...
Nodes explored: ...

IDDFS
Steps: ...
Nodes explored: ...

11) Conclusion

The Missionaries and Cannibals problem was solved using BFS, DFS, and IDDFS search strategies. BFS guarantees the shortest solution but uses more memory. DFS uses less memory but may explore unnecessary paths. IDDFS combines the advantages of BFS and DFS by performing depth-limited searches iteratively.