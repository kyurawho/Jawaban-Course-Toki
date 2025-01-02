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

struct Activity{
	int start, end;
};

Activity arr[100005];

bool compare(Activity s1, Activity s2){
	return (s1.end < s2.end);
}

int solve(Activity arr[], int n)
{
	sort(arr, arr + n, compare);
	
	int total = 0;
	
    int i = 0;

    for (int j = 1; j < n; j++) {
        if (arr[j].start >= arr[i].end) {
            total++;
            i = j;
        }
    }
    return ++total;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	
	For(i, n){
		int temp;
		cin >> arr[i].start >> temp;
		arr[i].end = arr[i].start + temp;
	}
	
	cout << solve(arr, n) << endl;
}
