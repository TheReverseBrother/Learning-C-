//
// Created by Tomas on 30/08/2019.
//

#include <iostream>
#include "team.h"
#include <string>
using namespace std;
team::team(string name,string phrase) {
    this -> name = name;
    this -> phrase = phrase;
};

team::team() {
  this ->name = "Liverpool";
  this ->phrase = "Youll never walk alone";
};

void team::chant() {
  cout<< this -> phrase << endl;
};
