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

double a[100001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	For(i, n){
		cin >> a[i];
	}
	
	sort(a, a + n);
	double hasil = 0;
	if(n % 2 == 1){
		hasil = a[(n - 1) / 2];
		cout << fixed << setprecision(1) << hasil << endl;
	}else{
		hasil = (a[(n - 1) / 2] + a[(n - 1) / 2 + 1]) / 2;
		cout << fixed << setprecision(1) << hasil << endl;
	}
}
