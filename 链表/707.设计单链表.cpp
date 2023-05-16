/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
#include <iostream>
using namespace std;

class MyLinkedList
{
public:
    MyLinkedList()
    {
        this->L = new ListNode(0);
        this->size = 0;
    }

    int get(int index)
    {
        int i = 0;
        ListNode *temp = L->next;
        while (i < size)
        {
            if (i++ == index)
                return temp->val;
            temp = temp->next;
        }
        return -1;
    }

    void addAtHead(int val)
    {
        ListNode *New = new ListNode(val);
        New->next = L->next;
        L->next = New;
        size++;
    }

    void addAtTail(int val)
    {
        int i = -1;
        ListNode *temp = L;
        while (1)
        {
            if (i == size - 1)
            {
                ListNode *New = new ListNode(val);
                temp->next = New;
                size++;
                return;
            }
            i++;
            temp = temp->next;
        }
    }

    void addAtIndex(int index, int val)
    {
        int i = -1;
        ListNode *temp = L;
        if (index > size)
            return;
        if (index == size)
        {
            addAtTail(val);
            return;
        }
        while (i < size)
        {
            if (i == index - 1)
            {
                ListNode *New = new ListNode(val);
                New->next = temp->next;
                temp->next = New;
                size++;
                return;
            }
            i++;
            temp = temp->next;
        }
    }

    void deleteAtIndex(int index)
    {
        if (index < size && index >= 0)
        {
            int i = -1;
            ListNode *temp = L;
            while (i < size)
            {
                if (i == index - 1)
                {
                    ListNode *del = temp->next;
                    temp->next = temp->next->next;
                    size--;
                    delete del;
                    return;
                }
                else if (i == index - 1 && index == size - 1)
                {
                    ListNode *del = temp->next;
                    temp->next = nullptr;
                    size--;
                    delete del;
                    return;
                }
                i++;
                temp = temp->next;
            }
        }
        else
        {
            return;
        }
    }

private:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    ListNode *L;
    int size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
