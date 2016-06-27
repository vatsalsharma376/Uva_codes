#include <bits/stdc++.h>
#define getcx getchar_unlocked
#define putcx putchar_unlocked
    using namespace std;
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


static const int INF = 1000;

int main()
{    
    int Case = 1, T;
    T=IN();
    while ( T-- )
    { 
        int N=IN(), R=IN();
        
        
        vector<vector<int> > buildings(N, vector<int>(N, INF));
        for (int i = 0; i < N; ++i)
            buildings[i][i] = 0;
        for (int i = 0; i < R; ++i)
        {
            int u=IN(), v=IN();
            
            buildings[u][v] = 1;
            buildings[v][u] = 1;
        }
        
        // Floyd-Warshall algorithm.
        for (int k = 0; k < N; ++k)
            for (int i = 0; i < N; ++i)
                for (int j = 0; j < N; ++j)
                   buildings[i][j] = min(buildings[i][j], buildings[i][k] + buildings[k][j]);

        int s, d;
        s=IN(); d=IN();

        int minTime = 0;
        for (int i = 0; i < N; ++i)
            if (buildings[s][i] != INF 
                && buildings[i][d] != INF)
            {
                minTime = max(minTime, buildings[s][i] + buildings[i][d]);
            }
        //cout << "Case " << Case++ << ": " << minTime << "\n";
        printf("Case %d: %d\n",Case++,minTime);
    }
    return 0;
}
