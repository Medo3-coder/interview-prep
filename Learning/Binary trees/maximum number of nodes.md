Here’s how you can implement the function to calculate the maximum number of nodes at level \( i \) of a binary tree in C++:

### Code Implementation:
```cpp
#include <iostream>
#include <cmath> // For the pow function
using namespace std;

void countNode(int i) {
    // Calculate maximum number of nodes at level i
    int result = pow(2, i - 1);
    cout << result << endl;
}

int main() {
    // Test examples
    countNode(5); // Output: 16
    countNode(1); // Output: 1

    return 0;
}
```

---

### Explanation:
1. **`pow(2, i - 1)`**:  
   This calculates \( 2^{i-1} \), which gives the maximum number of nodes at level \( i \) in the tree.

2. **Input/Output**:  
   The function takes an integer \( i \) as input and prints the maximum number of nodes at that level.

3. **Constraints**:  
   The constraints \( 1 \leq i \leq 20 \) ensure that the result fits in a standard `int` type because \( 2^{19} = 524288 \), which is within the range of `int`.

---

### Example Output:
**Input:**  
```
5
```
**Output:**  
```
16
```

**Input:**  
```
1
```
**Output:**  
```
1
```

---

### Complexity:
- **Time Complexity:** \( O(1) \)  
- **Space Complexity:** \( O(1) \)
