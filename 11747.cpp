#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge{
    int A;
    int B;
    int W;
}E[25005];
int N, M;
int Set[1005];
map<int, int> Map;

bool cmp(const Edge &A, const Edge &B);
void Initial(const int &N);
int Find_Root(int x);
void Union(const Edge &E, vector<int> &Ans);

int main()
{
    while (scanf("%d %d", &N, &M) && (N || M)) {
        Initial(N);
        int a, b;
        for (int i = 0, j = 1; i < M; ++i) {
            scanf("%d %d %d", &a, &b, &E[i].W);
            if (!Map[a]) Map[a] = j++;
            if (!Map[b]) Map[b] = j++;
            E[i].A = Map[a], E[i].B = Map[b];
        }

        sort(E, E + M, cmp);

        vector<int> Ans;
        for (int i = 0; i < M; ++i) {
            Union(E[i], Ans);
        }

        if (Ans.empty())
            puts("forest");
        else {
            printf("%d", Ans[0]);
            for (int i = 1; i < Ans.size(); ++i)
                printf(" %d", Ans[i]);
            printf("\n");
        }
    }
    return 0;
}
bool cmp(const Edge &A, const Edge &B){
    return A.W < B.W;
}
void Initial(const int &N)
{
    Map.clear();
    for (int i = 0; i <= N; ++i)
        Set[i] = i;
}
int Find_Root(int x)
{
    if (x == Set[x])
        return x;
    return Set[x] = Find_Root(Set[x]);
}
void Union(const Edge &E, vector<int> &Ans)
{
    int x = Find_Root(E.A);
    int y = Find_Root(E.B);

    if (x != y)
        Set[x] = y;
    else
        Ans.push_back(E.W);
}
