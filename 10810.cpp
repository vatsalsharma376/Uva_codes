#include <bits/stdc++.h>
using namespace std;
#define getcx getchar_unlocked
#define putcx putchar_unlocked
long int IN () {
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


#define sz 5000000
#define inf 1000000000
long long int a[sz+2],cnt,L[sz+2],R[sz+2];

void merge(long p,long q,long r){
 long i,j,k,ind1,ind2;

 for(i = p,ind1 = 1;i <= q;i++){
  L[ind1++] = a[i];
 }
 L[ind1] = inf;

 for(i = q+1, ind2 = 1;i <= r;i++){
  R[ind2++] = a[i];
 }
 R[ind2] = inf;

 i = j = 1;

 for(k = p;k <= r;k++){
  if( L[i] > R[j] ){
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
 if( p < r){
  long q = (p+r)/2;
  mergeSort(p,q);
  mergeSort(q+1,r);
  merge(p,q,r);
 }
}

int main(){
 long i,n;

 while(true){
     n=IN();        // there is n't any better algo for polynomial eval and with your I/O functiona also i got // I am looking now.
     if(!n) return 0;
  for( i = 1; i <= n; i++){//Polynomial evaluation is related to this problem? Anyway the problem looks easy. :) no not this yes damn easy!! :P
   cin>>a[i];
  }
  cnt = 0;
  mergeSort(1,n);
  printf("%lld\n",cnt);

 }

 return 0;
}
