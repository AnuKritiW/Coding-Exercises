# Singly-Linked List Interview Cheatsheet (C++)

Use this as a quick guide for the most common patterns, templates, and pitfalls in LeetCode-style `ListNode` problems.

---

## 0) Anatomy & Notation

```cpp
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* n) : val(x), next(n) {}
};
```
- `head` points to the first node (or `nullptr` for empty).
- Draw a tiny picture for tricky steps: `a -> b -> c -> ...`.

---

## 1) Golden Rules

- **Dummy (sentinel) nodes** simplify head/tail edge cases.
- Prefer **iterative O(1) extra space** unless recursion is simpler and N is small.
- **Move pointers, not values** (unless problem explicitly allows value swaps).
- Always consider edge cases: empty list, 1 node, 2 nodes, `k=0/1/len`, duplicates, no cycle, etc.
- When using two pointers, define the **invariant** (e.g., fast is k steps ahead).

---

## 2) Micro-Templates

### A) Traverse
```cpp
for (ListNode* p = head; p; p = p->next) {
  // use p->val
}
```

### B) Insert after a node `p`
```cpp
ListNode* n = new ListNode(x, p->next);
p->next = n;
```

### C) Delete after a node `p` (if exists)
```cpp
if (p && p->next) {
  ListNode* tmp = p->next;
  p->next = tmp->next;
  // delete tmp; // if managing memory
}
```

---

## 3) Workhorse Patterns

### 3.1 Reverse Entire List (iterative 3-pointer)
```cpp
ListNode* prev = nullptr;
ListNode* cur = head;
while (cur) {
  ListNode* nxt = cur->next;
  cur->next = prev;
  prev = cur;
  cur = nxt;
}
head = prev;
```
**Invariant:** `prev` is the reversed prefix; `cur` is the next node to process.

---

### 3.2 Reverse Sublist `[m, n]` (1-indexed)
```cpp
ListNode dummy(0, head);
ListNode* pre = &dummy;
for (int i = 1; i < m; ++i) pre = pre->next;

ListNode* cur = pre->next;
for (int i = 0; i < n - m; ++i) {
  ListNode* move = cur->next;         // node to move forward
  cur->next = move->next;
  move->next = pre->next;
  pre->next = move;
}
head = dummy.next;
```
**Idea:** Head-insert nodes within the window to the front of the sublist.

---

### 3.3 Merge Two Sorted Lists (dummy + tail)
```cpp
ListNode dummy;
ListNode* tail = &dummy;
ListNode* a = l1;
ListNode* b = l2;

while (a && b) {
  if (a->val <= b->val) { tail->next = a; a = a->next; }
  else { tail->next = b; b = b->next; }
  tail = tail->next;
}
tail->next = a ? a : b;
return dummy.next;
```

---

### 3.4 Middle of List (slow/fast)
```cpp
ListNode* slow = head;
ListNode* fast = head;
while (fast && fast->next) {
  slow = slow->next;
  fast = fast->next->next;
}
// slow is middle (left-middle for even length variants can be adjusted)
```

---

### 3.5 K-th From End / Remove N-th From End (two pointers)
```cpp
ListNode dummy(0, head);
ListNode* fast = &dummy;
ListNode* slow = &dummy;

for (int i = 0; i < k; ++i) fast = fast->next;   // fast k ahead
while (fast->next) { fast = fast->next; slow = slow->next; }

// slow->next is the k-th from end
// remove:
ListNode* del = slow->next;
slow->next = del->next;
// delete del; // if managing memory
return dummy.next;
```

---

### 3.6 Cycle Detection (Floyd) + Start of Cycle
```cpp
ListNode* slow = head;
ListNode* fast = head;
while (fast && fast->next) {
  slow = slow->next;
  fast = fast->next->next;
  if (slow == fast) {                // cycle
    ListNode* p = head;
    while (p != slow) { p = p->next; slow = slow->next; }
    // p (== slow) is cycle entry
    break;
  }
}
```

---

### 3.7 Palindrome List (find mid, reverse 2nd half, compare, optional restore)
```cpp
if (!head || !head->next) return true;

// find mid (end of first half)
ListNode* slow = head;
ListNode* fast = head;
while (fast->next && fast->next->next) {
  slow = slow->next; fast = fast->next->next;
}
// reverse second half
ListNode* prev = nullptr;
for (ListNode* cur = slow->next; cur; ) {
  ListNode* nxt = cur->next;
  cur->next = prev; prev = cur; cur = nxt;
}
// compare
ListNode* p1 = head;
ListNode* p2 = prev;
bool ok = true;
while (p2) { if (p1->val != p2->val) { ok = false; break; } p1 = p1->next; p2 = p2->next; }
// (optional) restore second half by reversing prev again
return ok;
```

---

### 3.8 Intersection of Two Lists (two runners swap heads)
```cpp
ListNode* a = headA;
ListNode* b = headB;
while (a != b) {
  a = a ? a->next : headB;
  b = b ? b->next : headA;
}
return a; // either intersection node or nullptr
```
**Why it works:** Each runner traverses A+B length; they align on the intersection or end.

---

### 3.9 Partition List by `x` (stable, two buckets)
```cpp
ListNode lessDummy, geDummy;
ListNode* lt = &lessDummy;
ListNode* ge = &geDummy;

for (ListNode* p = head; p; p = p->next) {
  if (p->val < x) { lt->next = p; lt = lt->next; }
  else            { ge->next = p; ge = ge->next; }
}
ge->next = nullptr;         // important to terminate
lt->next = geDummy.next;
return lessDummy.next;
```

---

### 3.10 Add Two Numbers (reverse-order digits)
```cpp
ListNode dummy; ListNode* tail = &dummy;
int carry = 0;
ListNode* a = l1; ListNode* b = l2;
while (a || b || carry) {
  int s = carry + (a ? a->val : 0) + (b ? b->val : 0);
  carry = s / 10;
  tail->next = new ListNode(s % 10);
  tail = tail->next;
  if (a) a = a->next; if (b) b = b->next;
}
return dummy.next;
```

---

### 3.11 Rotate Right by `k`
```cpp
if (!head || !head->next || k == 0) return head;
// get length & tail
int n = 1; ListNode* tail = head;
while (tail->next) { tail = tail->next; ++n; }
k %= n; if (k == 0) return head;
// make circular, then break
tail->next = head;
int steps = n - k;
ListNode* newTail = tail;
while (steps--) newTail = newTail->next;
ListNode* newHead = newTail->next;
newTail->next = nullptr;
return newHead;
```

---

### 3.12 Reverse Nodes in k-Group (outline)
- Count k nodes; if fewer than k remain, stop.
- Reverse the k-node block with the 3-pointer technique.
- Reconnect `prevGroupTail -> newBlockHead` and `oldBlockHead -> nextBlockHead`.
- Move `prevGroupTail` to `oldBlockHead` and continue.

---

## 4) Debugging Checklist

- **Null guards:** Before `p->next`, ensure `p` isn’t null.
- **Loop termination:** For slow/fast, use `while (fast && fast->next)`.
- **Edge cases:** Empty list, 1 node, exact boundaries (reverse `[1,1]`, remove `n=len`).
- **Reconnections:** After local reverses/merges, set all `next` pointers (especially tails).
- **Cycle risk:** When making circular links (rotate/concatenate), ensure you **break** the cycle.
- **Dummy usage:** Start with `ListNode dummy(0, head);` then return `dummy.next`.

---

## 5) Time/Space Heuristics

- Most list tasks are **O(N) time, O(1) extra space** with pointer tricks.
- Recursion is convenient but uses **O(N) stack**.
- When in doubt, **count length first** (O(N)) to simplify pointer math.

---

## 6) Common Invariants (say them out loud)

- Reverse: “`prev` points to the reversed prefix; `cur` to the next node to process.”
- Two-pointer window: “`fast` is `k` ahead of `slow`.”
- Merge: “`tail` is last of merged; `a`/`b` are next candidates.”
- Cycle entry: “After meeting, one from head and one from meet → entry when equal.”

---

## 7) Quick Edge-Case Matrix

- Empty list? → Return `nullptr` / handle gracefully.
- Single node? → Reverse/rotate/remove should still work.
- `k = 0 or 1`? → No change.
- `k >= length`? → Normalize `k %= length` where relevant.
- Duplicates? → Ensure comparisons use the required relation (`<=` vs `<`).
- End reconnection? → Terminate tails with `nullptr` to avoid hidden cycles.
