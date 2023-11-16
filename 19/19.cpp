#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dum = new ListNode(0, head);
        ListNode* cur = head, * node = dum;
        int cnt = 0;
        while (cur != nullptr) {
            cnt++;
            cur = cur->next;
            if (cnt > n) {
                node = node->next;
            }
        }
        ListNode* nNode = node->next;
        node->next = nNode->next;
        delete nNode;
        return dum->next;
    }
};

int main()
{
    ListNode* node5 = new ListNode(5);
    /*ListNode* node4 = new ListNode(5, node5);
    ListNode* node3 = new ListNode(5, node4);
    ListNode* node2 = new ListNode(5, node3);
    ListNode* node1 = new ListNode(5, node2);*/
    Solution sol;
    sol.removeNthFromEnd(node5, 1);
}

