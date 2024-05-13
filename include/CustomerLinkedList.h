#ifndef CUSTOMERLINKEDLIST_H
#define CUSTOMERLINKEDLIST_H
#include "CusromerNode.h"

class CustomerLinkedList
{
    CusromerNode *head, *tail;

public:
    int sizeLL;
    CustomerLinkedList()
    {
        head = tail = NULL;
        sizeLL=0;
    }

    void Add(Customer* data)
    {
        CusromerNode *node = new CusromerNode(data);

        if(head == NULL)
        {
            head = tail = node;
        }
        else
        {
            tail->Next = node;
            node->Prev = tail;
            tail = node;
        }
        sizeLL++;
    }

    CusromerNode* getHead(){
    return head;
    }

    void BubbleSort()
    {

        int sorted = 0;

        while(sorted == 0)
        {
            sorted = 1;

            CusromerNode *current = head;

            while(current->Next != NULL )
            {

                if(current->Data->getArriveTime() > current->Next->Data->getArriveTime())
                {
                    swapPointers(current->Data, current->Next->Data);
                    sorted = 0;
                }
                current = current->Next;
            }

        }
    }


protected:

private:

    void swapPointers(Customer* &ptr1, Customer* &ptr2)
    {
        Customer *temp = ptr1;
        ptr1 = ptr2;
        ptr2 = temp;
    }

};

#endif // CUSTOMERLINKEDLIST_H
