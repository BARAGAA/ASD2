#ifndef DEF_TICKET
#define DEF_TICKET

#include <iostream>
#include <string>


class Ticket
{
    public:
    /**
     * @Role : a constructor for the objetc of the type Ticket
     **/ 
    Ticket();
    /**
     * @Role : a destructor for the objetc of the type Ticket
     **/ 
    ~Ticket();
    /**
     * @Role : a hash calculator that calculates the Hash code of th ID .
     * 
     * @return : The hash code of the ID of the Ticket
     * */ 
    size_t hash_code() const;
    /**
     * @Override 
     * @Role :overrides the poerator== fuction which tests the equality of two objects of the type Ticket
     * @return : true or false
     * **/
    bool operator==(Ticket const& t)const;
    /**
     * @Override 
     * @Role :overrides the poerator!= fuction which tests the inequality of two objects of the type Ticket
     * @return : true or false
     * **/
    bool operator!=(Ticket const& t)const;

    //size_t operator()(const Ticket& t) const;
    /**
     * @Role :Access the ID of the instance of the class Ticket
     * @return : string
     * **/
    std::string getID()const;
    /**
     * @Role : Returns the hashcode of the ticket code and used for the creation of the hashmap in Consigne
     * @param  Ticket
     * @return size_t
     * */
    size_t operator()(const Ticket& t) const;
    struct getHashCode{
        size_t operator()(const Ticket & t) const{
            return t.hash_code(); 
        } 
    };




    private:
    std::string _code; //the most probably unique ID of a given Ticket 

    
};

#endif