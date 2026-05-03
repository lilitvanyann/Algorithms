# 📘 BFS Graph Project (C++ Implementation)

## 📌 Overview

This project is a simple implementation of a **Graph data structure** and **Breadth-First Search (BFS)** algorithm in C++.

It supports:

* Adjacency list graph representation
* BFS traversal
* Tracking distance, parent, and visited state
* Safe error handling using exceptions

---

## 📂 Project Structure

```
├── graph.h / graph.cpp      # Graph implementation (adjacency list)
├── bfs.h / bfs.cpp          # BFS algorithm implementation
├── main.cpp                 # Example usage
```

---

## 🧠 Features

### Graph

* Undirected graph
* Adjacency list storage
* Efficient edge insertion

### BFS Algorithm

* Traverses graph level by level
* Computes:

  * `distance` from start node
  * `parent` (for path reconstruction)
  * `color` (WHITE / GRAY / BLACK)

---

## ⚙️ BFS Logic

1. Initialize all nodes:

   * WHITE (unvisited)
   * distance = -1
   * parent = -1

2. Start node:

   * color = GRAY
   * distance = 0
   * push into queue

3. While queue is not empty:

   * pop front node
   * visit all neighbors
   * update distance, parent
   * mark visited nodes

4. Mark node as BLACK when fully processed

---

## 🚨 Error Handling

The BFS function uses exceptions:

```cpp
throw std::out_of_range("Invalid start vertex");
```

This ensures:

* Invalid input does not crash the program
* Errors are handled safely using `try/catch`

---

## 🧪 Example Usage

```cpp
try {
    BFSdata result = BFS(graph, 0);
} catch (const std::out_of_range& e) {
    std::cout << e.what();
}
```

---

## 📊 Output Data

After running BFS, you get:

* `distance[i]` → shortest distance from start node
* `parent[i]` → previous node in BFS tree
* `color[i]` → traversal state

---

## 💡 Notes

* BFS guarantees shortest path in unweighted graphs
* Uses queue (FIFO structure)
* Time complexity: **O(V + E)**

---

## 🚀 Future Improvements

* Add DFS implementation
* Add weighted graph support (Dijkstra)
* Add path reconstruction function
* Add visualization

---

## 👨‍💻 Author

C++ Graph & BFS implementation project
