#include <bits/stdc++.h>
using namespace std;
//1, 8, 27, 64, 125, 216, 343, 512, 729, 1000, 1331, 1728, 2197, 2744, 3375, 4096, 4913, 5832, 6859, 8000, 9261
 
int m, coins[] = {1, 8, 27, 64, 125, 216, 343, 512, 729, 1000, 1331, 1728, 2197, 2744, 3375, 4096, 4913, 5832, 6859, 8000, 9261 };
long long int ways[30010] = { 0 };
 
int main() {
    ways[0] = 1;
    for(int i = 0; i <21 ; i++)
        for(int j = coins[i]; j <= 10000; j++)
            ways[j] += ways[j - coins[i]];
    while(scanf("%d", &m) == 1)
        printf("%lld\n",ways[m]);
}
