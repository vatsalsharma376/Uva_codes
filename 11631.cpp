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

struct Street
{
    int u, v, length;
};

bool comp(const Street &s1, const Street &s2)
{
    return s1.length < s2.length;
}

int getGroup(vector<int> &groups, int u)
{/*
    return groups[u] == u? 
        u : groups[u]=getGroup(groups, groups[u]);
        */
        if(groups[u]==u) return u;
        return groups[u]=getGroup(groups, groups[u]);
}

int main()
{  
    int m, n;
    while (true)
    
    {
        m=IN(); n=IN();
        if(!m and !n) return 0;
        vector<Street> streets;
        vector<int> groups(m);
        int streetCount = 0;
        int originalCost = 0, cost = 0;

        for (int i = 0; i < n; ++i)
        {
            Street st;
            cin >> st.u >> st.v >> st.length;
            streets.push_back(st);
            originalCost += st.length;
        }

        sort(streets.begin(), streets.end(), comp);
        for (int i = 0; i < m; ++i)
            groups[i] = i;

        // Kruskal's algorithm.    
        for (size_t i = 0; i < streets.size() && streetCount < m - 1; ++i)
        {
            Street &st = streets[i];
            int groupU = getGroup(groups, st.u);
            int groupV = getGroup(groups, st.v);
            if (groupU != groupV)
            {
                cost += st.length;
                groups[groupV] = groupU;
                ++streetCount;
            }
        }
        //cout << originalCost - cost << endl;
        printf("%d\n",originalCost-cost);
    }
    return 0;
}           
