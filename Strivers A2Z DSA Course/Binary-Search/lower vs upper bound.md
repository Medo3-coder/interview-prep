Here’s a **comprehensive explanation** and examples of **lower bound** and **upper bound** in C++.

---

### **Lower Bound:**
The **lower bound** is the index of the **first element that is not less than \( k \)**. 
- In simpler terms, it finds the **smallest element \( \geq k \)**.

---

#### **Lower Bound Example Code:**
```cpp
#include <iostream>
#include <vector>
using namespace std;

int findLowerBound(vector<int>& arr, int k) {
    int left = 0, right = arr.size() - 1;
    int lowerBoundIndex = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] >= k) {
            lowerBoundIndex = mid; // Update index as arr[mid] >= k
            right = mid - 1;       // Move left to find the first occurrence
        } else {
            left = mid + 1;        // Move right as arr[mid] < k
        }
    }

    return lowerBoundIndex;
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9}; // Sorted array
    int k = 6;

    int lowerBoundIndex = findLowerBound(arr, k);
    cout << "Lower Bound Index: " << lowerBoundIndex << endl;

    return 0;
}
```

---

#### **How it Works:**
1. **Condition**: `if (arr[mid] >= k)`
   - If the middle element is \( \geq k \), it is a valid candidate for the lower bound.
   - Update `lowerBoundIndex` and move left (`right = mid - 1`) to find the smallest such value.

2. **Search Direction**:
   - If \( arr[mid] < k \), move right (`left = mid + 1`) because \( k \) must be further in the array.

---

#### **Example Walkthrough**:
For `arr = {1, 3, 5, 7, 9}` and \( k = 6 \):
1. Initial range: `left = 0`, `right = 4`.
   - `mid = 2` (`arr[mid] = 5`), \( 5 < 6 \). Move `left = mid + 1 = 3`.

2. Next range: `left = 3`, `right = 4`.
   - `mid = 3` (`arr[mid] = 7`), \( 7 \geq 6 \). Update `lowerBoundIndex = 3`, move `right = mid - 1 = 2`.

3. Stop when `left > right`. Return `lowerBoundIndex = 3`.

**Output**:
```
Lower Bound Index: 3
```

---

### **Upper Bound:**
The **upper bound** is the index of the **first element that is strictly greater than \( k \)**.

---

#### **Upper Bound Example Code:**
```cpp
#include <iostream>
#include <vector>
using namespace std;

int findUpperBound(vector<int>& arr, int k) {
    int left = 0, right = arr.size() - 1;
    int upperBoundIndex = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > k) {
            upperBoundIndex = mid; // Update index as arr[mid] > k
            right = mid - 1;       // Move left to find the first occurrence
        } else {
            left = mid + 1;        // Move right as arr[mid] <= k
        }
    }

    return upperBoundIndex;
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9}; // Sorted array
    int k = 6;

    int upperBoundIndex = findUpperBound(arr, k);
    cout << "Upper Bound Index: " << upperBoundIndex << endl;

    return 0;
}
```

---

#### **How it Works:**
1. **Condition**: `if (arr[mid] > k)`
   - If the middle element is \( > k \), it is a valid candidate for the upper bound.
   - Update `upperBoundIndex` and move left (`right = mid - 1`) to find the smallest such value.

2. **Search Direction**:
   - If \( arr[mid] \leq k \), move right (`left = mid + 1`) because larger elements must be further in the array.

---

#### **Example Walkthrough**:
For `arr = {1, 3, 5, 7, 9}` and \( k = 6 \):
1. Initial range: `left = 0`, `right = 4`.
   - `mid = 2` (`arr[mid] = 5`), \( 5 \leq 6 \). Move `left = mid + 1 = 3`.

2. Next range: `left = 3`, `right = 4`.
   - `mid = 3` (`arr[mid] = 7`), \( 7 > 6 \). Update `upperBoundIndex = 3`, move `right = mid - 1 = 2`.

3. Stop when `left > right`. Return `upperBoundIndex = 3`.

**Output**:
```
Upper Bound Index: 3
```

---

### **Using STL Functions for Lower and Upper Bounds:**
The C++ Standard Library provides `lower_bound` and `upper_bound` functions for sorted arrays.

#### Example:
```cpp
#include <iostream>
#include <vector>
#include <algorithm> // For lower_bound and upper_bound
using namespace std;

int main() {
    vector<int> arr = {1, 3, 5, 7, 9};
    int k = 6;

    auto lower = lower_bound(arr.begin(), arr.end(), k); // First element >= k
    auto upper = upper_bound(arr.begin(), arr.end(), k); // First element > k

    cout << "Lower Bound Index: " << (lower - arr.begin()) << endl;
    cout << "Upper Bound Index: " << (upper - arr.begin()) << endl;

    return 0;
}
```

**Output**:
```
Lower Bound Index: 3
Upper Bound Index: 3
```

---

### **Key Points:**
1. **Lower Bound**:
   - Finds the first element \( \geq k \).
   - Use case: Insert position for \( k \) in sorted order.

2. **Upper Bound**:
   - Finds the first element \( > k \).
   - Use case: Count the number of elements equal to \( k \) using `upper_bound - lower_bound`.

3. **Time Complexity**:
   - Binary search in both custom and STL approaches: **O(log n)**.

4. **Edge Cases**:
   - If no element satisfies the condition, the result is the **size of the array** (STL) or `-1` (manual).
