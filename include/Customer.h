#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Teller.h"

class Customer
{
    public:
        Customer(int id,int arriveTime,int serviceTime) {
            Id=id,
            ArriveTime=arriveTime;
            ServiceTime=serviceTime;
            WaitingTime=0;
        }

        int getArriveTime(){
        return ArriveTime;
        }
        int WaitingTime;
        int ServiceTime;
        int Id;
    protected:

    private:
        int ArriveTime;



        //Teller *t;    //why error here??



};

#endif // CUSTOMER_H
