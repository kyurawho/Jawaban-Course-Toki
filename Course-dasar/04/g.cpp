#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int a, b, c, d, jarak;
	cin >> a >> b >> c >> d;
	jarak = abs (a-c) + abs(b-d);
	cout << jarak << endl;
}
