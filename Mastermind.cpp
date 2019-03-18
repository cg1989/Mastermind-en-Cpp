#include "lib/Combinaison.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

void affiche_combi(Combinaison c){
    cout << c.getn1() << "." << c.getn2() <<"." << c.getn3() <<"." << c.getn4() <<endl;
}
int myrandom (int i){
    return rand()%i;
}

void generation_combi(Combinaison & c){
    srand(time(NULL));
    vector<int> vec;

    for (int i=1; i<7; ++i){
        vec.push_back(i);
    }

    random_shuffle( vec.begin(), vec.end() , myrandom );

    c.setn1(vec[1]);
    c.setn2(vec[2]);
    c.setn3(vec[3]);
    c.setn4(vec[4]);

}



int main(void){
    Combinaison cache;
    generation_combi(cache);
    affiche_combi(cache);
    

    
}