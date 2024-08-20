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
	int n, q;
	cin >> n >> q;
	vector<pair <string, int>> vect;
	For(i, n){
		string s;
		int num;
		cin >> s >> num;
		vect.push_back(make_pair(s, num));
	}
	
	
//	For(i, q){
//		string nama;
//		cin >> nama;
//		int ans = 0;
//		int l = 0, r = n - 1;
//		while(l <= r){
//			int m = l + (r - l) / 2;
//			
//			if(nama == vect[m].first){
//				ans = vect[m].second;
//				break;
//			}
//			
//			if(strcmp(nama, vect[m].first) > 0){
//				l = m + 1;
//			}else{
//				r = m - 1;
//			}
//		}
//		if(ans) cout << ans << endl;
//		else cout << "NIHIL" << endl;
//	}
	For(i, q){
		string nama;
		cin >> nama;
		int ans = 0;
		For(i, n){
			if(nama == vect[i].first){
				ans = vect[i].second;
				break;
			}
		}
		if(ans) cout << ans << endl;
		else cout << "NIHIL" << endl;
	}
}
