# DSA Assignment 2 — Organisational Hierarchy Using Tree Structure and Searching

**Language:** C
**Source file:** `program.c`

A general tree is used to represent the organisational hierarchy, displayed using
level-order traversal, followed by a comparison of Linear Search and Binary Search
over the department names.

---

## A) Tree Structure and Construction

A **general tree** is suitable for representing the organisational hierarchy because
each node can have multiple child nodes.

### The hierarchy

```
CEO
├── HR
├── Finance
└── IT
    ├── Development
    │   ├── Frontend
    │   └── Backend
    └── Testing
```

### Node structure

```c
struct Node {
    char name[MAX_NAME];
    int childCount;
    struct Node* children[MAX_CHILDREN];
};
```

### Construction and level-order traversal

Each node is created dynamically with `createNode()` and linked to its parent with
`addChild()`. The traversal uses a queue, so nodes are printed level by level from
the root.

### Output

```
Level-order traversal:
CEO HR Finance IT Development Testing Frontend Backend
```

The hierarchy level by level is:

| Level | Nodes |
|-------|-------|
| 0 | CEO |
| 1 | HR, Finance, IT |
| 2 | Development, Testing |
| 3 | Frontend, Backend |

---

## B) Searchable Representation and Search Comparison

The department names are stored in a two-dimensional character array:

```c
char departments[MAX_DEPARTMENTS][MAX_NAME];
```

The department names are:

CEO, HR, Finance, IT, Development, Testing, Frontend, Backend

For binary search, the names are sorted alphabetically:

```
Backend CEO Development Finance Frontend HR IT Testing
```

### Linear Search

Linear search checks each department one by one until the required department is
found. Its worst-case time complexity is **O(n)**.

### Binary Search

Binary search works on the sorted department list. It compares the target with the
middle element and eliminates half of the remaining elements after each comparison.
Its worst-case time complexity is **O(log n)**.

### Search comparison

| Department | Linear Search | Binary Search |
|------------|---------------|---------------|
| CEO | 2 comparisons | 2 comparisons |
| Development | 3 comparisons | 3 comparisons |
| Backend | 1 comparison | 4 comparisons |

For a small dataset, binary search does not necessarily use fewer comparisons for
every individual search. Its main advantage becomes clear as the number of
departments increases.

---

## C) Analysis

### 1. Tree Height

The longest path from the root CEO to a leaf is:

```
CEO → IT → Development → Frontend
```

This path contains 3 edges. Therefore:

**Tree height = 3** (or 4 levels, counting from level 0 to level 3).

### 2. Traversal Behaviour

The program uses level-order traversal, which visits the nodes level by level from
the root. A queue is used to implement the traversal.

The traversal order is:

```
CEO → HR → Finance → IT → Development → Testing → Frontend → Backend
```

- **Time complexity:** O(n), where n is the number of nodes in the tree.
- **Space complexity:** O(n) in the worst case, because the queue may contain many
  nodes.

### 3. Search Comparisons

**Linear Search**

- Best case = O(1)
- Average case = O(n)
- Worst case = O(n)

The department names do not have to be sorted for linear search.

**Binary Search**

- Best case = O(1)
- Average case = O(log n)
- Worst case = O(log n)

Binary search is more efficient for large numbers of departments when the data is
maintained in sorted order.

### 4. Time Complexity of Selected Operations

| Operation | Time Complexity |
|-----------|-----------------|
| Creating tree nodes | O(n) |
| Adding children | O(1) per child |
| Level-order traversal | O(n) |
| Linear search | O(n) |
| Binary search | O(log n) |
| Sorting departments | O(n²) |

In this program, **Bubble Sort** is used to sort the department names, so its time
complexity is O(n²). If a more efficient sorting algorithm such as Merge Sort or
Quick Sort were used, the average sorting time could be O(n log n).

### Suitability of the Representation

The general tree is suitable for organisational reporting because it represents the
parent-child relationship between departments naturally. It makes the organisational
structure easy to understand and allows the hierarchy to be displayed using different
traversal methods.

Level-order traversal is especially useful for organisational reporting because it
displays the organisation from the highest level to the lower levels.

For department searching, a character array is used to store the department names.
Linear search can be used without sorting, while binary search requires the names to
be sorted. For repeated searches and larger datasets, binary search is more efficient
because its time complexity is O(log n) compared with O(n) for linear search.

However, if departments are frequently added or removed, maintaining a sorted array
requires additional work.

---

## Conclusion

A general tree is a suitable data structure for representing the company's
organisational hierarchy because it clearly represents the relationships between the
CEO, departments, and sub-departments.

The level-order traversal displays the hierarchy level by level and has a time
complexity of O(n).

For department searching, linear search is simple and does not require sorted data,
but it has a worst-case time complexity of O(n). Binary search requires sorted data
but has a better worst-case time complexity of O(log n).

Therefore, the combination of:

```
General Tree
      ↓
Organisational Reporting

Sorted Character Array
      ↓
Binary Search
      ↓
Department Searching
```

is a suitable solution for organisational reporting and department searching.

---

## How to Compile and Run

**On Windows (CMD):**

```cmd
gcc program.c -o program.exe
program.exe
```

**On Linux / macOS:**

```bash
gcc program.c -o program
./program
```

---

## Note

The comparison counts depend on the order of the array and the implementation of
binary search. The important point is that linear search takes O(n) time in the worst
case, while binary search takes O(log n) time.
