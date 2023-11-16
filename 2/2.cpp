#include <iostream>
#include <vector>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr, * tail = nullptr;
        int c = 0;
        while (l1 || l2) {
            int a1 = l1 ? l1->val : 0;
            int a2 = l2 ? l2->val : 0;
            int sum = a1 + a2 + c;
            c = sum / 10;
            sum %= 10;
            if (!head) {
                head = new ListNode(sum);
                tail = head;
            }
            else {
                tail->next = new ListNode(sum);
                tail = tail->next;
            }
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (c > 0) {
            tail->next = new ListNode(c);
        }

        return head;

    }
};


int main()
{
    std::cout << "Hello World!\n";
}

