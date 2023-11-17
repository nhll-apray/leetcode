#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dum = new ListNode(0, head);
        ListNode* cur = dum;
        while (cur != nullptr && cur->next != nullptr 
            && cur->next->next != nullptr) {
            ListNode* node1 = cur->next;
            ListNode* node2 = node1->next;
            ListNode* next = node2->next;
            cur->next = node2;
            node2->next = node1;
            node1->next = next;
            cur = node1;
        }
        return dum->next;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

