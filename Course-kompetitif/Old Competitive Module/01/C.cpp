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

int N;
string s;

bool solve(string a){
	if(a.length() < s.length() - 1) return false;
		
	if(s[0] == '*'){
		for(int i = s.length() - 1; i > 0; i--){
			if(s[i] != a[a.length() - (s.length() - i)]) return false;
		}
	}else if(s[s.length() - 1] == '*'){
		for(int i = 0; i < s.length() - 1; i++){
			if(s[i] != a[i]) return false;
		}
	}else{
		for(int i = s.length() - 1; i > 0; i--){
			if(s[i] == '*') break;
			if(s[i] != a[a.length() - (s.length() - i)]) return false;
		}
		
		for(int i = 0; i < N; i++){
			if(s[i] == '*') break;
			if(s[i] != a[i]) return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> s;
	cin >> N;
	while(N--){
		string a;
		cin >> a;
		if(solve(a)) cout << a << endl;
	}
}
