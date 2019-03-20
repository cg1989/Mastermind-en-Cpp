#include "Combinaison.h"
#include <iostream>
#include <vector>

using namespace std;

//Constructeur
Combinaison::Combinaison(): m_cache(4), m_pred(4)
{

}

Combinaison::Combinaison(vector<int> cache, vector<int> pred): m_cache(cache), m_pred(pred)
{

}

//Setteur/getteur

int Combinaison::getCache(int n)
{
    if (n > static_cast<int> (m_cache.size())){
        cout << "Erreur: n trop grand" << endl;
    }
    return m_cache[n];
}

void Combinaison::setCache(vector<int> vec){
    m_cache = vec;
}

int Combinaison::getPred(int n)
{
    if (n > static_cast<int> (m_pred.size())){
        cout << "Erreur: n trop grand" << endl;
    }
    return m_pred[n];
}

void Combinaison::setPred(vector<int> vec){
    for (int i = 0; i < static_cast<int>(vec.size()); i++){
        m_pred.push_back(vec[i]);
    }
}

//Méthodes d'affichage

void Combinaison::afficheCache(){
     cout << getCache(0) << "." << getCache(1) <<"." << getCache(2) <<"." << getCache(3) <<endl;
    
}

void Combinaison::affichePred(){
     cout << getPred(0) << "." << getPred(1) <<"." << getPred(2) <<"." << getPred(3) <<endl;
    
}


//Méthodes 

int Combinaison::sizePred(){
    return m_pred.size();
}










//Destructeur
Combinaison::~Combinaison()
{

}
