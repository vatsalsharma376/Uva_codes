#include <iostream>         //Rank 4
#include <bits/stdc++.h>
#define getcx getchar_unlocked
#define putcx putchar_unlocked
using namespace std;
template<class ty>void oup(ty x) {
        char s[20];
        short i=0;
        do{
            s[i++]=x%10+'0';
            x/=10;
        }while(x);
        --i;
        while(i>-1)putcx(s[i--]);
    }
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
 
typedef pair<int, int> ii;
typedef vector<int> vi;
 
vi pset(200005);
void initSet(int N)
{
    pset.assign(N, 0); for (int i = 0; i < N; i++) pset[i] = i;
}
int findSet(int i)
{
    return (pset[i] == i) ? i : (pset[i] = findSet(pset[i]));
}
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
void unionSet(int i, int j) { pset[findSet(i)] = findSet(j); }
 
int main()
{
    int V, E, u, v, w, cost,t,totalCost,airPorts;
    vector< pair<int, ii> > EdgeList;
 
    t=IN();
    for(int i = 0 ; i < t ; i++){
        totalCost = 0;
        V=IN(); E=IN(); cost=IN();
        EdgeList.clear();
        for (int j = 0; j < E; j++) {
            
            u=IN(); v=IN(); w=IN();
            EdgeList.push_back(make_pair(w, ii(u-1, v-1)));
        }
        sort(EdgeList.begin(), EdgeList.end());
 
        initSet(V);
        int k = 0;
        for (int j = 0; j < E; j++) {
            pair<int, ii> front = EdgeList[j];
            if(k > V - 1 || front.first >= cost)
                break;
            if (!isSameSet(front.second.first, front.second.second)) {
            totalCost += front.first;
            unionSet(front.second.first, front.second.second);
            k++;
            }
        }
        airPorts = 0;
        for(int j = 0 ; j < V ; j++)
            if(pset[j] == j){
                totalCost += cost;
                airPorts ++;
            }
 
         //printf("Case #%d: %d %d\n",(i+1),totalCost,airPorts);
         printf("Case #");
         oup(i+1);
         printf(": ");
         oup(totalCost); printf(" ");
         oup(airPorts);
         puts("");
    }
    return 0;
}
