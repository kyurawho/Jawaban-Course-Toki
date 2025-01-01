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

int n, k;
int a[100005], b[100005];
ll sum = 0, x[100005];

int bin(ll z){
	int l = 0, r = n - 1;
	while(l <= r){
		int m = l + (r - l) / 2;
		if(x[m] <= z){
			l = m + 1;
		}else{
			r = m - 1;
		}
	}
	return l;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	
	For(i, n){
		cin >> a[i];
		sum += a[i];
		x[i] = sum;
	}
	
	For(i, k){
		cin >> b[i];
		cout << bin(b[i]) << endl;
	}
}
