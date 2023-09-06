#include <stdio.h>
#include <stdbool.h>
// Hitung harga setelah diskon. Diskon dihitung berdasarkan total harga belanja
float getDiscount(int price)
{
    /*
    buat variabel dengan tipe data float dengan nilai diambil dari parameter price .
    Kita perlu melakukan ini karena hasil perhitungan diskon bisa saja menghasilkan bilangan desimal
    */
    int discount = 0;

    // Diskon 10 %
    int discount10 = 10;
    // Diskon 20%
    int discount20 = 20;
    // Diskon 30%
    int discount30 = 30;
    // Hitung  diskon jika total belanja antara Rp 200.000 sampai Rp 500.000
    if (price >= 200000 && price <= 500000)
    {
        // set nilai discount dengan cara hitung 10% dari total belanja
        discount = price * discount10 / 100;
    }
    // Hitung harga setelah diskon jika total belanja antara Rp 500.000 sampai Rp 1.000.000
    else if (price > 500000 && price <= 1000000)
    {
        // set nilai discount dengan cara hitung 20% dari total belanja
        discount = price * discount20 / 100;
    }
    // Hitung harga setelah diskon jika total belanja lebih dari Rp 1.000.000
    else if (price > 1000000)
    {
        // set nilai discount dengan cara hitung 30% dari total belanja
        discount = price * discount30 / 100;
    }

    // Kembalikan nilai  diskon
    return discount;
}

int main()
{

    printf("---------------------------------------------\n");
    printf("PROGRAM UNTUK MENGHITUNG DISKON BELANJA\n");
    printf("---------------------------------------------\n\n");
    // Simpan nilai total harga dari input user dan menyimpan jumlah transaksi yang dilakukan user dalam satu bulan
    int totalPrice = 0, totalTransaction;
    // Simpan total diskon dari total belanja dan diskon dari jumlah transaksi
    int transactionDiscount = 0, loyaltyDiscount = 0, priceAfterDiscount = 0;
    // Persentase diskon jika user melakukan transaksi minimal 4x dalam satu bulan
    int discount20 = 20;
    // Buat variabel untuk menyimpan apakah user masih ingin input transaksi
    bool inputAgain = true;
    // Perulangan untuk meminta input user
    while (inputAgain == true)
    {
        int nominal;
        printf("Masukkan nilai total belanja (rupiah): ");
        scanf("%d", &nominal);
        // Bersihkan buffer input
        getchar();
        // Menambahkan harga yang diinput oleh user ke total nominal harga
        totalPrice += nominal;
        // Hitung nilai diskon berdasarkan total belanja
        transactionDiscount += getDiscount(nominal);
        // Jumlah transaksi user dalam satu bulan bertambah 1
        totalTransaction++;

        while (1)
        {
            char isContinue;
            // Tanya ke user apakah ingin menginput data transaksi lagi
            printf("Belanja lagi? (Y/N) ");
            scanf("%c", &isContinue);
            // Bersihkan buffer input
            getchar();
            // Jika user tidak ingin menginput data transaksi lagi, maka kita hentikan loopnya
            if (isContinue == 'n' || isContinue == 'N')
            {
                inputAgain = false;
                break;
            }
            // Jika user masih ingin input transaksi lagi
            else if (isContinue == 'Y' || isContinue == 'y')
            {
                break;
            }
            // Jika user input character lain selain huruf y / n
            else
            {
                printf("Tolong masukkan 'y' jika ingin melanjutkan transaksi dan 'n' jika ingin berhenti input transaksi\n");
            }
        }
    }

    // Hitung harga setelah diskon berdasarkan nominal transaksi
    priceAfterDiscount = totalPrice - transactionDiscount;
    // Jika jumlah transaksi dalam satu bulan 4 atau lebih maka akan mendapatkan diskon tambahan yaitu 20% dari total harga
    if (totalTransaction >= 4)
    {
        loyaltyDiscount = priceAfterDiscount * discount20 / 100;
    }
    // Hitung harga setelah diskon
    priceAfterDiscount -= loyaltyDiscount;

    // Menampilkan hasil ke user
    printf("\n\nHarga akhir : Rp. %d\n\n", priceAfterDiscount);
    printf("---------------------------------------------\n");
    printf("Rekap Transaksi\n");
    printf("%-40s", "Total belanja");
    printf(": Rp. %d\n", totalPrice);
    printf("%-40s", "Diskon dari total belanja");
    printf(": Rp. %d\n", transactionDiscount);
    printf("%-40s", "Diskon dari jumlah transaksi");
    printf(": Rp. %d\n", loyaltyDiscount);
    printf("---------------------------------------------\n");

    return 0;
}
