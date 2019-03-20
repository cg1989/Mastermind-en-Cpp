#ifndef COMBINAISON_H_
#define COMBINAISON_H_
#include <vector>

using namespace std;

class Combinaison
{

public:
    //Cons/decons
    Combinaison();
    Combinaison(vector<int> cache, vector<int> pred);
    ~Combinaison();

    //Set/get
    int getCache(int n);
    void setCache(vector<int> cache);

    int getPred(int n);
    void setPred(vector<int> pred);

    //Méthdodes d'affichages
    void afficheCache();
    void affichePred();

    //Méthodes de jeu
    int sizePred();
    

private:
    vector<int> m_cache;
    vector<int> m_pred;
    vector<int> m_res;
    //static int compteur;

    
};

#endif /* Combinaison_H_ */
