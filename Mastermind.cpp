#include "lib/Combinaison.h"
#include <iostream>

using namespace std;

void affiche_combi(Combinaison x){
    cout << x.getn1() << "." << x.getn2() <<"." << x.getn3() <<"." << x.getn4() <<endl;
}

int main(void){
    Combinaison cache;

    affiche_combi(cache);
    }