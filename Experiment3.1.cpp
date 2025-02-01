//Problem Statement1: You are given the heads of two sorted linked lists list1 and list2. Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists. Return the head of the merged linked list.
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 || !l2) return l1 ? l1 : l2;
        if (l1->val <= l2->val) { l1->next = mergeTwoLists(l1->next, l2); return l1; }
        else { l2->next = mergeTwoLists(l1, l2->next); return l2; }
    }
};

int main() {
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    Solution sol;
    ListNode* result = sol.mergeTwoLists(l1, l2);

    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}
