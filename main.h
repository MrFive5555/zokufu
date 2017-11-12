// main.h
// #define HUSBAND_WIFE_WEIGHT 1
// #define HUSBAND_WIFE_COLOR ""
// #define WIFE_SUBSPRING_WEIGHT 2
// #define WIFE_SUBSPRING_COLOR ""
#ifndef MAIN_H
#define MAIN_H

#include<string>

using namespace std;

#define NO_MOTHER -1
// #define RELATIONSHIP_FILENAME "relationship.csv"
#define RELATIONSHIP_FILENAME "relationship.dot"
#define PERSON_FILNAME "person.csv"

typedef long id_type;

enum Gender {MALE,FEMALE} ;

extern string execDir();

#endif