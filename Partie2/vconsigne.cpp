/**
* @author BA RAGAA Mohammed
* @date 04/05/2020
* */
#include "ticket.hpp"
#include "vconsigne.hpp"
#include <cassert>
#include <unordered_map>
#include "case.hpp"
using namespace std;

typedef std::pair<Ticket,Case> Entree; 
/**
* @Role : a constructor for the object of the type Consigne
* @O(n)
*/ 
VConsigne::VConsigne(vector<std::pair<size_t,float>> list){

    assert(list.size() > 0); // Empty lists are not accepted
    //attributs
    _capacity =0 ;
    _usedCases = 0 ;
    //setting the vectors and other attributs
    for(int i = 0 ; i < list.size(); i++){
        float vol = list.at(i).second; //for each volume
        assert(vol > 0); // the non positive volumes are not accepted
        for(int j = 0 ; j < list.at(i).first; j++){
            _emptyCases.push_back(i);// j cases are added for each volume
            _volumes.push_back(vol);
            _capacity++;
        }
    }
}
/**
* @Role : a destructor for the objetc of the type Ticket
* @O(1)
**/ 
VConsigne::~VConsigne(){}

/**
* @Role : Verification if the Consigne is full
* @return : true or false ;
* O(1)
*/ 
bool VConsigne::isFull()const{
    return _usedCases == _capacity;
}


/**
 * @Role test if there is a case of which the volume is higher of equal to a certain number
 *@param float
 * @return boolean
 * @ O(n)
**/
bool VConsigne::checkVolume(float volume){
    if(!isFull()){ //if its full then no need to check
        for(int i = 0; i< _emptyCases.size() ; i++){
            //cout<<"0"<<endl;
            if(_volumes.at(_emptyCases.at(i)) >= volume){
                return true; // a case is found that matches the requirements
            }
        }
    }
    return false;
}
/**
  * @param Bagage
  * @Role : given a bagage , the function inserts the bagage in the Consigne and returns a ticket that is used for its retreival.
  * @return : Ticket
  * @O(n)
**/ 
Ticket VConsigne::deposit(Bagage &package){

    assert(checkVolume(package.getVolume())); // check for volume O(n)
    int index = -1;
    float volInLoop;
    int bestMatch;
    float caseVol;

    for(int i = 0 ; i <_emptyCases.size(); i++){
        caseVol = _volumes[_emptyCases.at(i)];

        if(index == -1 && package.getVolume() <= caseVol){
            
            index = _emptyCases.at(i);
            bestMatch = i;
            volInLoop = caseVol;
    
        }else if( caseVol >= package.getVolume() && caseVol < volInLoop ){ 
            index = _emptyCases.at(i);
            bestMatch = i;
            volInLoop = caseVol;
        }
    }
    _emptyCases.erase(_emptyCases.begin()+bestMatch); //O(1)

    
    Ticket t;
    Case target ={(size_t)index,package};

    _map.insert(make_pair(t, target));

    _usedCases++;

  return t;
}
/**
* @param Ticket
* @Role : given a ticket , the function returns the associated Bagage in the Consigne (the Hash map)
* @return :Bagage
**/
Bagage& VConsigne::collect(Ticket t){
    assert(_usedCases > 0); //if used cases are zero then there is no bagege
    assert(_map.find(t) != _map.end()); //the ticket must have associated bagage


    auto it = _map.find(t);//costs a constant time O(1) in most(if not all ) cases as a worst case complexity
    Case caseForTicket = it-> second;

    _emptyCases.push_back(caseForTicket.place);//the case is empty agein

    _map.erase(t);//delete the pair <Ticket,Case> from the map.
    _usedCases--;//the used cases are decreased by one .
    return caseForTicket.package;//the package is returned from the function
}
