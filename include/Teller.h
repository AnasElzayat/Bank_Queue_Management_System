#ifndef TELLER_H
#define TELLER_H
#include "CustomerLinkedList.h"


class Teller
{
    public:
        Teller(int id) {
        Id=id;
        CurrentTime=0;
        Avalibality = 1;
        WasteTime=0;
        CustomerList;
        }

        float getCurrentTime(){
        return CurrentTime;
        }
        void AddToCurrentTime(float t){
        CurrentTime+=t;
        }
        CustomerLinkedList CustomerList;
        float WasteTime;
        bool Avalibality;
        int Id;
    protected:

    private:
        float CurrentTime;


};

#endif // TELLER_H
