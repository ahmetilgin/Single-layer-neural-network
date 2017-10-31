#include "headers/siniragi.h"


SinirAgi::SinirAgi()
{

    // bu ara katmanda ki -1 değerine sahip değişken
    //Sinif[0].noktaEkle(-1,0,-1);
    //Sinif[0].noktaEkle(0.5,0.5,-1);
    //Sinif[1].noktaEkle(0,0,-1);
   // Sinif[1].noktaEkle(0,1,-1);
}






void SinirAgi::ogrenmeBaslat(){

    do{
           this->setHata(0);
           for(int i = 0; i < SINIFSAYISI ; i++){
                for(int j = 0; j < this->Sinif[i].getOrnekSayisi();j++){
                    ileriYonluHesaplama(i,j);
                }
            }
      }
      while(this->hataliysamDuzelt());
 }









void SinirAgi::ileriYonluHesaplama(int sinifIndex,int ornekIndex){

    Noktalar ornek;
    double toplam= 0;
    // Giris ve Ara katman arası çıktı
    // İ indexine sahip sınıftan j indexine sahip örneği al
    ornek = Sinif[sinifIndex].sinifaAitNoktaGet(ornekIndex);
    //cout<<"Verilen Ornek: "<<endl;
    //ornek.noktalarEkranaBas();

    for(int iKatman = 0; iKatman < KATMANSAYISI;iKatman++){

        for(int iNoron = 0; iNoron <GIRISKATMANINORONSAYISI; iNoron++){
            // girisle noron arasında ki ağırlığın çarpımı ve çıkış hesabı
            for(int iCarpim = 0; iCarpim < GIRISSAYISI; iCarpim++){
                toplam += ornek.getDegerler(iCarpim) * noron[iKatman][iNoron].getGirisAgirligi(iCarpim);
                //cout<<"Ornek: "<<ornek.getDegerler(iCarpim)<<" Agirlik: "<<noron[iKatman][iNoron].getGirisAgirligi(iCarpim)<<" "<<endl;
            }
        //cout<<"Verilen Ornek için toplam = "<<toplam<<" "<<endl;
        //toplam = this->noron[iKatman][iNoron].sigmoidFonksiyonu(toplam);
        toplam = this->noron[iKatman][iNoron].surekliFonksiyon(toplam);
        this->noron[iKatman][iNoron].noronCikislariSetle(toplam);
        toplam = 0;
        //cout<<"Beklenen Deger: "<<Sinif[sinifIndex].beklenenDegerGet()<<endl;
        double beklenenCikanFarki=this->Sinif[sinifIndex].beklenenDegerGet()-this->noron[iKatman][iNoron].getNoronCikis();
        //ağırlıkların güncelleneceği anlamına gelir
        //cout<<"Beklenen Cikan Farki = "<<beklenenCikanFarki<<endl;
        this->setHata(mutlakDegerAl(beklenenCikanFarki)+mutlakDegerAl(this->getHataMiktari()));

        //if(beklenenCikanFarki < 0) beklenenCikanFarki = -beklenenCikanFarki;
        //cout<<"************DÜZELTİLECEK Mİ :::: "<<this->hataliysamDuzelt()<<"      "<<endl;

        if(this->hataliysamDuzelt()==1){

            //cout<<"DÜzeltiliyor.."<<endl;
            //cout<<"Düzeltilirken hataMiktari = "<<this->getHataMiktari()<<endl;
            for(int iAgirlik = 0; iAgirlik < GIRISSAYISI;iAgirlik++){

                double suAnkiAgirlik = this->noron[iKatman][iNoron].getGirisAgirligi(iAgirlik);
                double delta= beklenenCikanFarki * ornek.getDegerler(iAgirlik);
                //cout<<"Delta: "<<delta<<endl;
                //cout<<"Güncellemeden Önce: "<<suAnkiAgirlik<<endl;
                double yeniAgirlik = suAnkiAgirlik + delta;
                this->noron[iKatman][iNoron].setGirisAgirliklari(yeniAgirlik,iAgirlik);
                //cout<<"Güncellemeden Sonra: "<<this->noron[iKatman][iNoron].getGirisAgirligi(iAgirlik)<<endl;

            }
        }
        }

    }
   //this->setHata(0);

}








void SinirAgi::InitNetwork(){
    Noron girisNoronlari;
    //1.Katmana Tek noron push edildi.
    for(int i = 0 ; i < GIRISKATMANINORONSAYISI ;i++){
        this->noron[i].push_back(girisNoronlari);

    }

}



void SinirAgi::setHata(double suAnkiHata){
    this->suAnkiHataMiktari = suAnkiHata;
}



double SinirAgi::getHataMiktari(){
    return this->suAnkiHataMiktari;
}



double SinirAgi::getBeklenenHataMiktari(){
    return this->beklenenHataMiktari;
}

void SinirAgi::setBeklenenHataOrani(double miktar)
{
    this->beklenenHataMiktari = miktar;
}




double SinirAgi::hataliysamDuzelt(){

double fark ;
double suan =this->getHataMiktari();
if(suan < 0) fark = -this->getHataMiktari();
else{
    fark = this->getHataMiktari();
}


//cout<<"ALİNAN HATA ::::: "<<fark<<"     ";


if(fark > this->getBeklenenHataMiktari()) return 1;
else{
    return 0;
}
}




double SinirAgi::mutlakDegerAl(double x){
    return (x < 0) ? -x:x;
}


