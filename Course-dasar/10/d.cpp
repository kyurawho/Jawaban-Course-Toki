#include <stdio.h>

bool primetest(int x){// loop ini untuk mengecek apakah nilainya 1 atau bukan
	if(x < 2){
		return true;//cek apakah 1 atau tidak
	}
	for(int i = 2; i < x; i++){// i=2 karena tidak perlu mengecek 1
		if(x%i == 0){//loop terus hingga mendapat modulus 0, terdapat banyak pohon faktor, akan masuk ke void faktorisasi
			return false;//false agar masuk ke else dr int main()
		}
	}
	return true;// jika prima dan lebih besar dari 2, dia akan print angkanya sendiri dari true ini, tidak masuk false karena for loop (i<x)
}

void faktorisasi(int x){
	for(int i = 2; i <= x; i++){//for loop untuk menghitung kembali sisa x, gtw kenapa batasnya sampe x
		int pangkat = 0;//menghitung pangkat
		while(x % i == 0){//fungsi pangkat, modulus == 0 untuk mencari apakah ada pangkat seletah x/=i
			x/=i;//seperti pohon faktor sendiri
			pangkat++;//menghitung pangkat
		}
		
		if(pangkat > 1){//mengaplikasikan pangkat lebih dari 1
			printf("%d^%d", i, pangkat);
			if(x != 1){//fungsi agar terprint x, tapi diakhir tidak print karena i = 1
				printf(" x ");
			}
		}else if(pangkat == 1){
			printf("%d", i);//mengaplikasikan pangkat 1
			if(x != 1){
				printf(" x ");
			}
		}
	}
}

int main(){
	int n;
	
	scanf("%d", &n);
	
	if(primetest(n)){
		printf("%d", n);
	}else{
		faktorisasi(n);
	}
}

/*input
693

output
3^2 x 7 x 11*/

//cobalah input 12 untuk menganalisi program
