#include "Utils.h"

#include <iomanip>
using namespace std;

double convertRanges(const int n,const double rand){ 
    return((rand*n)/RES);
}

double compareDouble(const double a,const double b,const double delta){
    double relativeDelta{((a>b)?a:b)*delta};
    return(abs(a-b)<relativeDelta);
}

double maxFitness(vector<Tour> &tours){  // Retorna a maior Fitness da população
    double max = -1*numeric_limits<double>::max(),fitness{0.0};
    for(Tour t : tours){
        fitness = t.getFitness();
        if(max < fitness){
            max = fitness;
        }
    }
    return(max);
}

int bestFitness(vector<Tour> &tours){
    double max = -1*numeric_limits<double>::max(),fitness{0.0};
    int aux;
    for(int i=0; i<tours.size();i++){
        fitness = tours[i].getFitness();
        if(max < fitness){
            aux = i;
        }
    }
    return(aux);
}


double minFitness(vector<Tour> &tours){  // Retorna a menor Fitness da população
    double min = numeric_limits<double>::max(),fitness{0.0};
    for(Tour t : tours){
        fitness = t.getFitness();
        if(min > fitness){
            min = fitness;
        }
    }
    return(min);
}

bool contains(vector<City> &vec,City &c){  // Irá verificar se a cidade já existe no Tour
    for(City objC : vec){
        if(objC == c){
            return(true);
        }
    }
    return(false);
}

double distance(City& c1,City& c2){  // Retorno da distancia entre duas cidades
    return(sqrt(pow(c1.getX()-c2.getX(),2)+pow(c1.getY()-c2.getY(),2)));
}

City eraseAndReturn(vector<City>& map, int index){
    City tmp = map[index];
    map.erase(map.begin() + index);
    return(tmp);
} 

int findLowerDistance(vector<City> map, City atual){
    double lower{numeric_limits<double>::max()};
    int index{-1};

    for(int i=0; i<map.size(); i++){
        if(lower > distance(map[i], atual)){
            if(distance(map[i],atual)!=0){
                index=i;
                lower = distance(map[i], atual);
            }
        }
    }
    return(index);
}