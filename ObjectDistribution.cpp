#include <iostream>
#include <cmath>

using namespace std;

// Faktorial Function
int factorial(int n){
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

//Combination Function
int combination(int n, int m){
    return factorial(n) / (factorial(n-m) * factorial(m));
}

// Function for Stirling Number of Second Kind 
int SNum(int o, int k, int i){
    return pow(-1, i) * combination(k, i) * pow(k-i, o);
}

int SNumI(int a, int b){
    int SNumI_num = 0;
    for (int j = 0; j <= b; j++){
        SNumI_num += SNum(a, b, j);
    }
    SNumI_num = SNumI_num / factorial(b);
    return SNumI_num;
}

int main ()
{
    int objek, ruang;
    int hasil = 0;
    cout << "Masukkan jumlah objek ";
    cin >> objek;
    cout << "Masukkan jumlah ruang ";
    cin >> ruang;
    for (int c = 1; c <= ruang; c++) {
        hasil = hasil + SNumI(objek, c);
    }
    cout << hasil;
}