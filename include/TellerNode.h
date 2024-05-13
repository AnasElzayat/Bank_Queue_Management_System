#ifndef TELLERNODE_H
#define TELLERNODE_H
#include "Teller.h"


class TellerNode
{
    public:
        Teller* Data;
        TellerNode *Prev, *Next;

        TellerNode(Teller* data)
        {
            Data = data;
            Prev = Next = NULL;
        }

    protected:

    private:
};

#endif // TELLERNODE_H
