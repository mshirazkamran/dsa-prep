# Data Structures and Algorithms Overview

## Tree  
A tree is a hierarchical data structure where each node is connected by edges. Each node has one parent (except the root) and can have multiple children.  
Trees are commonly used to represent hierarchical relationships such as organizational charts, file systems, and XML/HTML documents.  
**Use Case**: Efficient searching, insertion, and deletion in hierarchical data, e.g., file systems and databases.

---

## AVL Tree  
An AVL Tree is a self-balancing binary search tree where the height difference (balance factor) between the left and right subtrees of any node is at most one.  
Balancing is maintained using rotations (single or double) during insertions and deletions, ensuring efficient operations.  
**Use Case**: Applications requiring frequent insertions and deletions while maintaining sorted data, such as databases and memory management systems.

---

## Queue  
A queue is a linear data structure that follows the FIFO (First In, First Out) principle. Elements are added to the rear and removed from the front.  
Queues are widely used in task scheduling, data buffering, and breadth-first search in graphs.  
**Use Case**: Managing requests in operating systems, such as job scheduling or printer task management.

---

## Dequeue  
A deque (Double-Ended Queue) is a generalized form of a queue where elements can be added or removed from both ends.  
It provides flexibility in accessing and managing elements but requires more control over pointers.  
**Use Case**: Sliding window problems, caching, and scenarios needing fast access to both ends of a list.

---

## Stack  
A stack is a linear data structure following the LIFO (Last In, First Out) principle. Elements are added (pushed) or removed (popped) from the top of the stack.  
It is ideal for scenarios where the most recently added data is the first to be used, such as in recursive calls or undo operations.  
**Use Case**: Expression evaluation, backtracking algorithms, and managing function calls in compilers.

---

## Min Heap  
A min heap is a binary tree where the root node contains the smallest value, and every parent node is smaller than or equal to its children.  
Heap properties ensure that retrieval of the smallest element is efficient.  
**Use Case**: Priority queues where the smallest or highest-priority element is served first, such as in task scheduling.

---

## Max Heap  
A max heap is a binary tree where the root node contains the largest value, and every parent node is greater than or equal to its children.  
It is primarily used for efficiently retrieving the maximum value in a collection.  
**Use Case**: Heap sort and implementing priority queues that require the largest element first.

---

## Minimum Spanning Tree (MST)  
A minimum spanning tree is a subset of edges in a connected, weighted graph that connects all vertices with the minimum total edge weight and no cycles.  
MST ensures optimal resource usage when connecting nodes in a network.  
**Use Case**: Network design, such as laying cables, or connecting cities in road systems.

---

## Prim’s Algorithm  
Prim’s algorithm finds the MST of a graph by starting with a single vertex and growing the tree by adding the smallest edge that connects an unvisited vertex.  
It uses a greedy approach to ensure optimality.  
**Use Case**: Designing networks like electricity grids or optimizing paths between cities.

---

## Kruskal’s Algorithm  
Kruskal’s algorithm finds the MST by sorting edges by weight and adding them one by one to the MST, provided they do not form a cycle.  
It efficiently handles sparse graphs.  
**Use Case**: Building network connections with minimum cost, such as telephone or data networks.

---

## Dijkstra’s Algorithm  
Dijkstra’s algorithm is used to find the shortest path from a source vertex to all other vertices in a weighted graph with non-negative edge weights.  
It employs a greedy approach to progressively calculate the shortest distances.  
**Use Case**: GPS navigation systems, internet routing, and traffic management systems.
