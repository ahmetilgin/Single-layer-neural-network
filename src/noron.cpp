#include "headers/noron.h"
#include <time.h>
#include <iostream>
using namespace std;


Noron::Noron()
{
    srand(time(NULL));
    // Her Nöron için başlangıç setlenmesi rastgele
    for(int i = 0; i < 3; i++){
        girisAgirligi[i] = rand()% 5;
    }

}
void Noron::agirliklariEkrandaGoster(){
    for(int i = 0; i < 3;i++){
        cout<< girisAgirligi[i] << ' ';
    }
    cout <<endl;
}

void Noron::noronCikislariSetle(double x){
    this->cikis=x ;
    //Net çıkış sigmoid fonksiyonundan geçiriliyor.
   // cout<<"Sigmoid sonucu: " <<sigmoidFonksiyonu(this->cikis)<<endl;
   // cout<<"FnetFonksiyonu Sonucu : "<<fnetFonksiyonu(sigmoidFonksiyonu(this->cikis))<<endl;
    //this->netCikis = fnetFonksiyonu(sigmoidFonksiyonu(this->cikis));

}
double Noron::getGirisAgirligi(int index){
    return this->girisAgirligi[index];
}
double Noron::getNoronCikis(){
    return this->cikis;
}

double Noron::getNetCikis(){
    return this->netCikis;
}


double Noron::sigmoidFonksiyonu(double x){
    if(x < 0 ) return -1.0;
    else return 1.0; // eşit 0 durumu da 1 döndürüyor.
}
double Noron::fnetFonksiyonu(double x){
    return (0.5) * x;
}


void Noron::setGirisAgirliklari(double x,int index){
    this->girisAgirligi[index] = x;
}
double Noron::surekliFonksiyon(double x){
    double sonuc = (1-exp(-2*x))/(1+exp(-2*x));
    //cout<<"Surekli Fonksiyon Çıkışı:: "<<sonuc<<endl;
    return sonuc;
}
