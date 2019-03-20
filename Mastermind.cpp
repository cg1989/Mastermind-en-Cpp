#include "lib/Combinaison.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <string>
#include<conio.h>

using namespace std;

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

    c.setCache(vec);

}

void jouer(vector<int> & vec, Combinaison & c){ // A faire: Vérif de la saisie.
    int n = 0;
    int temp;
    
    while (n != 4){
        cin >> temp;
        //printf("\x0d");
        printf("\027[1A");
        vec.push_back(temp);
        n++;
    }
    c.setPred(vec);
}

void compare(Combinaison & c,int & exact,int & presque){
    for (int i = 0; i < c.sizePred(); i++){
        if (c.getPred(i) == c.getCache(i)){
            exact++;
        }else{
            int n = 0;
            for (int j = 0; j < c.sizePred(); j++){
                if (c.getPred(n) == c.getCache(i)){
                    presque++;
                }
                n++;
            }
        }
    }
}

int gagne(int var){
    if (var == 4){
        return 0;
    }else{
        return 1;
    }
}

int main(void){
    vector<int> cache;
    vector<int> pred;
    vector<int> res;
    int exact = 0, presque = 0, nbCoups = 0, win = 1;
    
    Combinaison jeu (cache,pred);
    generation_combi(jeu);
    jeu.afficheCache();

    while (win != 0){
        exact = 0; presque = 0;
        if (!pred.empty()){pred.clear();}
        jouer(pred,jeu);
        jeu.affichePred();
        compare(jeu,exact,presque);
        win = gagne(exact);
        cout << "exact: " << exact << endl;
        cout << "presque: " << presque << endl;

        nbCoups++;
    }
    

    //compare(cache,pred);
    //cout <<"DEBUG> " <<pred[0] << "." << pred[1] <<"." << pred[2] <<"." << pred[3] <<endl;
    // for (int i = 0; i < jeu.sizePred(); i++){
    //     cout << jeu.getPred(i);
    // }
        
}


//Voir les exacts et presque !