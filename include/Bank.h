#ifndef BANK_H
#define BANK_H
#include "TellerLinkedList.h"
#include "CustomerLinkedList.h"
#include "Teller.h"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

#include <iostream>
using namespace std;

class Bank
{
    public:
        int totalWaitingTime;
        int totalServiceTime;
        Bank(int id,TellerLinkedList t,CustomerLinkedList c) {
        Id=id;
        CurrentTime=0;
        TellerList=t;
        CustomerList =c;
        CustomerList.BubbleSort();
        totalServiceTime=0;
        totalWaitingTime=0;
        }

        void CusromerServed(){
            CusromerNode *current = CustomerList.getHead();
            while(current != NULL )
            {
                TellerNode *t = TellerList.getHead();
                t->Data->CustomerList.Add(current->Data);
                t->Data->Avalibality=0;
                int waitTime;
                if(current->Data->getArriveTime() < t->Data->getCurrentTime()){
                    waitTime=t->Data->getCurrentTime()- current->Data->getArriveTime();
                    current->Data->WaitingTime=waitTime;
                    totalWaitingTime+=waitTime;
                }else if(current->Data->getArriveTime() > t->Data->getCurrentTime()){
                    waitTime= current->Data->getArriveTime()-t->Data->getCurrentTime();
                    t->Data->WasteTime += waitTime;
                    t->Data->AddToCurrentTime(waitTime);
                }
                int serviceTime=current->Data->ServiceTime;
                t->Data->AddToCurrentTime(serviceTime);
                totalServiceTime+=serviceTime;
                t->Data->Avalibality=1;
                TellerList.BubbleSort();
                current=current->Next;
            }
        }

        void displayAllServices(){
            TellerNode *currentTeller = TellerList.getHead();
            while(currentTeller != NULL )
            {
                cout<<"============================================" <<endl;
                cout << YELLOW<<"For Teller with id :- "<<currentTeller->Data->Id<<endl
                <<"he served the following customers :-"<<endl<< RESET << endl;
                CusromerNode *currentCustomer = currentTeller->Data->CustomerList.getHead();
                while(currentCustomer!= NULL){
                    cout<<"\t customer with id :- "<<currentCustomer->Data->Id<<endl;
                    cout<<"Arrive time = "<<currentCustomer->Data->getArriveTime()<<"\t service time = "
                    <<currentCustomer->Data->ServiceTime<<"\t waiting time = "<<currentCustomer->Data->WaitingTime<<
                    "\t leaving time = "<<currentCustomer->Data->WaitingTime+currentCustomer->Data->ServiceTime+currentCustomer->Data->getArriveTime()<<endl;
                    currentCustomer=currentCustomer->Next;
                }

                if(currentTeller->Data->getCurrentTime() > CurrentTime){
                    CurrentTime=currentTeller->Data->getCurrentTime();
                }

                cout <<endl<<"teller utilization rates = "<<100*(currentTeller->Data->getCurrentTime()-currentTeller->Data->WasteTime)/(currentTeller->Data->getCurrentTime())<<" %" << endl;
                currentTeller=currentTeller->Next;
            }
        }

        void makeReport (){
            cout<<endl<<"===========================================================================" <<endl;
            cout << YELLOW<<"General Report for bank with Id :- "<<Id<< RESET << endl;
            cout<<"\t avg waiting time = "<<totalWaitingTime/CustomerList.sizeLL<<endl;
            cout<<"\t avg Service time = "<<totalServiceTime/CustomerList.sizeLL<<endl;
        }


    protected:

    private:
        int Id;
        int CurrentTime;
        TellerLinkedList TellerList;
        CustomerLinkedList CustomerList;
};

#endif // BANK_H
