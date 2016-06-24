#include <bits/stdc++.h>    // RANK 3 WOO!
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
    void oupx(unsigned long long x){
        char s[20];
        short i = 0;
        do{
            s[i++] = x % 10 + '0';
            x /= 10;
        }while(x);
        --i;
        while(i > -1)putcx(s[i--]);
    }
     
#define sz 1000000  
#define inf 1000000000  
long a[sz+2],L[sz+2],R[sz+2]; 
long long cnt;

void merge(long p,long q,long r){  
 long i,j,k,ind1,ind2;  

 for(i = p,ind1 = 1;i <= q;i++){  
  L[ind1++] = a[i];  
 }  
 L[ind1] = inf;  

 for(i = q+1,ind2 = 1;i <= r;i++){  
  R[ind2++] = a[i];  
 }  
 R[ind2] = inf;  

 i = j = 1;  

 for(k = p;k <= r;k++){  
  if(L[i] > R[j]){  
   cnt += ind1 - i;  
   a[k] = R[j];  
   j++;  
  }  
  else{  
   a[k] = L[i];  
   i++;  
  }  
 }  
}  

void mergeSort(long p,long r){  
 if(p < r){  
  long q = (p+r)/2;  
  mergeSort(p,q);  
  mergeSort(q+1,r);  
  merge(p,q,r);  
 }  
}  

int main(){  
 long i,n;  

 while(scanf("%ld",&n) == 1){  
  for(i = 1;i <= n; i++){  
   a[i]=IN(); 
  }  
  cnt = 0;  
  mergeSort(1,n);  
  oupx(cnt);
  printf("\n");
 }  

 return 0;  
}
