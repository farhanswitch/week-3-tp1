#include <stdio.h>

int main()
{

    printf("==================== Program Konversi Jarak ====================\n\n");
    // Deklarasi variabel untuk menyimpan nilai dari input user
    float distanceInKM;

    // Proses membaca input dari user. Input dari user berupa angka yaitu nilai jarak dalam satuan kilometer
    printf("Masukkan jarak dalam kilometer: ");
    scanf("%f", &distanceInKM);

    // Membersihkan buffer input
    getchar();

    // Proses mengkonversi jarak dari satuan kilometer ke satuan meter dan centimeter
    float distanceInM = (float)distanceInKM * 1000;
    float distanceInCM = (float)distanceInKM * 100000;

    // Proses menampilkan hasil konversi ke layar
    printf("\n--------------------\n");
    printf("Hasil konversi\n");
    printf("--------------------\n\n");
    printf("Tekan enter untuk menampilkan hasil konversi ke meter..");
    while (getchar() != '\n')
        ;
    printf("%.2f km = %.2f m\n", distanceInKM, distanceInM);
    printf("Tekan enter untuk menampilkan hasil konversi ke centimeter..");
    while (getchar() != '\n')
        ;
    printf("%.2f km = %.2f m\n", distanceInKM, distanceInCM);

    return 0;
}