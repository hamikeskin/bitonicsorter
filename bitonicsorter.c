#include<stdio.h>
#include "bitonicsorter.h"

// Dizine göre karşılaştır ve değiştir
void degistirme(int dizi[], int i, int j, int d) {
    int yedek;
    if (d == (dizi[i] > dizi[j])) {
        yedek = dizi[i];
        dizi[i] = dizi[j];
        dizi[j] = yedek;
    }
}

// d = 1 ise artan sırada,
// aksi takdirde azalan sırada bir bitonik sırayı sıralar
void bitonikBirlestirme(int dizi[], int l, int c, int d) {
    int k, i;
    if (c > 1) {
        k = c / 2;
        for (i = l; i < l + k; i++)
            degistirme(dizi, i, i + k, d);
        bitonikBirlestirme(dizi, l, k, d);
        bitonikBirlestirme(dizi, l + k, k, d);
    }
}

//Dizinin iki yarısını zıt sıralama düzenlerinde
// yinelemeli olarak sıralayarak bitonik dizi oluşturur
// bitonikBirlestirme elde edilen verileri birleştirir
void bitonikSiralama(int dizi[], int l, int c, int d) {
    int k;
    if (c > 1) {
        k = c / 2;
        bitonikSiralama(dizi, l, k, 1);
        bitonikSiralama(dizi, l + k, k, 0);
        bitonikBirlestirme(dizi, l, c, d);
    }
}

// Tüm diziyi sıralar
void siralama(int dizi[], int n, int sira) {
    bitonikSiralama(dizi, 0, n, sira);
}

// Arama işlemini uygulama
int ogeBul(const int dizi[], int n, int anahtar) {
    int i;
    for (i = 0; i < n; i++)
        if (dizi[i] == anahtar)
            return i;

    return -1;
}

// Verilen kapasitenin dizi[] değerine bir anahtar ekler.
// n, dizi[] nin mevcut boyutudur.
// Bu işlev, ekleme başarılı olursa n + 1,
// aksi takdirde n döndürür.
int ogeEkle(int dizi[], int n, int anahtar, int kapasite) {

    // n zaten kapasiteden büyük veya kapasiteye eşitse
    // daha fazla öğe ekleyemezsiniz
    if (n >= kapasite)
        return n;

    dizi[n] = anahtar;

    return (n + 1);
}

int ogeSil(int dizi[], int n, int anahtar) {
    // Silinecek öğenin konumunu bulma
    int poz = ogeBul(dizi, n, anahtar);

    if (poz == -1) {
        printf("\nOge bulunamadi");
        return n;
    }

    // Öğe silme işlemi
    int i;
    for (i = poz; i < n - 1; i++)
        dizi[i] = dizi[i + 1];

    return n - 1;
}

int siralaYazdir(int dizi[], int n, int sira, int i) {
    siralama(dizi, n, sira);

    printf("Siralanmis dizi: \n");
    for (i = 0; i < n; i++)
        printf("%d ", dizi[i]);
    return 0;
}

