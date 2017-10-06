#include "Tour.h"

Tour::Tour(){};
Tour::Tour(Map &map, const int popSize){
    Map tmpMap(map.getCityList());
    int size{(int)map.getCityList().size()};
    int indexFirst{rand()%size};
    int ctrl{0}, batata{0};
    
    while(contains(firstPoint,tmpMap.getCityList()[indexFirst]) && firstPoint.size() < size){
        indexFirst=rand()%size;
    }
    (route).push_back(eraseAndReturn(tmpMap.getCityList(), indexFirst));
    size--;

    firstPoint.push_back(route[0]);
       
    while(size!=0){
        (route).push_back(eraseAndReturn(tmpMap.getCityList(), findLowerDistance(tmpMap.getCityList(), (route)[ctrl])));
        size--;
        ctrl++;
    }  
}

vector<City>& Tour::getRoute(){
    return(route);
}

double Tour::getFitness(){  // Irá retornar a fitness do Tour específico
    double sum{0.0};
    for(int i=0;i<(route).size();i++){
        if((i+1) == (route).size()){
            sum+=distance(i,0);
        }else{
            sum+=distance(i,i+1);
        }
    }
    dist = sum;
    return((1/sum)*10000);
}

void Tour::swap(const int a,const int b){  // Auxiliar para a realização de mutação, irá trocar de lugar duas cidades do Tour
    City tmp = (route)[a];
    (route)[a] = (route)[b];
    (route)[b] = tmp;
}

double Tour::distance(const int a,const int b){  // Retorno da distancia entre duas cidades adjacentes
    return(sqrt(pow(((route)[a].getX())-((route)[b].getX()),2)+pow(((route)[a].getY())-((route)[b].getY()),2)));
}

ostream& operator<<(ostream &output,Tour &t){  // Overload de operador para impressão da população
    int i{0};
    for(City c : t.getRoute()){
        output<<setfill(' ')<<setw(3)<<i<<": "<<c<<endl;
        ++i;
    }
    output<<"Fitness: "<<t.getFitness()<<endl;
    output<<"Distance: "<<t.dist<<endl;
    return(output);
}

int Tour::findCity(City &c){
    for(int i=0; i<route.size(); i++){
        if(c==route[i])
            return(i);
    }
    return(-1);
}
