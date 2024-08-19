#include <iostream>
#include <string>
using namespace std;

bool fungsi(string s){
	int len = s.length();
	if (len <= 1) return true;
	if(s[0] == s[len - 1])
	{
		string temp =s;
		temp.erase(len - 1, 1);
		temp.erase(0, 1);
		return fungsi(temp);
	}else{
		return false;
	}
}


int main(){
	string s;
	cin >> s;
	/*int len = s.length();
	cout << len << endl;*/
	if (fungsi(s)) printf("YA\n");
	else printf("BUKAN\n");
}
