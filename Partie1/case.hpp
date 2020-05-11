/**
 * @author BA RAGAA Mohammed
 * @date 17/04/2020
 * @ made as a solution for not doublicating the structure in both of cpp and hpp files of Consigne
**/

#ifndef DEF_CASE
#define DEF_CASE

/**
 * @Role: the alias type of the Bagage which is basically a string
 * */
typedef std::string Bagage;

/**
 * @Role: the alias type of the Bagage which is basically a string
 * */
typedef struct case{
        
        int place;
        Bagage &package;
        
    } Case;
#endif