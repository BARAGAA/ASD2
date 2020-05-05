#ifndef DEF_BAGAGE
#define DEF_BAGAGE


class Colis{ 

public:
virtual unsigned float getVolume();
virtual std::string getBagageID();


protected:
unsigned float _volume; // float is chosen for the fractions of a kilogram for which a double would be an over kill 

std::string _bagageID;

}
#endif