#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* get_intersection_node(ListNode* list_a, ListNode* list_b)
{
    int length_a = 0, length_b = 0;
    int distance = 0;

    ListNode* cur = list_a;
    while(cur)
    {
        length_a++;
        cur = cur->next;
    }

    cur = list_b;
    while(cur)
    {
        length_b++;
        cur = cur->next;
    }

    ListNode* cur_a = list_a;
    ListNode* cur_b = list_b;
    if (length_a > length_b)
    {
        distance = length_a - length_b;
        while (distance--)
            cur_a = cur_a->next;
    }
    else
    {
        distance = length_b - length_a;
        while (distance--)
            cur_b = cur_b->next;
    }

    while(cur_a)
    {
        if(cur_a == cur_b)
        {
            return cur_a;
        }
        else
        {
            cur_a = cur_a->next;
            cur_b = cur_b->next;
        }
    }
    return NULL;
}
int main()
{
    vector<int> list_a_vec = {0, 9, 1, 2, 4};
    vector<int> list_b_vec = {3, 2, 4};
    ListNode* head_a = new ListNode(list_a_vec[0]);
    ListNode* head_b = new ListNode(list_b_vec[0]);
    ListNode* cur = head_a;
    for (int i = 1; i < list_a_vec.size(); i++)
    {
        ListNode* new_node_a = new ListNode(list_a_vec[i]);
        cur->next = new_node_a;
        cur = cur->next;
    }
    return 0;
}
