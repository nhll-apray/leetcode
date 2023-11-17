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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) {
            return head;
        }
        ListNode* dum = new ListNode(0, head);
        ListNode* cur = dum;
        while (cur != nullptr) {
            int cnt = 0;
            ListNode* node = cur->next;
            while (node != nullptr && cnt < k) {
                cnt++;
                node = node->next;
            }
            if (cnt != k) {
                break;
            }
            ListNode* pre = node;
            ListNode* next;
            node = cur->next;
            for (cnt = 0; cnt < k; cnt++) {
                next = node->next;
                node->next = pre;
                pre = node;
                node = next;
            }
            next = cur->next;
            cur->next = pre;
            cur = next;
        }
        return dum->next;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

