#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	cin >> s;
		
	int a = s.find("_"), x = 0;
	
	if(a >= 0){
		while(a >= 0){
			s[a + 1] -= 'a' - 'A';// ini masalanya keknya
			s.erase(s.find("_"), 1);
			a = s.find("_");
		}
	}else{
		while(s.length() != x+1){
			if(s[x] < 'Z'){
				s[x] += 'a' - 'A';
				s.insert(x, "_");
				x++;
			}else{
				x++;
			}
		}
	}
	cout << s << endl;
}

//input
//aa_bb_cc
//aaBbCc
//012345
