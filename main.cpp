#include <iostream>
#include "ticket.hpp"
#include "consigne.hpp"
using namespace std;

main(){
    Consigne C(2);

    Bagage b1 ="'b1'";
    Bagage b2 ="'b2'";

    Ticket t1,t2;

    t1 = C.deposit(b1);
    t2 = C.deposit(b2);
        
    cout << C.isFull() << endl;

    Ticket t3;
    Bagage b3 ="'b3'";

    
    
    std:: cout <<C.collect(t1)<<endl;
    std::cout<< C.isFull() << endl;
    t3 = C.deposit(b1);
    std::cout<< C.isFull() << endl;
    std::cout<< C.collect(t3) << endl;


}