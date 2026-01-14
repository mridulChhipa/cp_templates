# Competitive Programming: Common Mistakes & Pitfalls

## 1. Static Global Arrays vs. New Constraints

**The Problem:** Using fixed-sized global arrays (e.g., `MAX = 2e5 + 7`) and forgetting to update them when moving to a new problem with larger constraints (e.g., ). This leads to **Runtime Errors (SIGSEGV)** or **Wrong Answers** due to buffer overflows.

**The Fix:** * Always check the "Constraints" section first.

* Consider using `std::vector` for dynamic sizing if memory limits allow.
* If using global arrays, make a habit of updating `MAX` immediately upon reading the problem.

---

## 2. Dynamic Evaluation in Loop Conditions

**The Problem:** Placing a function or operation with  complexity inside the loop condition. Because the condition is evaluated **every iteration**, the total complexity balloons.

> **Example:**
> ```cpp
> for (int i = 0; i < accumulate(a, a + n, 0LL); i++) {
>     // ... logic ...
> }
> 
> ```
> 
> 
> * **Expected Complexity:** 
> * **Actual Complexity:** 
> * **Why:** `accumulate` scans  elements every single time the loop checks if it should continue.
> 
> 

**The Fix:** Pre-calculate the limit outside the loop.

```cpp
ll total_sum = accumulate(a, a + n, 0LL);
for (int i = 0; i < total_sum; i++) {
    // ... logic ...
}

```

---

## 3. The Sum of Divisors:  Trap

**The Problem:** When calculating the sum of divisors using the geometric series formula:



If , then . The modular inverse of  does not exist, causing the program to crash or return garbage values.

**The Fix:**
When , the terms of the series  all become . Therefore, the sum is simply .

**Corrected Logic Snippet:**

```cpp
ll p_mod = primes[i] % MOD;
ll exponent = (__int128_t)b * exps[i];

if ((p_mod - 1 + MOD) % MOD == 0) {
    // Case where p % MOD == 1
    res = res * ((exponent + 1) % MOD) % MOD;
} else {
    // Standard Geometric Series Formula
    ll num = (mod_pow(p_mod, exponent + 1) - 1 + MOD) % MOD;
    ll den_inv = mod_inv(p_mod - 1);
    res = res * num % MOD * den_inv % MOD;
}

```

---

## 4. Integer Overflow in Intermediate Calculations

**The Problem:** Even if the final result fits in a `long long`, intermediate multiplications might overflow.

* **Example:** `a * b % MOD` where  will overflow before the modulo is applied.

**The Fix:** * Use `__int128_t` for intermediate multiplications.

* Ensure constants like `1e18` are typed as `1LL << 60` or similar to avoid precision issues with `double`.

---

## 5. Space Optimization for 2D DP Arrays

**The Problem:** When solving dynamic programming problems, you might create a 2D array where computing row `i` only requires values from row `i-1`. This uses O(n × m) space even though you only need O(m) space at any time.

**The Optimization:** Instead of maintaining the entire 2D array, use two 1D arrays: `curr` (current row) and `next` (previous row). Swap them after each iteration.

**Example:**

```cpp
// Instead of this (O(n × m) space):
vector<vector<int>> dp(n, vector<int>(m));
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        dp[i][j] = /* computation using dp[i-1][...] */;
    }
}

// Use this (O(m) space):
vector<int> curr(m), next(m);
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        curr[j] = /* computation using next[...] */;
    }
    swap(curr, next);  // Move current row to next for the next iteration
}
```

**Key Points:**
* Only works when row `i` depends solely on row `i-1`
* Reduces space complexity from O(n × m) to O(m)
* Common in problems like: Edit Distance, Longest Common Subsequence, Grid Path problems

---

## 6. Stack Memory Limits for Local Arrays

**The Problem:** Declaring large arrays inside functions (local/stack arrays) can cause **Stack Overflow (SIGSEGV)** even if the array size seems reasonable. The stack has limited memory, typically **1-8 MB** by default.

**Stack Size Limits:**
* **Default stack size:** ~1 MB on most systems
* **Safe local array size:** Approximately **10^6 integers** (4 MB) or **250,000 long longs** (2 MB)
* Arrays larger than **10^7 elements** will almost certainly crash

**Example of the Problem:**

```cpp
void solve() {
    int arr[10000000];  // 40 MB - STACK OVERFLOW!
    // ... your code ...
}
```

**The Fix:**

**Option 1: Use Global/Static Arrays** (allocated in data segment, not stack)
```cpp
int arr[10000000];  // Global - safe, stored in data segment

void solve() {
    // Use arr here
}
```

**Option 2: Use Dynamic Allocation** (allocated on heap)
```cpp
void solve() {
    vector<int> arr(10000000);  // Heap allocation - safe
    // OR
    int* arr = new int[10000000];  // Manual heap allocation
}
```

**Option 3: Increase Stack Size** (compile-time flag)
```bash
# For GCC/G++
g++ -Wl,--stack,268435456 solution.cpp  # Sets stack to 256 MB

# Or use compiler pragma (Windows/MinGW)
#pragma GCC optimize("O2")
#pragma GCC optimize("stack-protector")
```

**Memory Allocation Comparison:**
| Location | Size Limit | Declaration | Lifetime |
|----------|------------|-------------|----------|
| **Stack** | ~1-8 MB | Local variables in functions | Function scope |
| **Heap** | ~Available RAM | `new`, `malloc`, `vector` | Until freed/deleted |
| **Data Segment** | ~Available RAM | Global/static variables | Program lifetime |

**Best Practice:**
* Use **global arrays** for competitive programming (simple & fast)
* Use **vectors** when size is dynamic or for cleaner code
* **Never** declare large local arrays (> 10^6 elements) without good reason
