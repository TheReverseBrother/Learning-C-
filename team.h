//
// Created by Tomas on 30/08/2019.
//

#ifndef LEARNING_C___TEAM_H
#define LEARNING_C___TEAM_H
#include <string>
using namespace std;
//header files allow for easy reading but also help with the compiler
class team {
private:
    string name;
    string phrase;

public:
    team(string name,string phrase);
    team();
    ~team();
    void chant();
};


#endif //LEARNING_C___TEAM_H
