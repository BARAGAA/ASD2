/**
 * @author BA RAGAA Mohammed
 * @date 08/04/2020
 * */
 #include <iostream>
#include "ticket.hpp"
#include "consigne.hpp"
using namespace std;

main(){
    Consigne C(3);

    Bagage b1 ="'b1'";
    Bagage b2 ="'b2'";
    Bagage b3 ="'b3'";

    Ticket t1,t2,t3;

    t1 = C.deposit(b1);
    t2 = C.deposit(b2);
    t3 = C.deposit(b3);
    std::cout <<"t1.code= "<<t1.getCode()<< endl;
    std::cout <<"t1.hash= "<<t1.hash_code()<<endl;
    std::cout <<"t2.code= "<<t2.getCode()<< endl;
    std::cout <<"t2.hash= "<<t2.hash_code()<<endl;

        
    cout << C.isFull() <<" value of fullness"<< endl;

    

    
    
    std::cout <<C.collect(t2)<<endl;
    std::cout<< C.isFull()<<" value of fullness"<< endl;
    std::cout<< C.collect(t3) << endl;  
    t2 = C.deposit(b2);
    std::cout<< C.isFull()<<" value of fullness"<< endl;
    t3 = C.deposit(b3);
    std::cout<< C.isFull()<<" value of fullness"<< endl;




}