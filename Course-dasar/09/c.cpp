#include <stdio.h>
#include <cmath>

int main(){
	int a, arr[10000001], x, b = 1, n;
	scanf("%d", &a);
	
	for(int i = 0; i < a; i++){
		scanf("%d", &arr[i]);
	}
	
	x = arr[0];
	for(int i = 0; i < a; i++){
		if(arr[i] > 0){
			n = 1;//untuk menetralkan kembali, ketika loop untuk arr selanjutnya, ia ttp bernilai 1/mulai dari awl
			for(int j = i+1; j < a; j++){//i+1 untuk langsung masuk ke arr kedua
				if(arr[i] == arr[j]){//mengecek apakah ada yang memiliki angka sama
					arr[j]=0;
					n++;
				}
			}
		}
		if(n > b){//jumlahnya lebih banyak otomatis masuk sini, jadi gak pakai pengecekan
			b = n;//ketika b sudah menjadi angka 2, dia terus menjadi 2 meskipun loop
			x = arr[i];
		}else{
			if(n == b){//pengecekan apabila jumlah sama
				if(arr[i] > x){//pengecekan mana yang lebih besar; x nilainya sudah terdaftar sebagai salah satu array, jadi dapat melakukan pengecekan dengan array lainnya
					b=n;
					x = arr[i];
				}
			}
		}
	}
	
	printf("%d", x);
}

/*test program
6
1 3 2 4 1 4*/
