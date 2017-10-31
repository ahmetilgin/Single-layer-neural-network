#include "headers/noktalar.h"

Noktalar::Noktalar()
{

}


void Noktalar::noktalarEkranaBas() {
    for(int i = 0 ; i < GIRISSAYISI;i++){
        cout<< this->getDegerler(i)<<"  ";
    }
    cout<<endl;
}

double Noktalar::getDegerler(int index){
    return this->degerler[index];
}
void Noktalar::setDegerler(double x, double y, double z){
    this->degerler[0] = x;
    this->degerler[1] = y;
    this->degerler[2] = z;
}
