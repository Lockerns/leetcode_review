#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {};
};

ListNode* DetectCircle(ListNode* head)
{
    ListNode* fast = head;
    ListNode* slow = head;

    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)
        {
            ListNode* index1 = fast;
            ListNode* index2 = head;
            while(index1 != index2)
            {
                index1 = index1->next;
                index2 = index2->next;
            }
            return index2;
        }
    }
    return nullptr;
}

int main()
{
    return 0;
}