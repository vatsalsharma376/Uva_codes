#include<bits/stdc++.h>     // RANK 7 
using namespace std;
#define ll long long 
#define vi vector<int> 
#define pb push_back
#define ff(x,y) for(int i=x;i<y;i++)
#define ffr(x,y) for(int i=x;i<=y;i++)     
#define getcx getchar_unlocked
#define putcx putchar_unlocked            
#define MX INT_MAX
unsigned long long int IN () {
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
void oupx(unsigned long long int x){
    char s[20];
    short i = 0;
    do{
        s[i++] = x % 10 + '0';
        x /= 10;
    }while(x);
    --i;
    while(i > -1)putcx(s[i--]);
}

//using namespace std;

//typedef vector<int> vi;

int main()
{
	int T=IN();
	while (T--) {
    	vector<int> a;
    int na=IN();
    
    while (na--) {
      int ai=IN();
      a.push_back(ai);
    }

    int s = 0;
    for (int i=1; i<a.size(); ++i) {
      for (int j=0; j<i; ++j) {
        if (a[j]<=a[i]) {
          ++s;
        }
      }
    }
    oupx(s);
    puts("");
	}
	return 0;
}
