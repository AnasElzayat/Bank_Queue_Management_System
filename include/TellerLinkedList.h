#ifndef TELLERLINKEDLIST_H
#define TELLERLINKEDLIST_H
#include "TellerNode.h"
#include "Teller.h"


class TellerLinkedList
{
    TellerNode *head, *tail;

public:
    int sizeLL;
    TellerLinkedList()
    {
        head = tail = NULL;
        sizeLL=0;
    }

    void Add(Teller* data)
    {
        TellerNode *node = new TellerNode(data);

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

    TellerNode* getHead(){
    return head;
    }

    void BubbleSort()
    {

        int sorted = 0;

        while(sorted == 0)
        {
            sorted = 1;

            TellerNode *current = head;

            while(current->Next != NULL )
            {

                if(current->Data->getCurrentTime() > current->Next->Data->getCurrentTime())
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

    void swapPointers(Teller* &ptr1, Teller* &ptr2)
    {
        Teller *temp = ptr1;
        ptr1 = ptr2;
        ptr2 = temp;
    }

};

#endif // TELLERLINKEDLIST_H
