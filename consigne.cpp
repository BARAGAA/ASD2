/**
 * @author BA RAGAA Mohammed
 * @date 08/04/2020
 * */
#include "ticket.hpp"
#include "consigne.hpp"
#include <assert.h>
#include <unordered_map>
#include "case.hpp"
using namespace std;




    typedef std::pair<Ticket,Case> Entree;

/**
 * @Role : a constructor for the objetc of the type Consigne
 **/ 
Consigne::Consigne(size_t n){
    _capacity = n; //in construction capacity set to n
    _usedCases = 0; // no case is used yet 
    _nextCase = 0; // starting case is in the index 0
}
/**
 * @Role : a destructor for the objetc of the type Ticket
 **/ 
Consigne::~Consigne(){
    // no  dynanmic allocation so no disallocation needed
}
/**
 * @Role : Verification if the Consigne is full
 * @return : true or false ;
 **/ 
bool Consigne::isFull() const{
    return _usedCases  == _capacity;
}
/**
 *@param Bagage
* @Role : given a bagage , the function inserts the bagage in the Consigne and returns a ticket that is used for its retreival.
* @return : Ticket
**/ 
Ticket Consigne::deposit(Bagage package){
    assert(!isFull()); //      _usedCases  != _capacity
    size_t reservedPlace;
    if (_nextCase <= _capacity){ //first usage for the case the nextCase variable is used.
        reservedPlace = _nextCase;
    }
    else{ //not the first usage , the case queue is used to stock the package
         reservedPlace = _emptyCases.front();//access to first case of a queue which is constant time
        _emptyCases.pop(); //returns the top element in the queue with  a cost of O(n) in worst case with amortized O(1) in general

    }
    //case to insert to the map
    Case target; 
    target.place = reservedPlace; 
    target.package = package;

    Ticket T;    //The associated ticket

    _map.insert(make_pair(T,target)); //The insertion
    

    _nextCase++; //adding the case to the counter 
    _usedCases++;//adding the case to the counter

    return T;
}

/**
 * @param Ticket
* @Role : given a ticket , the function returns the associated Bagage in the Consigne (the Hash map)
* @return :Bagage
* @complexity 
**/
Bagage Consigne::collect(Ticket t){
    assert(_usedCases >0);// has to have at least one element
    auto it1 = _map.find(t); //costs a constant time O(1) in most(if not all ) cases as a worst case complexity
    assert(it1 != _map.end()); // checking the existence of the pair in the map
    Case caseForTicket= it1->second; //getting the case by the ticket.
    //(if the key exists) here we should first  check if the key exists in the map. 
        size_t location = caseForTicket.place; //getting the location of the case
        _emptyCases.push(location); //add the case in the end of the queue.
        _map.erase(t); //delete the pair <Ticket,Case> from the map.
        _usedCases--; //the used cases are decreased by one .
    
    return caseForTicket.package; //the package is returned from the function


}