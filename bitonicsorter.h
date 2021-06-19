#ifndef BITONICSORTER_BITONICSORTER_H
#define BITONICSORTER_BITONICSORTER_H

void degistirme(int dizi[], int i, int j, int d);

void bitonikBirlestirme(int dizi[], int l, int c, int d);

void bitonikSiralama(int dizi[], int l, int c, int d);

void siralama(int dizi[], int n, int sira);

int ogeBul(const int dizi[], int n, int anahtar);

int ogeEkle(int dizi[], int n, int anahtar, int kapasite);

int ogeSil(int dizi[], int n, int anahtar);

int siralaYazdir(int dizi[], int n, int sira, int i);


#endif //BITONICSORTER_BITONICSORTER_H
