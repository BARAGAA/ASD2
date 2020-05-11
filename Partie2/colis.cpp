/**
 * @author BA RAGAA Mohammed
 * @date 08/04/2020
**/
#include "bagage.hpp"
#include "colis.hpp"
/**
     * @Role : constructor for the object of the type Colis
     * @param string,float
     */
Colis::Colis(std::string name , float volume ){
    _volume = volume;
    _bagageID = name;
}
/**
 * @Role : Destructor for type Colis
 */ 
Colis::~Colis(){}
/**
 * @Role gets the volume of the Colis(Bagage)
 * @return float(the volume)
 */
float Colis::getVolume(){
    return _volume;
}
/**
 * @Role: gets the ID of the bagage(the text)
 * @return string
 */
std::string Colis::getBagageID(){
    return _bagageID;
}
