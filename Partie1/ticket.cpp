/**
 * @author BA RAGAA Mohammed
 * @date 08/04/2020
 * */
 
#include "ticket.hpp"
#include <bits/stdc++.h>
#include <string>

     /**
     * @Role : a constructor for the objetc of the type Ticket
     **/ 
    Ticket::Ticket(){
        _code ="";
        const int MAX_SIZE = 26;        
        char letters[MAX_SIZE] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q',
        'r','s','t','u','v','w','x',
        'y','z'};
        for (int i=0 ; i < 20; i++)
        _code= _code + letters[rand() % MAX_SIZE];
    }
    /**
     * @Role : a destructor for the objetc of the type Ticket
     **/ 
    Ticket::~Ticket(){}

    /**
     * @Role : a hash calculator that calculates the Hash code of th ID .
     * 
     * @return : The hash code of the ID of the Ticket
     * */
    size_t Ticket::hash_code()const{
        std::hash<std::string> hashFonction;
        return hashFonction(_code);
    }
    
    /**
     * @Override 
     * @Role :overrides the poerator== fuction which tests the equality of two objects of the type Ticket
     * @return : true or false
     * **/
    bool Ticket::operator==(Ticket const& t)const{
        return t._code == _code;
    }
     /**
     * @Override 
     * @Role :overrides the poerator!= fuction which tests the inequality of two objects of the type Ticket
     * @return : true or false
     * **/
    bool Ticket::operator!=(Ticket const& t)const{
        return  t._code != _code;
    }
     /**
     * @Role :Access the ID of the instance of the class Ticket
     * @return : string
     * **/
    std::string Ticket::getCode()const{
    return _code;
    }

