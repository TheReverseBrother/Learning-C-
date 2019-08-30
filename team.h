//
// Created by Tomas on 30/08/2019.
//

#ifndef LEARNING_C___TEAM_H
#define LEARNING_C___TEAM_H
#include <string>
using namespace std;

class team {
private:
    string name;
    string phrase;

public:
    team(string name,string phrase);
    team();
    void chant();
};


#endif //LEARNING_C___TEAM_H
