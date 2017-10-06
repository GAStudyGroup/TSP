#ifndef TOUR_H
#define TOUR_H

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include "City.h"
#include "Map.h"
class Tour;
#include "Utils.h"

using std::vector;
using std::ostream;
using std::setfill;
using std::setw;

class Tour{

    friend ostream& operator<<(ostream&,Tour &);

public:
    Tour();
    Tour(Map&,const int);
    vector<City>& getRoute();
    double getFitness();
    void swap(const int,const int);
    int findCity(City&);
private:
    vector<City> route;
    double dist{0};
    double distance(const int,const int);
};

#endif