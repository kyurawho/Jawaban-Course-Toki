#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define fi first
#define se second
#define pb push_back
#define pq priority_queue
#define mp make_pair
#define all(x) x.begin(), x.end()
#define Repp(i, l, r, a) for (int i = l; i < r; i += a)
#define Rep(i, l, r) Repp(i, l, r, 1)
#define For(i, n) Rep(i, 0, n)
#define Fori(i, n) Rep(i, 1, n + 1)
#define Each(x, v) for (auto x : v)
#define Repd(i, l, r) for (int i = r - 1; i >= l; i--)
#define Ford(i, n) Repd(i, 0, n)
#define endl "\n"

typedef pair <int, int> pii;
typedef pair <int, pii> piii;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string juri;
	cout << "?" << endl << "1 2 3 4" << endl << "5 6 7 8" << endl;
	cout << flush;
	cin >> juri;
	if(juri == "KIRI"){
		cout << "?" << endl << "1 2" << endl << "3 4" << endl;
		cout << flush;
		cin >> juri;
		if(juri == "KIRI"){
			cout << "?" << endl << "1" << endl << "2" << endl;
			cout << flush;
			cin >> juri;
			if(juri == "KIRI"){
				cout << "! 1";
				cout << flush;
			}else{
				cout << "! 2";
				cout << flush;
			}
		}else{
			cout << "?" << endl << "3" << endl << "4" << endl;
			cout << flush;
			cin >> juri;
			if(juri == "KIRI"){
				cout << "! 3";
				cout << flush;
			}else{
				cout << "! 4";
				cout << flush;
			}
		}
	}else{
		cout << "?" << endl << "5 6" << endl << "7 8" << endl;
		cout << flush;
		cin >> juri;
		if(juri == "KIRI"){
			cout << "?" << endl << "5" << endl << "6" << endl;
			cout << flush;
			cin >> juri;
			if(juri == "KIRI"){
				cout << "! 5";
				cout << flush;
			}else{
				cout << "! 6";
				cout << flush;
			}
		}else{
			cout << "?" << endl << "7" << endl << "8" << endl;
			cout << flush;
			cin >> juri;
			if(juri == "KIRI"){
				cout << "! 7";
				cout << flush;
			}else{
				cout << "! 8";
				cout << flush;
			}
		}
	}
}
