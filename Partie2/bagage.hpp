#include<string>

#ifndef DEF_BAGAGE
#define DEF_BAGAGE

//the abstract class Bagage which has Colis as a child class
class Bagage{ 

    public:
    // Abstract functions 
    virtual  float getVolume()=0;
    virtual std::string getBagageID()=0;


    protected:
    float _volume; // float is chosen for the fractions of a kilogram for which a double would be an over kill 

    std::string _bagageID;

};
#endif