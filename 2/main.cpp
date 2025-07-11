#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(), *n = dummy;

        bool carry = false;
        while (l1 || l2) {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            n->next = new ListNode(val1 + val2 + (carry ? 1 : 0));
            carry = false;
            if (n->next->val >= 10) {
                n->next->val -= 10;
                carry = true;
            }

            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
            n = n->next;
        }
        if (carry) {
            n->next = new ListNode(1);
        }

        return dummy->next;
    }
};
