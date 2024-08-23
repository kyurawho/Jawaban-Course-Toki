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

int n;
int arr[10];
int update[3][2] = {{3, 0}, {0, 3}, {1, 1}};

bool solve(int a, int b, int cur[]){
	if(a >= n - 1){
		For(i, n){
			if(cur[i] != arr[i]) return 0;
		}
		return 1;
	}
	
	bool res = 0;
	int newa, newb;
	if (b + 1 >= n) {
		newa = a+1;
		newb = a+2;
	} else {
		newa = a;
		newb = b+1;
	}
	
	for (int i = 0; i < 3; i++) {
		cur[a] += update[i][0];
		cur[b] += update[i][1];
		res = res or solve(newa, newb, cur);
		cur[a] -= update[i][0];
		cur[b] -= update[i][1];
	}

	return res;
}
	

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		
		int total = 0;
		For(i, n){
			cin >> arr[i];
		}
		
		int empty[6] = {0, 0, 0, 0, 0, 0};
		
		if(solve(0, 1, empty)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
