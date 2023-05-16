/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList
{
public:
    MyLinkedList()
    {
        this->head = new ListNode(0);
        this->size = 0;
    }

    int get(int index)
    {
        ListNode *temp = head;
        if (index < 0 || index >= size)
            return -1;
        for (int i = -1; i < size; i++)
        {
            if (i == index)
            {
                return temp->val;
            }
            temp = temp->next;
        }
        return -1;
    }

    void addAtHead(int val)
    {
        ListNode *N = new ListNode(val);
        if (size == 0)
        {
            N->next = head->next;
            N->prev = head;
            head->next = N;
        }
        else
        {
            N->next = head->next;
            N->prev = head;
            head->next = N;
            N->next->prev = N;
        }
        size++;
    }

    void addAtTail(int val)
    {
        ListNode *temp = head;
        ListNode *N = new ListNode(val);
        while (temp && temp->next)
        {
            temp = temp->next;
        }
        temp->next = N;
        N->prev = temp;
        size++;
    }

    void addAtIndex(int index, int val)
    {
        ListNode *temp = head;
        if (index == size)
            addAtTail(val);
        else if (index > size)
            return;
        else
        {
            ListNode *N = new ListNode(val);
            for (int i = -1; i < size; i++)
            {
                if (i == index)
                {
                    N->next = temp;
                    N->prev = temp->prev;
                    temp->prev = N;
                    N->prev->next = N;
                    size++;
                    return;
                }
                temp = temp->next;
            }
        }
    }

    void deleteAtIndex(int index)
    {
        ListNode *temp = head;
        if (index >= 0 && index < size)
        {
            for (int i = -1; i < size; i++)
            {
                if (i == index && index == size - 1)
                {
                    temp->prev->next = nullptr;
                    size--;
                    return;
                }
                else if (i == index)
                {
                    temp->next->prev = temp->prev;
                    temp->prev->next = temp->next;
                    size--;
                    return;
                }
                temp = temp->next;
            }
        }
    }

private:
    struct ListNode
    {
        ListNode *prev;
        ListNode *next;
        int val;
        ListNode(int x) : val(x), prev(nullptr), next(nullptr) {}
    };
    ListNode *head;
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
