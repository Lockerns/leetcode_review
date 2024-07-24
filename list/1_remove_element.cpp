#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode* RemoveElements(ListNode* head, int val)
    {
        ListNode* dummy_head = new ListNode(0);
        dummy_head->next = head;
        ListNode* cur = dummy_head;
        while(cur->next)
        {
            if (cur->next->val == val)
            {
                ListNode* temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            }
            else
            {
                cur = cur->next;
            }
        }
        head = dummy_head->next;
        delete dummy_head;
        return head;
    }
};

int main()
{
    int test_nums[] = {1,2,6,3,4,5,6};
    ListNode* cur = new ListNode(0);
    ListNode* head = cur;
    for (auto ele : test_nums)
    {
        ListNode* new_node = new ListNode(ele);
        cur->next = new_node;
        cur = cur->next;
    }
    ListNode* temp = head;
    head = head->next;
    delete temp;

    Solution test;
    head = test.RemoveElements(head, 6);
    cur = head;
    while(cur)
    {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
    return 0;
}

