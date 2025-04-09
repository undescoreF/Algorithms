This repository contains C implementations of fundamental algorithms for **searching**, **sorting**, and **processing synthetic datasets**. 

---

## 📁 Repository Structure

### **1. Sorting Algorithms**
- `bubbleSort.c` – Basic O(n²) comparison sort  
- `insertionSort.c` – Simple adaptive insertion sort  
- `quickSort.c` – Efficient O(n log n) divide-and-conquer sort  
- `radixSort.c` – Fast non-comparative integer sort  
- `selectionSort.c` – Basic in-place O(n²) sort  

### **2. Search Algorithms**
- `binary_search.c` – Classic O(log n) binary search  
- `interpolation_search.c` – Optimized for uniformly distributed data  
- `jump_search.c` – Block-based search (O(√n)) for sorted arrays  
- `linear_search.c` – Basic O(n) sequential check  

### **3. CSV Processing (Synthetic Data)**
- `quickSort_csv.c` – Sorts 1,000 synthetic user records  
- `binarySearch_csv.c` – Searches in sorted user data  
- **Dataset:** `random_user.csv`  
- **Output:** `random_user_sorted_by_name.csv`  

### **4. Performance Analysis**
- `search_time.c/h` – Benchmarks for search algorithms  
---
