// Rank 7 :)
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define vi vector<int> 
#define pb push_back
#define getcx getchar_unlocked
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

 
char sieve[500000];
int dpCount[1000000];
 
char isPrime(int n){
    if (n == 2)
        return 1;
    else if (! (n % 2))
        return 0;
    else {
        return sieve[(n-1)/2];
    }
}
 
int digitSum(int a){
    static char tempStr[10];
    static int len, sum;
    int i;
 
    sum = 0;
    sprintf(tempStr,"%d",a);
    len = strlen(tempStr);
    for (i = 0; i < len; i++){
        sum += (tempStr[i] - '0');
    }
 
    return sum;
}
 
void init(){
    int i, cur;
    memset(sieve,1,sizeof(sieve));
    memset(dpCount,0,sizeof(dpCount));
 
    /* sieve of eratosthenes */
    sieve[0] = 0;
    for (i = 3; i <= 1001; i+=2){
        if (sieve[(i-1)/2]){
            cur = 3*i;
            while (cur < 1000000){
                sieve[(cur-1)/2] = 0;
                cur = cur + i + i;
            }
        }
    }
 
    /* DP */
    dpCount[0] = 0;
    dpCount[1] = 0;
    dpCount[2] = 1;
    for (i = 3; i < 1000000; i++){
        if (isPrime(i) && isPrime( digitSum(i) )){
            dpCount[i] = dpCount[i-1] + 1;
        }
        else {
            dpCount[i] = dpCount[i-1];
        }
    }
}
 
int main(){
    int N, i, first, last;
 
    init();
 
    N=IN();
    for (i = 0; i < N; i++){
        first=IN(); last=IN();
        printf("%d\n",dpCount[last]-dpCount[first-1]);
    }
 
    return 0;
}
