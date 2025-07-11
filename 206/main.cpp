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
    ListNode *reverseList(ListNode *head) {
        ListNode *prev = nullptr, *current = head;
        while (current) {
            ListNode *next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }
};
