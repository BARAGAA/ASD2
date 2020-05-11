/**
 * @author BA RAGAA Mohammed
 * @date 08/04/2020
 */
 #include <iostream>
#include "ticket.hpp"
#include "vconsigne.hpp"
#include "bagage.hpp"
#include "colis.hpp"
using namespace std;



main(){


    


    Colis col1("col1txt",1);
    Colis col2("col2txt",2);
    Colis col3("col3txt",3);
    Colis col4("col4txt",1);
    Colis volumeVer("vol",10);


    cout<<"test Coils::getVolume() "<<endl<<"expect 10 in the next line "<<endl;
    cout<<volumeVer.getVolume()<<endl<<endl;

    cout<<"test Coils::getBagageID() "<<endl<<"expect 'vol' in the next line "<<endl;
    cout<<volumeVer.getBagageID()<<endl<<endl;

    std::vector<std::pair<size_t,float>> list;
    list.push_back(std::pair<size_t,float>(1,1));
    list.push_back(std::pair<size_t,float>(2,3));
    VConsigne C1(list);

    cout<<"test VConsigne::checkVolume() in a false case"<<endl<<"expect 0 in the next line "<<endl;
    cout<< C1.checkVolume(volumeVer.getVolume())<<endl;


    Ticket t1;
    Ticket t2;
    Ticket t3;
    Ticket t4;

   
    t1 = C1.deposit(col1);
    t2 = C1.deposit(col2);

    cout<<"test VConsigne::isFull() in a false case"<<endl<<"expect 0 in the next line "<<endl;
    cout <<C1.isFull()<<endl<<endl;

    t3 = C1.deposit(col3);
    //expect error if when decommenting the next line for depassing the capacity
    //t4 = C1.deposit(col4);

    cout<<"test isFull in a true case"<<endl<<"expect 1 in the next line "<<endl;
    cout <<C1.isFull()<<endl<<endl;


    cout<<"prompt the text associated with bageges in the order 1-3-2 to test VCosigne::collect()"<<endl<<endl;
    cout<<C1.collect(t1).getBagageID()<<endl;
    cout<<C1.collect(t3).getBagageID()<<endl;
    cout<<C1.collect(t2).getBagageID()<<endl;

    cout<<"test diposit a collected bagage"<<endl<<endl;
    Ticket t5 = C1.deposit(col3);
    cout<<C1.collect(t5).getBagageID()<<endl;
    




}
