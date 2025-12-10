# Binary Search Cheatsheet

## Core Ideas
- **Choose your goal first**, then pick the loop shape.
- Two canonical intervals:
  - **Closed**: `[l, r]` with `while (l <= r)` — great for exact match or “shrink while tracking best”.
  - **Half-open**: `[l, r)` with `while (l < r)` — great for boundary searches (first `true`).

Always compute `mid` safely: `int mid = l + (r - l) / 2;`

---

## Templates

### 1) Exact Match (`a[i] == x`) — Closed `[l, r]`
```cpp
int l = 0, r = n - 1;
while (l <= r) {
    int mid = l + (r - l) / 2;
    if (a[mid] == x) return mid;
    if (a[mid] < x)  l = mid + 1;
    else             r = mid - 1;
}
// not found
```

### 2) First `>= x` (aka `lower_bound`) — Half-open `[l, n)`
```cpp
int l = 0, r = n;
while (l < r) {
    int mid = l + (r - l) / 2;
    if (a[mid] >= x) r = mid;     // keep mid; answer is in [l, mid]
    else             l = mid + 1; // discard [l, mid]
}
int idx = l; // check idx < n && a[idx] >= x
```

**Closed variant (track answer):**
```cpp
int l = 0, r = n - 1, ans = n;
while (l <= r) {
    int mid = l + (r - l) / 2;
    if (a[mid] >= x) { ans = mid; r = mid - 1; }
    else              { l = mid + 1; }
}
// ans = first >= x (or n if none)
```

### 3) First `> x` (aka `upper_bound`) — Half-open `[l, n)`
```cpp
int l = 0, r = n;
while (l < r) {
    int mid = l + (r - l) / 2;
    if (a[mid] > x) r = mid;
    else            l = mid + 1;
}
int idx = l; // check idx < n && a[idx] > x
```

### 4) Last `<= x` (predecessor) — Closed `[l, r]`
```cpp
int l = 0, r = n - 1, ans = -1;
while (l <= r) {
    int mid = l + (r - l) / 2;
    if (a[mid] <= x) { ans = mid; l = mid + 1; } // try to go right
    else             { r = mid - 1; }
}
// ans = last <= x (or -1 if none)
```

**Via `upper_bound` shortcut:**
```cpp
int j = upper_bound(a.begin(), a.end(), x) - a.begin();
int ans = (j == 0) ? -1 : j - 1;
```

### 5) Monotone Predicate Pattern (boundary of `false..false..true..true`)
> Find the **first index where `pred(i)` is true**:
```cpp
int l = 0, r = n; // [l, r)
auto pred = [&](int i){ /* monotone condition */ };

while (l < r) {
    int mid = l + (r - l) / 2;
    if (pred(mid)) r = mid;    // keep true region
    else           l = mid + 1;
}
int firstTrue = l; // in [0..n]
```

> Find the **last index where `pred(i)` is true** (use “upper mid” to avoid stalling):
```cpp
int l = 0, r = n - 1;
auto pred = [&](int i){ /* monotone condition */ };

while (l < r) {
    int mid = l + (r - l + 1) / 2; // bias up
    if (pred(mid)) l = mid;        // keep true region
    else           r = mid - 1;
}
int lastTrue = l; // validate if any true exists
```

---

## When to Use Which

- **Boundary searches** (first `>=`, first `>`, first true): use **half-open** `[l, r)`; no “ans” temp needed.
- **Exact match** or **track best while shrinking** (last `<=`, max feasible): use **closed** `[l, r]` with an `ans` variable.

---

## Edge Cases & Guardrails

- **Duplicates**: boundary forms (2–4) are safer than “exact match”.
- **Empty / all smaller / all larger**: always validate the final index and condition.
- **Infinite loop pitfalls**:
  - In closed form, never do `l = mid;` or `r = mid;` — must be `mid ± 1`.
  - In half-open, `r = mid` is fine because interval stays `[l, mid)`.
- **Overflow-safe mid**: `l + (r - l) / 2`.
- **Right-biased mid**: use `(r - l + 1) / 2` when converging on the **last** true.

---

## Quick Mappings (What to Call)

- **First index with `a[i] >= x`** → `lower_bound(x)`
- **First index with `a[i] > x`** → `upper_bound(x)`
- **Last index with `a[i] <= x`** → `upper_bound(x) - 1`

---

## Tiny Checklist Before You Run

- Defined goal? (exact, first ≥, first >, last ≤, predicate boundary)
- Chosen interval style accordingly?
- Mid computed safely?
- Updates move past `mid` (closed) or shrink the half-open interval?
- Post-loop bounds/condition validated?
