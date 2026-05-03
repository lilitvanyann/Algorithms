# 📘 Graph Implementation in C++

## 📌 Overview

This project implements a simple **Graph data structure** in C++ using an **adjacency list representation**.

It supports building and managing an undirected graph efficiently.

---

## 📂 Features

* Adjacency list representation
* Undirected graph support
* Dynamic edge insertion
* Easy access to neighbors of each node

---

## 🧠 Graph Representation

The graph is stored as:

* A vector of lists (or vectors)
* Each index represents a node
* Each list contains its neighbors

Example:

```
0 → 1, 2
1 → 0, 3
2 → 0
3 → 1
```

---

## ⚙️ Main Operations

### ➕ Add Edge

Adds a connection between two nodes:

* `addEdge(u, v)`
* Since graph is undirected, both directions are added:

  * u → v
  * v → u

---

## 🧩 Complexity

* Add edge: **O(1)**
* Get neighbors: **O(degree of node)**
* Space: **O(V + E)**

---

## 💡 Usage Idea

This graph can later be used for algorithms like:

* BFS (Breadth-First Search)
* DFS (Depth-First Search)
* Shortest Path algorithms

---

## 🚀 Future Improvements

* Directed graph support
* Weighted edges
* Dijkstra algorithm
* Graph visualization

---

## 👨‍💻 Author

C++ Graph Implementation Project
