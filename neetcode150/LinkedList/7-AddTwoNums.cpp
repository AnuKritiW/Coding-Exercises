/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carryOver = 0;
        ListNode* head = l1;
        ListNode* tail = nullptr;
        while (l1 != nullptr && l2 != nullptr)
        {
            // modify l1 in place
            l1->val += (l2->val + carryOver);
            carryOver = 0;
            if (l1->val > 9)
            {
                l1->val -= 10;
                carryOver = 1;
            }

            // increment
            tail = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        if (l1 != nullptr || l2 != nullptr)
        {
            // one of the linkedlists is longer than the other
            if (l1 != nullptr)
            {
                getRemainingList(tail, l1, carryOver);
            }
            else
            {
                getRemainingList(tail, l2, carryOver);
            }
        }

        if ((carryOver != 0) && (tail != nullptr))
        {
            tail->next = new ListNode(carryOver, nullptr);
        }
        return head;
    }

    void getRemainingList(ListNode*& tail, ListNode* l1, int& carryOver)
    {
        // if l2 is longer than l2, this adds the remainder of l2 to l1 so it is still in place
        tail->next = l1;

        while (l1 != nullptr)
        {
            if (carryOver == 0)
            {
                tail->next = l1;
                return;
            }

            l1->val = l1->val + carryOver;
            carryOver = 0;
            if (l1->val > 9)
            {
                l1->val -= 10;
                carryOver = 1;
            }

            tail = l1;
            l1 = l1->next;
        }
    }
};
