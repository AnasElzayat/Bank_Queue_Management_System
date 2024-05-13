#ifndef CUSROMERNODE_H
#define CUSROMERNODE_H
#include "Customer.h"


class CusromerNode
{
    public:
        Customer* Data;
        CusromerNode *Prev, *Next;

        CusromerNode(Customer* data)
        {
            Data = data;
            Prev = Next = NULL;
        }

    protected:

    private:
};

#endif // CUSROMERNODE_H
