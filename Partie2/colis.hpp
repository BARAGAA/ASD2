#include <string>
#include "bagage.hpp"

#ifndef DEF_COLIS
#define DEF_COLIS
//the child class of the class Bagage
class Colis : public Bagage{

    public :
    /**
     * @Role : constructor for the object of the type Colis
     * @param string,float
     */
    Colis(std::string name , float volume );
    /**
     * @Role : Destructor for type Colis
     */ 
    ~Colis();
    /**
     * @Role gets the volume of the Colis(Bagage)
     * @return float(the volume)
     */
    float getVolume();
    /**
     * @Role: gets the ID of the bagage(the text)
     * @return string
     */
    std::string getBagageID();
};

#endif