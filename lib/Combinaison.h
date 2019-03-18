#ifndef COMBINAISON_H_
#define COMBINAISON_H_


using namespace std;

class Combinaison
{

public:
    Combinaison();
    Combinaison(int n1, int n2, int n3, int n4);
    ~Combinaison();

    //static void nbCombinaison();
    int getn1();
    void setn1(int n1);

    int getn2();
    void setn2(int n2);

    int getn3();
    void setn3(int n3);

    int getn4();
    void setn4(int n4);

    friend bool operator==(Combinaison const& a, Combinaison const& b);

private:
    int m_n1;
    int m_n2;
    int m_n3;
    int m_n4;
    //static int compteur;

    
};

#endif /* Combinaison_H_ */
