#include <iostream>
#include "consigne.hpp"
#include "Ticket.hpp"
using namespace std;

main(){
    Consigne C(2);

    Bagage b1 ="1";
    Bagage b2 ="2";
    Bagage b3 ="3";

    Ticket t1,t2,t3;

    t1 = C.deposit(b1);
    t2 = C.deposit(b2);
    t3 = C.deposit(b3);
        
    cout << C.isFull() << endl;

    Ticket t4;
    Bagage b4;

    /*try
    {
        t4 = C.C.deposit(b4);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    */
    std:: cout <<C.collect(t1)<<endl;
    std::cout<< C.isFull() << endl;
    t3 = C.deposit(b1);
    std::cout<< C.isFull() << endl;
    std::cout<< C.collect(t3) << endl;


}