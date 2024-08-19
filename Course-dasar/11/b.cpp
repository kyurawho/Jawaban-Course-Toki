#include <stdio.h>
#include <string>
using namespace std;

int main(){
	string a, b;
	scanf("%s %s", &a, &b);
	int x = b.length();
	while(a.find(b) <= 100){
		a.erase(a.find(b), x);
	}
	printf("%s", a.c_str());
}
