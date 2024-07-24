#include <iostream>
#include <vector>

using namespace std;

class MyLinkedList
{
public:
    struct ListNode
    {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    // init linkedlist
    MyLinkedList()
    {
        _dummy_head = new ListNode(0);
        _size = 0;
    }

    int get(int index)
    {
        if (index > (_size - 1) || index < 0) return -1;
        ListNode* cur = _dummy_head;
        while(index--)
        {
            cur = cur->next;
        }
        return cur->next->val;
    }

    void addAtHead(int val)
    {
        ListNode* temp = _dummy_head->next;
        ListNode* new_node = new ListNode(val);
        new_node->next = temp;
        _dummy_head->next = new_node;
        _size++;
    }

    void addAtTail(int val)
    {
        ListNode* new_node = new ListNode(val);
        ListNode* cur = _dummy_head;
        while(cur->next)
        {
            cur = cur->next;
        }
        cur->next = new_node;
        _size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0) addAtHead(val);
        if (index > _size) return;
        ListNode* cur = _dummy_head;
        while(index--)
        {
            cur = cur->next;
        }
        ListNode* new_node = new ListNode(val);
        new_node->next = cur->next;
        cur->next = new_node;
        _size++;
    }

    void deleteAtIndex(int index)
    {
        if (index >= _size || index < 0) return;
        ListNode* cur = _dummy_head;
        while(index--)
        {
            cur = cur->next;
        }

        ListNode* temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
        temp = NULL;
        _size--;
    }

    void printLinkedList()
    {
        ListNode* cur = _dummy_head;
        while (cur->next)
        {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
private:
    ListNode* _dummy_head;
    int _size;
};

int main()
{
    MyLinkedList linked_list = MyLinkedList();
    linked_list.addAtHead(1);
    linked_list.printLinkedList();
    linked_list.addAtTail(3);
    linked_list.printLinkedList();
    linked_list.addAtIndex(1, 2);
    linked_list.printLinkedList();
    cout << linked_list.get(1) << endl;
    linked_list.deleteAtIndex(1);
    cout << linked_list.get(1) << endl;
    linked_list.printLinkedList();
    return 0;
}
