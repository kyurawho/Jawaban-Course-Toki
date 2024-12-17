#include <iostream>
using namespace std;

int main(){
	string a, b;
	cin >> a;
	cin >> b;
	
	int beda = 0;
	
	if(a.length() == b.length() + 1){
		for(int i = 0; i < a.length(); i++){
			if(a[i] != b[i] && i != a.length() - 1){
				beda++;
				break;
			}else if(i == a.length() - 1 && beda == 0) beda++;
		}
		if(beda == 1) printf("Tentu saja bisa!");
		else printf("Wahh, tidak bisa :(");

//		int id1 = 0, id2 = 0;
//		while(id1 < a.length() && id2 < b.length() && beda < 2){
//			if(a.at(id1) != b.at(id2)){
//				beda++;
//				id1++;
//			}else{
//				id1++;
//				id2++;
//			}
//			
//			if(id2 == b.length() && beda == 0) beda++;
//		}
	}else printf("Wah, tidak bisa :(");
//	if(beda == 1) printf("Tentu saja bisa!");
//	else printf("Wah, tidak bisa :(");
}
