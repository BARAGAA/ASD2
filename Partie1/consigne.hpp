/**
 * @author BA RAGAA Mohammed
 * @date 08/04/2020
**/

#ifndef DEF_CONSIGNE
#define DEF_CONSIGNE

#include "ticket.hpp"
#include "case.hpp"

#include <string>
#include <vector>
#include <unordered_map>
#include <queue>



class Consigne{
    public:
        /**
         * @Role : a constructor for the objetc of the type Consigne
         **/ 
            Consigne(size_t capa);
        /**
         * @Role : a destructor for the objetc of the type Ticket
         **/ 
            ~Consigne();
        /**
     * @Role : Verification if the Consigne is full
     * @return : true or false ;
     **/ 
        bool isFull()const;
        /**
         * @param Ticket
        * @Role : given a ticket , the function returns the associated Bagage in the Consigne (the Hash map)
        * @return :Bagage
        **/ 
        Bagage collect(Ticket);
        /**
         * @param Bagage
        * @Role : given a bagage , the function inserts the bagage in the Consigne and returns a ticket that is used for its retreival.
        * @return : Ticket
        **/ 
        Ticket deposit(Bagage);

    private:
   
        std::unordered_map<Ticket,Case,Ticket::getHashCode> _map; //Unordered map that is used to link tickets with bagage for the current Bagage in the consigne.
        std::queue<size_t> _emptyCases; // a queue for the empty cases that was essentialy created to guarentee the balanced usage for the cases in the Consigne
        size_t _capacity; // the maximum number of Bagage that can be at once in the Consigne
        size_t _usedCases; // the current used cases that have Bagage in the instance of time.
        size_t _nextCase; // the index of the next case where the bagage will be put if the queue below didn't get used entierly yet ,also represents the the total number of deposits so far

};

#endif