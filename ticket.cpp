#include "ticket.hpp"
#include <bits/stdc++.h>


    Ticket::Ticket(){
        _code ="";
        const int MAX_SIZE = 26;        
        char letters[MAX_SIZE] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q',
        'r','s','t','u','v','w','x',
        'y','z'};
        for (int i=0 ; i < 20; i++)
        _code= _code + letters[rand() % MAX_SIZE];
    }
    Ticket::~Ticket(){
    }
    
    size_t Ticket::hash_code()const{
        std::hash<std::string> hashFonction;
        return hashFonction(_code);
    }
    
    
    bool Ticket::operator==(Ticket const& t)const{
        return t._code == _code;
    }
    bool Ticket::operator!=(Ticket const& t)const{
        return  t._code != _code;
    }
    std::string Ticket::getID()const{
    return _code;
    }

