#include <iostream>
using namespace std;

int main(){
	int angka = 0, n;
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		for(int j =1; j <= i; j++){
			cout << angka;
			angka++;
			angka %= 10;
			if(angka == 0){
				angka = 0;
			}
		}
		cout << endl;
	}
}
