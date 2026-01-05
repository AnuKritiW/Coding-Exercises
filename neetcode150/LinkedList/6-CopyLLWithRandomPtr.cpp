/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
        {
            return nullptr;
        }

        Node* currPtr = head;
        while (currPtr != nullptr)
        {
            Node* copy = new Node(currPtr->val);
            // add the copy enroute to node->random
            // so node--r-->node2 now is node--r-->copy--n-->node2
            copy->next = currPtr->random;
            currPtr->random = copy;

            currPtr = currPtr->next; // increment
        }

        currPtr = head; // reset to start
        while (currPtr != nullptr)
        {
            Node* copy = currPtr->random;
            // if the original node originally pointed to a non-null node, 
            // we want the copy node to point to the copy of that non-null node.
            copy->random = (copy->next == nullptr) ? nullptr : copy->next->random;

            currPtr = currPtr->next; // increment
        }

        Node* copyHead = head->random;

        currPtr = head; // reset to start
        while (currPtr != nullptr)
        {
            Node* copy = currPtr->random;
            currPtr->random = copy->next;
            copy->next = (currPtr->next == nullptr) ? nullptr : currPtr->next->random;

            currPtr = currPtr->next; // increment
        }

        return copyHead;
        
    }
};
