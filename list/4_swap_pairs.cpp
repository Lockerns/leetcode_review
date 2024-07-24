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
    ListNode* SwapPairs(ListNode* head)
    {
        ListNode* dummy_head = new ListNode(0);
        dummy_head->next = head;
        ListNode* cur = dummy_head;
        while(cur->next && cur->next->next)
        {
            ListNode* temp = cur->next->next->next;
            cur->next->next->next = cur->next;
            cur->next = cur->next->next;
            cur->next->next->next = temp;
            cur = cur->next->next;
        }
        ListNode* result = dummy_head->next;
        delete dummy_head;
        dummy_head = NULL;
        return result;
    }
};

int main()
{
    Solution solu;
    int nums[] = {1, 2, 3, 4};
    ListNode* head = new ListNode(nums[0]);
    ListNode* cur = head;
    for (int i = 1; i < 4; i++)
    {
        ListNode* temp = new ListNode(nums[i]);
        cur->next = temp;
        cur = cur->next;
    }
    cur = solu.SwapPairs(head);
    while(cur)
    {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
    return 0;
}
