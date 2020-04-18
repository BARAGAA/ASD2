#ifndef DEF_BAGAGE
#define DEF_BAGAGE


class Bagage{

public:
Bagage(std::string, unsigned float );

~Bagage(void);

unsigned float getVolume();
std::string getBagageID();


private:
unsigned float _volume; // float is chosen for the fractions of a kilogram for which a double would be an over kill 

std::string _bagageID;

}
#endif