#include <iostream>
#include <cstring>

using namespace std;

struct phonebook {
    char name[11];
    char num[7];
};

typedef struct phonebook Phonebook;
Phonebook PB[100001];
unsigned int n;

void solve(char *);

int main() {
    unsigned int q;
    cin>>n>>q;
    for(unsigned int i=1; i<=n; i++) {
        cin>>PB[i].name>>PB[i].num;
    }

    for(unsigned int i=1; i<=q; i++) {
        char search[11];
        cin>>search;
        solve(search);
    }
    return 0;
}

void solve(char search[]) {
    unsigned int l = 1, r = n;
    char num[7] = "NIHIL";
    while(l <= r && (strcmp(num, "NIHIL") == 0)) {
        unsigned int m = (r + l)/2;
        if(strcmp(search, PB[m].name) > 0) {
            l = m + 1;
        } else if (strcmp(search, PB[m].name) < 0) {
            r = m - 1;
        } else {
            strcpy(num, PB[m].num);
        }
    }
    cout<<num<<endl;
}