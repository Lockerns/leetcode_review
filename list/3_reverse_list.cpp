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
    ListNode* reverse_list(ListNode* head)
    {
        ListNode* temp;
        ListNode* cur = head;
        ListNode* pre = NULL;
        while(cur)
        {
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};

int main()
{
    int nums[] = {1, 2, 3, 4, 5};
    ListNode* head = new ListNode(nums[0]);
    ListNode* cur = head;
    for (int i = 1; i < 5; i++)
    {
        ListNode* new_node = new ListNode(nums[i]);
        cur->next = new_node;
        cur = cur->next;
    }
    Solution solu;
    cur = solu.reverse_list(head);

    while(cur)
    {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
    return 0;
}
