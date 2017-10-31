#ifndef NORON_H
#define NORON_H
#include <math.h>       /* exp */
#define NORONGIRISSAYISI 3
class Noron
{
    double girisAgirligi[NORONGIRISSAYISI];
    double cikis;
    double netCikis;
public:
    Noron();
    void agirliklariEkrandaGoster();
    void noronCikislariSetle(double x);
    void setGirisAgirliklari(double x,int index);
    double getGirisAgirligi(int index);
    double getNoronCikis();
    double getNetCikis();
    double sigmoidFonksiyonu(double x);
    double fnetFonksiyonu(double x);
    double surekliFonksiyon(double x);

};

#endif // NORON_H
