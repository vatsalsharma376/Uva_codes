#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define vi vector<int> 
#define pb push_back
#define ff(x,y) for(int i=x;i<y;i++)
#define ffr(x,y) for(int i=x;i<=y;i++)
#define getcx getchar_unlocked
#define pcx putchar_unlocked
#define MX INT_MAX
int gcd(int a,int b){ if(a==0) return 0; return gcd(b%a,a);}
int IN () {
    bool minus = false;
    int result = 0;
    char ch;
    ch = getcx();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getcx();
    }
    if (ch == '-') minus = true; else result = ch-'0';
    while (true) {
        ch = getcx();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}

bitset<26> wok;
vector< vector<int> > v(26);
int n, m;
string s;
int main() {

    while(cin >> n >> m) {
        bool flag=true;
    getline(cin, s);
    
    wok.reset();

    getline(cin, s);
    for(char c : s) 
    {
        wok.set(c-'A');
    }
    for(int i=0; i<m; i++) {
        getline(cin, s);
        int a = s[0]-'A', b = s[1]-'A';
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int years = 0;
    while(wok.count() < n) {
        vector<int> wokeup;
        for(int cur=0; cur<26; cur++) {
        if(wok[cur]) continue;
        int wok_neighbors = 0;
        for(int neighbor : v[cur]) if(wok[neighbor]) wok_neighbors++;
        if(wok_neighbors >= 3) wokeup.push_back(cur);
        }

        if(wokeup.empty()) {
        cout << "THIS BRAIN NEVER WAKES UP\n";
        flag=0;
        break;
        }

        for(int i : wokeup) wok.set(i);
        years++;
    }
    if(!flag) continue;
    cout << "WAKE UP IN, " << years << ", YEARS\n";
    }
    
    return 0;
}
