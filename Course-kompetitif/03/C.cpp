#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<string, string> vect[100005];
int n, q, ans;
string name;
int binser(){
    int l = 0, r = n - 1, m;

    while(l <= r){
        m = (l + r) / 2;

        if(vect[m].first == name) return m;
        if(vect[m].first < name) l = m + 1;
        else r = m - 1;
    }

    return -1;
}

void solve(){
    cin >> name;

    ans = binser(); 
    
    if(ans == -1) cout << "NIHIL" << endl;
    else cout << vect[ans].second << endl;
}

int main(){
	cin >> n >> q;
	for(int i= 0; i < n; i++){
		cin >> vect[i].first >> vect[i].second;
	}
	
	while(q--){
		solve();
	}
}
