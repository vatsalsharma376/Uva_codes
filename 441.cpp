#include <bits/stdc++.h>
#define getcx getchar_unlocked
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

int main() {
    int k;
    bool flag=false;
while(true){
    k=IN();
    if(!k){
    	return 0;	
    } 
    if(flag) printf("\n");
    flag=true;
   	//else printf("\n");
    int S[k];
    
for (int i = 0; i < k; i++) S[i]=IN();

for (int a = 0; a < k - 5; a++)
for (int b = a + 1; b < k - 4; b++)
for (int c = b + 1; c < k - 3; c++)
for (int d = c + 1; d < k - 2; d++)
for (int e = d + 1; e < k - 1; e++)
for (int f = e + 1; f < k; f++)
printf("%d %d %d %d %d %d\n",S[a],S[b],S[c],S[d],S[e],S[f]);
//flag=true;
 //if(flag) printf("\n");   
}
    return 0;
}
