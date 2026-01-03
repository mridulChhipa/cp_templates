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
