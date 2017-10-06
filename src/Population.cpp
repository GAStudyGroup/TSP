#include "Population.h"

Population::Population(Map &map,const int size){
    for(int i=0;i<size;i++){
        population.push_back(Tour(map, size));
    }
}

Population::Population(){ }

vector<Tour>& Population::getPopulation(){
    return(population);   
}

/*
    realiza a escolha dos tours que irão para a proxima geração
    reserva o melhor tour para ir para a proxima sem alteração
    escolhe os outros por meio da roleta
    faz o crossover nos escolhidos
    faz a mutação 
    e então junta o tour escolhido pelo elitismo e retorna a nova reração
*/
Population* Population::newGeneration(){
    Population  *newPop = new Population;
    Tour best = elitism();
    for(int i=0;i<population.size()-1;i++){
        (*newPop).getPopulation().push_back(roulete());
    }
    newPop->cross();
    newPop->mutate();
    (*newPop).getPopulation().push_back(best);
    return(newPop);
}

void Population::mutate(){
    //faz a mutação em todos os tours
    for(int i=0;i<population.size();i++){
        mutation(i);
    }
}

void Population::cross(){
    //tamanho da população
    int size{(int)population.size()};
    for(int i=0;i<size/2;i++){
        crossoverPMX(rand()%size,rand()%size);
    }
}

void Population::mutation(const int a){
    //realiza n mutações, sendo n o tanto de cidades existentes
    int size{(int)population[0].getRoute().size()};
    for(int i=0;i<size;i++){
        if(rand()%100 < (MUT_PERCENTAGE)){
            population[a].swap(rand()%size,rand()%size);
        }
    }
}

void Population::crossover(const int a,const int b){  
    // Realiza o crossover "cortando" a cauda dos pais passando para os filhos, depois o resto do cromossomo filho é gerado

    Tour tmp1{population[a]},tmp2{population[b]};
    vector<City> order1,order2;
    int size{(int)population[0].getRoute().size()},ctrl1{0},ctrl2{0};
    for(int i=size/2;i<size;i++){  
        // Geração das caudas dos filhos

        population[a].getRoute()[i] = tmp2.getRoute()[i];
        order1.push_back(tmp2.getRoute()[i]);
        population[b].getRoute()[i] = tmp1.getRoute()[i];
        order2.push_back(tmp1.getRoute()[i]);
    }
    for(int i=0;i<size;i++){
        // Geração do inicio do cromossomo filho

        if(!contains(order1,tmp1.getRoute()[i])){  // Se a cidade não está no Tour Filho(devido ao crossover) será adicionada
            population[a].getRoute()[ctrl1] = tmp1.getRoute()[i];
            ++ctrl1;
        }else{//do nothing
        }
        if(!contains(order2,tmp2.getRoute()[i])){ // Idem 
            population[b].getRoute()[ctrl2] = tmp2.getRoute()[i];
            ++ctrl2;
        }else{//do nothing
        }
    }
}

Tour Population::elitism(){  // Mantem a melhor solução da geração, irá retornar o Tour
    double maxFit{maxFitness(population)};
    for(Tour t : (population)){
        if(compareDouble(t.getFitness(),maxFit)){
            return(t);
        }
    }
}

Tour Population::roulete(){  // Método de seleção Roleta
    double sumFitness{0.0},ctrl{0.0};
    int random{0};
    //acha o fitness total da população
    for(Tour t : (population)){
        sumFitness+=(t).getFitness();
    }
    //sorteia um número int e então converte ele para o intervalo de 0 até a fitness total
    random = rand()%RES;
    ctrl = convertRanges(random,sumFitness);
    for(Tour t : (population)){
        ctrl-=(t).getFitness();
        if(ctrl<=0){
            return(t);
        }
    }
    return(population[population.size()-1]);
}


ostream& operator<<(ostream &output,Population &pop){  // Overload de operador para impressão da população
    int i{0};
    for(Tour t : pop.getPopulation()){
        output<<"Tour "<<setfill('0')<<setw(3)<<i<<endl;
        output<<t<<endl;
        ++i;
    }
    return(output);
}




// CROS

/*
    Irá definir o ponto de corte entre os dois pais
    Nesse ponto irá "jogar" o gene de um pai para o outro, alterando as posições iguais
    Serão gerados os filhos a partir disso.
*/
void Population::crossoverPMX(const int a, const int b){
    Tour tmp1{population[a]}, tmp2{population[b]};
    int size{(int)population[0].getRoute().size()};
    int index1{rand()%size}, index2{rand()%size};

    if(index1 > index2){    
        int tmp{index1};
        index1=index2;
        index2=tmp;
    }

    for(int i=index1; i<index2; i++){
        population[a].swap(i,population[a].findCity(tmp2.getRoute()[i]));
        population[a].getRoute()[i] = tmp2.getRoute()[i];

        population[b].swap(i,population[b].findCity(tmp1.getRoute()[i]));
        population[b].getRoute()[i] = tmp1.getRoute()[i];
    }
}


