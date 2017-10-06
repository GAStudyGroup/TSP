#ifndef MAP_H
#define MAP_H

#include <cstdlib>
#include <vector>
#include "City.h"
using std::vector;

class Map{

public:
    Map(const int=20);
    Map(vector<City>);
    vector<City>& getCityList();
private:
    vector<City> cityList;
};

#endif