#include<bits/stdc++.h>       // RANK 21
using namespace std;
#define ll long long 
#define vi vector<int> 
#define pb push_back
#define ff(x,y) for(int i=x;i<y;i++)
#define ffr(x,y) for(int i=x;i<=y;i++)
#define getcx getchar_unlocked
#define pcx putchar_unlocked
#define MX INT_MAX
//int gcd(int a,int b){ if(a==0) return 0; return gcd(b%a,a);}
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

int main(){
    int i = 0, j, n, len, flag[101];
    char ch[101], chance, t;
    while(true)
    
    {
        n=IN();
        if(n==-1) break;
        memset(ch, 0, sizeof(ch));
        memset(flag, 0, sizeof(flag));
        scanf("%s", ch);
        getcx();
        len = strlen(ch);
        for(i=0; i<=7;)
        {
            t = 0;
            chance = getcx();
            if(i == 7 && chance != '\n') continue;   
            else if(chance == '\n') break;
            for(j=0; j<len; j++)
            {
                if(ch[j] == chance)
                {
                    t = 1;
                    flag[j] = 1;
                }
            }
            if(t == 0) i++;
        }
        printf("Round %d\n", n);
            for(j=0; j<len && flag[j] == 1; ++j);
            if(j<len) {if(i != 7)printf("You chickened out.\n");
                      else printf("You lose.\n");
            }else printf("You win.\n");
        
    }
    return 0;
}
