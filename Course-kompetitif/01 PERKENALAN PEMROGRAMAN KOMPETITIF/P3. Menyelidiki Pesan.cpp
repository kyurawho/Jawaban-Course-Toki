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
	int n;
	cin >> n;
	
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	
	map <char, char> m1, m2;
	bool ok = 1;
	
	For(i, n){
		char a, b;
		a = s1[i], b = s2[i];
		
		if(m1.count(a) && m1[a] != b){
			cout << "Pak Dengklek bingung";
			ok = 0;
			break;
		}else{
			m1[a] = b;
		}
		
		if(m2.count(b) && m2[b] != a){
			cout << "Pak Dengklek bingung";
			ok = 0;
			break;
		}else{
			m2[b] = a;
		}
	}
	
	if(ok){
		For(i, n){
			if(m2.count(s3[i])){
				cout << m2[s3[i]];
			}else{
				cout << '?';
			}
		}
	}
}
