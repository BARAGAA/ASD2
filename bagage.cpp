/**
 * @author BA RAGAA Mohammed
 * @date 08/04/2020
 * */
#include "ticket.hpp"
#include "consigne.hpp"
#include <assert.h>
#include <unordered_map>
#include "case.hpp"
using namespace std;

Bagage(std::string, unsigned float ){}

~Bagage(void){}

unsigned float getVolume(){
    return _volume;
}
std::string getBagageID(){
    return _bagageID;
}
