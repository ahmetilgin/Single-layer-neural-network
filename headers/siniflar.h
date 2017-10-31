#ifndef SINIFLAR_H
#define SINIFLAR_H
#include <iostream>
#include "noktalar.h"
#include <vector>
using namespace std;

class Siniflar
{
    vector <Noktalar> sinifaAitNoktalar;
    double beklenenDeger;
    int ornekSayisi = 0;
public:
    Siniflar();
    void noktaEkle(double x, double y, double z);
    void sinifAitNoktalariGoster();
    void beklenenDegerSet(int x);
    double beklenenDegerGet();
    Noktalar sinifaAitNoktaGet(int index);
    int getOrnekSayisi();

};

#endif // SINIFLAR_H
