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
	int n, m, k;
	cin >> n >> m >> k;
	
	int petak[n][m];
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> petak[i][j];
		}
	}
	
	int nans = -1, mans = -1;
	bool menarik = 0;
	for(int j = 0; j < m; j++){
		for(int i = 0; i < n; i++){
		unsigned int kemenarikan;
            if(m==1 && n==1) {
                kemenarikan=0;
            } else if(m==1) {
                kemenarikan=((i==0) ? 0:petak[i-1][0]) * ((i==n-1) ? 0:petak[i+1][0]);
            } else if(n==1) {
                kemenarikan=((j==0) ? 0:petak[0][j-1]) * ((j==m-1) ? 0:petak[0][j+1]);
            } else if(i==0 && j==0) {
                kemenarikan=petak[1][0]*petak[0][1];
            } else if(i==n-1 && j==0) {
                kemenarikan=petak[i-1][0]*petak[i][1];
            } else if(i==0 && j==m-1) {
                kemenarikan=petak[0][j-1]*petak[1][j];
            } else if(i==n-1 && j==m-1) {
                kemenarikan=petak[i][j-1]*petak[i-1][j];
            } else if(i==0) {
                kemenarikan=petak[i][j-1]*petak[i][j+1]*petak[i+1][j];
            } else if(i==n-1) {
                kemenarikan=petak[i][j-1]*petak[i][j+1]*petak[i-1][j];
            } else if(j==0) {
                kemenarikan=petak[i-1][j]*petak[i+1][j]*petak[i][j+1];
            } else if(j==m-1) {
                kemenarikan=petak[i-1][j]*petak[i+1][j]*petak[i][j-1];
            } else {
                kemenarikan=petak[i][j-1]*petak[i][j+1]*petak[i-1][j]*petak[i+1][j];
            }
            if(kemenarikan==k) {
                menarik=true;
                nans = i + 1;
                mans = j + 1;
                break;
            }
        }
        if(menarik) break;
	}
	
	if(menarik) cout << nans << ' ' << mans << endl;
	else cout << "0 0" << endl;
}
