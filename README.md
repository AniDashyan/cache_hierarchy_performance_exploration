# Cache Hierarchy Performance Exploration: Vector vs List with Increasing Stride Sizes

## Overview

This repository contains a C++ program that measures and compares the performance of accessing elements in a `std::vector` and a `std::list` with increasing stride sizes (e.g., step 1, 16, 64, 256). The primary objective is to analyze how different cache levels (L1, L2, L3) affect access times due to locality. It helps to understand how cache performance is influenced by stride sizes and data structures.

## Problem Description

In this program, an array is accessed with increasing stride sizes. The goal is to measure the time taken to access the array with various stride sizes and compare the performance of two data structures: `std::vector` and `std::list`. The measurements give insight into how cache levels affect access performance.

The program uses different stride sizes, which define the step distance between consecutive accesses in the array. These strides represent patterns of memory access that vary in spatial locality, and the resulting access times help to understand cache behavior.

## Key Concepts

- **Stride Sizes**: The distance between consecutive elements accessed in the container.
- **Locality**: How elements are stored in memory and how close they are to each other, which impacts cache utilization.
- **Cache Levels**: L1, L2, and L3 caches store data at different proximity levels to the CPU. Understanding how cache levels interact with different stride sizes helps optimize memory access patterns for performance.
- **Data Structures**:
  - `std::vector`: A dynamic array that stores elements contiguously in memory, making it cache-friendly.
  - `std::list`: A doubly linked list where elements are scattered in memory, making it less cache-friendly than `std::vector`.

## Program Behavior

The program:
1. Initializes a large container (16 * 256 * 1024 * 64 elements).
2. Runs tests with various stride sizes on two containers (`std::vector` and `std::list`).
3. Measures the time it takes to access elements using each stride size and container type.
4. Outputs the results in terms of milliseconds, showing the difference in access times for both `std::vector` and `std::list`.

### Strides Used:
The stride values used in the tests are: `1`, `4`, `16`, `32`, `64`, `256`, and `1024`. 

## Build & Run

### Prerequisites

Ensure you have the following installed:
- **CMake** (for building the project)
- **A C++ compiler** (such as `g++` or `clang++`)

### Steps to Build & Run

1. Clone this repository to your local machine:
   ```bash
   git clone https://github.com/your-username/ccache_hierarchy_performance_exploration.git
   cd cache_hierarchy_performance_exploration
   ```
2. Run CMake to configure the build system:
   ```bash
   cmake -S . -B build
   ```
3. Build the project in Release mode:
   ```bash
   cmake --build build --config Release
   ```
5. Run the compiled executable:
   ./build/main

## Example Output

After running the program, you will see output similar to this:

```text
Stride    Vector      List
-----------------------------------
    1      1719 ms      3407 ms
    4       514 ms      2081 ms
   16       186 ms      2088 ms
   32       101 ms      1945 ms
   64        73 ms      1897 ms
  256        16 ms      1847 ms
```

## Analysis

- **Cache Effects**: The program helps demonstrate how caches interact with various access patterns. For example, accessing memory in a sequential manner (small strides) tends to be more cache-friendly, as it improves the likelihood of cache hits (especially in L1 cache).
- **Vector vs List**: As `std::vector` stores elements contiguously in memory, it benefits from better spatial locality and typically exhibits better performance with larger stride sizes. In contrast, `std::list` has poor locality due to its scattered memory allocation, leading to higher access times.
