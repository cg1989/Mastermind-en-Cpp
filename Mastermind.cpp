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

bool checkNumber(int number){
    if (number == 1 || number == 2 || number == 3 || number == 4 || number == 5 || number == 6){
        return true;
    }else{
        return false;
    }
    
}
void jouer(vector<int> & vec, Combinaison & c){ // A faire: Vérif de la saisie.
    int n = 0;
    int temp;
    fflush(stdin);

    while (n != 4){
        temp = static_cast<int> (getch())-48;
        if(checkNumber(temp)){
            if(n == 3){
                printf("%d | ",temp);
            }else{
                printf("%d.",temp);
            }
            vec.push_back(temp);
            n++;
        }
        if(temp == 65){
            exit( EXIT_SUCCESS);
        }
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

void affiche(int blanc,int noir){
    for (int i = 0; i < blanc; i++){
        if (i == blanc-1 && noir == 0){
            printf("@");
        }else{
            printf("@.");
        }
    }

    for (int i = 0; i < noir; i++){
        if(i == noir-1){
            printf("o");
        }else{
            printf("o.");
        }  
    }

    int sum = 2 + 4 - (blanc + noir);
    if (sum%2 == 1){
        sum++;
    }

    for (int i = 0; i < sum;i++){
        printf(" ");
    }

    printf("|\n");
}

void ligne(){
    printf("+-----------+----------+\n");
}

void nbtour(int n){
    cout << "|#" << n <<" ";
}

void titre(){
    system("cls");
    printf("   +---------------+\n");
    printf("   |  MasterMind!  |\n");
    printf("   +---------------+\n\n");
}

void msgFin(int nb){
    cout << "Bravo!"<< endl << "Nombre de coups: " << nb << endl;
}

int main(void){
    vector<int> cache;
    vector<int> pred;
    vector<int> res;
    int exact = 0, presque = 0, nbCoups = 1, win = 1;
    
    titre();
    
    Combinaison jeu (cache,pred);
    generation_combi(jeu);
    //jeu.afficheCache();
    ligne();

    while (win != 0){
        exact = 0; presque = 0;
        pred.clear();
        nbtour(nbCoups);
        jouer(pred,jeu);
        compare(jeu,exact,presque);
        win = gagne(exact);
        affiche(exact,presque);
        ligne();
        
        nbCoups++;
    }

    msgFin(nbCoups-1);
    

    //compare(cache,pred);
    //cout <<"DEBUG> " <<pred[0] << "." << pred[1] <<"." << pred[2] <<"." << pred[3] <<endl;
    // for (int i = 0; i < jeu.sizePred(); i++){
    //     cout << jeu.getPred(i);
    // }
        
}

