#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {};
};

ListNode* RemoveNthFromEnd(ListNode* head, int index)
{
    ListNode* dummy_head = new ListNode(0);
    dummy_head->next = head;
    ListNode* left = dummy_head;
    ListNode* right = dummy_head;

    while(right->next && index--)
    {
        right = right->next;
    }

    while(right->next)
    {
        left = left->next;
        right = right->next;
    }
    ListNode* temp = left->next;
    left->next = left->next->next;
    delete temp;
    temp = NULL;
    head = dummy_head->next;
    delete dummy_head;
    dummy_head = NULL;
    return head;
}

int main()
{
    // vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> nums = {1, 2};
    int index = 1;

    ListNode* head = new ListNode(nums[0]);
    ListNode* cur = head;
    for (int i = 1; i < nums.size(); ++i)
    {
        ListNode* new_node = new ListNode(nums[i]);
        cur->next = new_node;
        cur = cur->next;
    }
    head = RemoveNthFromEnd(head, index);
    cur = head;
    while(cur)
    {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
    return 0;
}
