#include "Combinaison.h"
#include <iostream>

using namespace std;

Combinaison::Combinaison(): m_n1(0), m_n2(0), m_n3(0), m_n4(0)
{

}

Combinaison::Combinaison(int n1, int n2, int n3, int n4): m_n1(n1), m_n2(n2), m_n3(n3), m_n4(n4)
{

}

int Combinaison::getn1(){
    return m_n1;
}
void Combinaison::setn1(int n1){
    m_n1 = n1;
}

int Combinaison::getn2(){
    return m_n2;
}
void Combinaison::setn2(int n2){
    m_n2 = n2;
}

int Combinaison::getn3(){
    return m_n3;
}
void Combinaison::setn3(int n3){
    m_n3 = n3;
}

int Combinaison::getn4(){
    return m_n4;
}
void Combinaison::setn4(int n4){
    m_n4 = n4;
}

bool operator==(Combinaison const& a, Combinaison const& b)
{
    if (a.m_n1 == b.m_n2)
        return true;
    else
        return false;
}


Combinaison::~Combinaison()
{

}