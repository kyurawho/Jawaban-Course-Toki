#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	int k;
	
	cin >> s;
	cin >> k;
	
	for(int i=0; i<s.length(); i++){
		if(s[i]+k > 'z'){
			s[i] = s[i]+k-26;
		}else{
			s[i] += k;
		}
	}
	cout << s << endl;
	
	return 0;
}

