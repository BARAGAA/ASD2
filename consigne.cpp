#include "Ticket.hpp"
#include "consigne.hpp"
#include <assert.h>
#include <unordered_map>
#include<iostream>

using namespace std;

typedef struct case_t {
        
        int _place;
        Bagage _package;
        
    } Case;

    typedef std::pair<Ticket,Case> entree;


Consigne::Consigne(size_t n){
    _capacity = n;
    _usedCases = 0;
    _nextCase = 0;
}

bool Consigne::isFull() const{
    return _usedCases  == _capacity;
}

Ticket Consigne::deposit(Bagage _package){
    bool full = isFull();
    assert(full== false);
    int reservedPlace;
    if (_nextCase <= _capacity)
        reservedPlace = _nextCase;
    else{
         reservedPlace = _emptyCases.front();
        _emptyCases.pop();
    }
    Case target;
    target._place = reservedPlace;
    target._package = _package;

    Ticket T;
    _map.insert(make_pair(T, target));
     
    
    auto it = _cases.begin();
    it += reservedPlace;
    _cases.insert(it,T);
    
    _nextCase++;
    _usedCases++;
    return (T);

    
    
}

Bagage Consigne::collect(Ticket T){
    auto it = _map.find(T);
    Case obtainedCase= it->second;
    if(it != _map.cend()){
      
      int location = obtainedCase._place;
      auto it = _cases.begin() + location;
      _cases.erase(it);
      _emptyCases.push(location);
      _map.erase(T);

      _usedCases--;
    }


    return obtainedCase._package;


}