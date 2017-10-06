#ifndef POPULATION_H
#define POPULATION_H

#include <vector>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include "Tour.h"
#include "Map.h"
#include "Utils.h"


using std::cout;
using std::endl;

using std::vector;
using std::ostream;
using std::setfill;
using std::setw;
using std:: string;

class Population{

    friend ostream& operator<<(ostream&,Population &);

public:
    Population(Map&,const int=10);
    Population();
    vector<Tour>& getPopulation();

    Population* newGeneration();

private:
    const int MUT_PERCENTAGE{2};

    vector<Tour> population;
    //realiza a mutação em todos os tours
    void mutate();
    //realiza o cross em todos os tours
    void cross();
    //realiza a mutação no tour especificado
    void mutation(const int);
    //realiza o cross nos tours especificados
    void crossover(const int,const int);

    Tour elitism();
    
    Tour roulete();

    void crossoverPMX(const int, const int);
};
#endif