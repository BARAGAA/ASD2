
#include "ticket.hpp"
#include "case.hpp"
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>



#ifndef DEF_VCONSIGNE
#define DEF_VCONSIGNE

class VConsigne{
   public:
      /**
         * @Role : a constructor for the object of the type Consigne
         **/ 
            VConsigne(std::vector<std::pair<size_t,float>> list);
      /**
         * @Role : a destructor for the objetc of the type Ticket
         **/ 
            ~VConsigne();
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
      Bagage& collect(Ticket T);

      /**
      * @param Bagage
      * @Role : given a bagage , the function inserts the bagage in the Consigne and returns a ticket that is used for its retreival.
      * @return : Ticket
      **/ 
      Ticket deposit(Bagage &B);
      
      /**
         * @Role test if there is a case of which the volume is higher of equal to a certain number
         * @param float
         * @return boolean
      **/
      bool checkVolume(float V);
      private:

      std::unordered_map<Ticket,Case,Ticket::getHashCode> _map; //Unordered map that is used to link tickets with bagage for the current Bagage in the consigne.
      std::vector<int> _emptyCases; // a queue for the empty cases that was essentialy created to guarentee the balanced usage for the cases in the Consigne
      size_t _capacity; // the maximum number of Bagage that can be at once in the Consigne
      size_t _usedCases; // the current used cases that have Bagage in the instance of time.
      std::vector<float> _volumes; //vector of volumes that is used to check for the avalability of a bi enough case
};

#endif