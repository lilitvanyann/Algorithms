# Queue Implementation in C++

This project is a simple implementation of a Queue data structure using a dynamic array in C++.

## Features

- Enqueue (add element)
- Dequeue (remove element)
- Front (get first element)
- Back (get last element)
- Check if queue is empty
- Check if queue is full

## Technologies

- C++
- Object-Oriented Programming
- Dynamic Memory Allocation

## Project Files

- `queue.h` – Queue class declaration
- `queue.cpp` – Queue class implementation
- `main.cpp` – Program testing

## How It Works

The queue follows FIFO (First In, First Out):

- First inserted element is removed first
- New elements are added at the back
- Elements are removed from the front

## Example

```cpp
queue q(5);

q.Enqueue(10);
q.Enqueue(20);

q.Dequeue();
