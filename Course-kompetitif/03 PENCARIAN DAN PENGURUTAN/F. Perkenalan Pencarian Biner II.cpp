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

int n, q, a[100005], b[100005];
ll sum = 0, x[100005];

int bin(ll x){
	int l = 0, r = n - 1;
	while(l <= r){
		int m = (l + r) / 2;
		if(b[m] == x){
			return m + 1;
		}else if(b[m] < x){
			l = m + 1;
		}else{
			r = m - 1;
		}
	}
	return l + 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	For(i, n){
		cin >> a[i];
		sum += a[i];
		b[i] = sum;
	}
	cin >> q;
	For(i, q){
		cin >> x[i];
		cout << bin(x[i]) << endl;	
	}
}
