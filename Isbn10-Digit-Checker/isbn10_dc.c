/*
#Ad-Soyad = Huseyin Sahin
#E-posta = huseyin.sahin@ceng.ktu.edu.tr
#Proje = Isbn10 Digit Checker
*/

#include <stdio.h>
#include <stdlib.h>

int d1_hesapla(int sayi_basamaklari[9]);
long long sayilari_birlestirme(int sayi_basamaklari[9],int d1_sayisi);

int main(int argc, char* argv[])
{
    int i, basamaklar[9];
    long long girilen_sayi=atoi(argv[1]);
    /* argv ile string olarak alinan sayi atoi fonksiyonu ile tam
    sayiya donusturur */

    for(i=0; i<9; i++)
    {
        basamaklar[i]=girilen_sayi%10;
        girilen_sayi/= 10;
    /* girilen sayi basamaklarina ayrilip listeye kaydedilir */
    }

    int d1_sayisi=d1_hesapla(basamaklar);

    /* d1 sayisini hesaplamak icin d1_hesapla() fonksiyonu cagrilir */

    long long SonSayi=sayilari_birlestirme(basamaklar,d1_sayisi);

    /* Ekrana basilacak sayiyi hesaplamak icin sayilari_birlestirme()
    fonksiyonuna basamaklar listesi ve d1 sayisi gonderilir */
    printf("Sayinin Hesaplanmis Hali = %lld",SonSayi);

    return 0;
}

int d1_hesapla(int sayi_basamaklari[9])
{
    int i, d1_sayisi, toplam=0, katsayi=2;
    for(i=0; i<9;i++)
    {
        toplam=toplam+(sayi_basamaklari[i]*katsayi);
        katsayi++;

        /* Her bir basamak ilgili katsayi ile carpilir ve
        toplamlari alinir */
    }

    d1_sayisi=11-(toplam%11);
    d1_sayisi%=11;

    /* ilgili toplam sayisini 11'in kati yapmak icin
    eklenmesi gereken d1 hesaplanir */
    return d1_sayisi;
}

long long sayilari_birlestirme(int sayi_basamaklari[9], int d1_sayisi)
{
    int i;
    long long birlesik_sayi=0, basamak_kuvveti=10;

    /* long long kullanmamin sebebi integer degerinin yeterli
    kapasiteye sahip olmamasidir */
    for(i=0;i<9;i++)
    {
        birlesik_sayi+=(sayi_basamaklari[i]*basamak_kuvveti);
        basamak_kuvveti*=10;

        /* Sayinin sonuna d1 eklenerek son haline getirilir */
    }

    if(d1_sayisi>=0 && d1_sayisi<10)
    {
       birlesik_sayi+=d1_sayisi;

       /* Sayinin en anlamsiz hanesine, tek haneli
       olan d1 sayisi eklenir */
    }

    else{
        birlesik_sayi=(birlesik_sayi*10)+d1_sayisi;
        /* Eger d1 `10` ise, ana sayi 10 ile
       carpilarak 1 kez sola shift edilir.Olusan yeni
       sayiyla eklenecek hane toplanir */
    }
    return birlesik_sayi;
}

