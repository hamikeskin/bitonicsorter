//
//
// BU PROGRAM, GİRİŞ BOYUTU 2'NİN KATLARI (2, 4, 8, 16, 32) OLDUĞUNDA CALIŞIR.
//
//
#include<stdio.h>
#include "bitonicsorter.h"

int main() {
    printf("BU PROGRAM, GIRIS BOYUTU \n"
           "2'NIN KATLARI (2, 4, 8, 16, 32) OLDUGUNDA CALISIR.\n");
    int dizi[] = {1, 10, 2, 3, 1, 23, 45, 21};
    int n = sizeof(dizi) / sizeof(dizi[0]);
    int i = 0;
    int sira = 1;

    siralaYazdir(dizi, n, sira, i);

    int komut = 0;
    int anahtar;
    while (komut < 4) {
        printf("\nOge eklemek icin 1, Oge Silmek icin 2,\n"
               "Siralamak icin 3, Cikis icin 4 e basiniz : ");

        scanf("%d", &komut);

        if (komut == 1) {
            int kapasite = sizeof(dizi) / sizeof(dizi[0]);
            printf("Sayi gir : ");
            scanf("%d", &anahtar);

            printf("\n Eklemeden Once: ");
            for (i = 0; i < n; i++)
                printf("%d  ", dizi[i]);

            // Anahtar yerleştirme
            n = ogeEkle(dizi, n, anahtar, kapasite);

            printf("\n Eklemeden sonra: ");
            for (i = 0; i < n; i++)
                printf("%d  ", dizi[i]);
        }
        if (komut == 2) {
            printf("Sayi gir : ");
            scanf("%d", &anahtar);

            printf("Silmeden Once\n");
            for (i = 0; i < n; i++)
                printf("%d  ", dizi[i]);

            n = ogeSil(dizi, n, anahtar);

            printf("\nSilmeden Sonra\n");
            for (i = 0; i < n; i++)
                printf("%d  ", dizi[i]);
        }
        if (komut == 3) {
            siralaYazdir(dizi, n, sira, i);
        }
    }
}