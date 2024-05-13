#include <iostream>
#include "Teller.h"
#include "Customer.h"
#include "CustomerLinkedList.h"
#include "TellerLinkedList.h"
#include"CusromerNode.h"
#include "TellerNode.h"
#include "Bank.h"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

using namespace std;



int main()
{
    CustomerLinkedList customerList1;
    cout << YELLOW<<"-------------------------------- Hello sir in our bank --------------------------------"<< RESET << endl;

    int ok=1;
    int Id=1;
    int arriveTime;
    int serviceTime;
    while(ok){
    cout<<"for customer with id {"<<Id<<"}"<<endl<<"\t plz enter his arrival time : ";
    cin>> arriveTime;
    cout<<"\t plz enter his service time : ";
    cin>> serviceTime;
    cout<<"\t do you want to continue?    chose             (1)for yes    (0)for no  : ";
    cin>>ok;
    customerList1.Add(new Customer(Id,arriveTime,serviceTime));
    Id++;
}
cout<<endl<<endl<<endl;



    Teller t1 (1);
    Teller t2 (2);
    Teller t3 (3);

    TellerLinkedList tellerList1;
    tellerList1.Add(&t1);
    tellerList1.Add(&t2);
    tellerList1.Add(&t3);

    //Customer c1 (1,10,30);
    //Customer c2 (2,15,30);
    //Customer c3 (3,20,10);


    //customerList1.Add(&c3);
    //customerList1.Add(&c2);
    //customerList1.Add(&c1);


    Bank b1 (1,tellerList1,customerList1);
    b1.CusromerServed();
    b1.displayAllServices();
    b1.makeReport();
    return 0;
}
