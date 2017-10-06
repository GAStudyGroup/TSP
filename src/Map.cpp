#include "Map.h"

Map::Map(const int size){
    for(int i=0;i<size;i++){
        City objC(rand()%1000,rand()%1000);
        cityList.push_back(objC);
    }
}

Map::Map(vector<City> data):cityList(data){}

vector<City>& Map::getCityList(){
    return(cityList);
}