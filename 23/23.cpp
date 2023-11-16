#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
    ListNode* mergeLists(vector<ListNode*>& lists, int l, int r) {
        if (l > r) {
            return nullptr;
        }
        else if (l == r) {
            return lists[l];
        }
        else {
            ListNode* list1 = mergeLists(lists, l, l + (r - l) / 2);
            ListNode* list2 = mergeLists(lists, l + (r - l) / 2 + 1, r);
            ListNode* dum = new ListNode(0);
            ListNode* tail = dum;
            while (list1 != nullptr && list2 != nullptr) {
                if (list1->val <= list2->val) {
                    tail->next = list1;
                    list1 = list1->next;
                }
                else {
                    tail->next = list2;
                    list2 = list2->next;
                }
                tail = tail->next;
            }
            tail->next = (list1 == nullptr ? list2 : list1);
            return dum->next;
        }

    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeLists(lists, 0, lists.size() - 1);
    }
};

int main()
{
    
}

