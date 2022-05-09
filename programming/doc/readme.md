# Programming

## General topics

* Flag - Variable used as a temporary item, like buffer, number counter, iteration parser.

    Example in c:

    ```c
    for (int i = 0; i < 10; i++)
    ```

## Data structures

### Array

* Lower level;
* Stores single data type;
* Fixed size;
* Static, use index operator;

### Vector

* High level;
* Can store multiple data types;
* The size can vary;
* Dynamic, uses structures.

## Sorting structures

### Stack

LIFO - last in, first out

```mermaid
flowchart
insert["insert<br><sub>(push)"] --> top --> remove["remove<br><sub>(pop)"]
subgraph Vector["items ⠀⠀⠀⠀⠀⠀⠀"]
  top["⠀ top ⠀"] --- list["⠀ ... ⠀"] --- bottom
end
```

<!-- TODO: graph -->
<!-- TODO: list -->
### Queue

FIFO - first in, first out

```mermaid
flowchart
insert["insert<br><sub>(enqueue)"] --> top
bottom --> remove["remove<br><sub>(dequeue)"]

subgraph Vector["items ⠀⠀⠀⠀⠀⠀⠀"]
  top["⠀ top ⠀"] --- list["⠀ ... ⠀"] --- bottom
end
```

<!-- TODO: Sorting algorithms -->

### Source

* [Definition on C++ vector vs list - Educba](https://www.educba.com/c-plus-plus-vector-vs-list/)
* [Lists vs array in Python - Medium](https://medium.com/backticks-tildes/list-vs-array-python-data-type-40ac4f294551)

<!--
TODO: Graph, Adjacent list - https://www.geeksforgeeks.org/comparison-between-adjacency-list-and-adjacency-matrix-representation-of-graph/
 -->