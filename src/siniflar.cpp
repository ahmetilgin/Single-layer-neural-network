#include "headers/siniflar.h"

Siniflar::Siniflar()
{

}
void Siniflar::noktaEkle(double x, double y, double z){
    Noktalar noktam;
    noktam.setDegerler(x,y,z);
    this->sinifaAitNoktalar.push_back(noktam);
    this->ornekSayisi++;
}


void Siniflar::sinifAitNoktalariGoster(){
    for(unsigned int i=0; i<this->sinifaAitNoktalar.size(); ++i)
         cout << this->sinifaAitNoktalar[i].getDegerler(0) << ' ' << this->sinifaAitNoktalar[i].getDegerler(1) << ' ' << this->sinifaAitNoktalar[i].getDegerler(2)<< endl ;
}

void Siniflar::beklenenDegerSet(int x){
    this->beklenenDeger = x;
}

// burda ki index o seçilen indexe ait nokta
Noktalar Siniflar::sinifaAitNoktaGet(int index){
    Noktalar noktam = sinifaAitNoktalar[index];
    return noktam;
}

double Siniflar::beklenenDegerGet(){
    return this->beklenenDeger;
}

int Siniflar::getOrnekSayisi(){
    return this->ornekSayisi;
}
