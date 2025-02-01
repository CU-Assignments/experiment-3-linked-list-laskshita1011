//Problem Statement2: Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev = nullptr, * curr = head;
        ListNode* dummy = new ListNode(-101);
        dummy->next = head;
        prev = dummy;
        
        while (curr) {
            if (curr->next && curr->val == curr->next->val) {
                while (curr->next && curr->val == curr->next->val) curr = curr->next;
                prev->next = curr->next;
            } else {
                prev = prev->next;
            }
            curr = curr->next;
        }
        
        return dummy->next;
    }
};

int main() {
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(1);
    l1->next->next = new ListNode(2);
    l1->next->next->next = new ListNode(3);
    l1->next->next->next->next = new ListNode(3);

    Solution sol;
    ListNode* result = sol.deleteDuplicates(l1);

    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}
