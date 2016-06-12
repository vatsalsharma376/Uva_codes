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
/*int hcf(int n1, int n2){ if(!n2) return n1; return hcf(n2,n1%n2);}

int main(){
    int t;
    while(true){
        t=IN();
        if(!t) break;
        int lis[t];
        int x;
        for(int i=0;i<t;i++){
            x=IN();
            lis[i]=x;
        }
        
        double prs(0);
        for(int i=0;i<t-1;i++){         // i think this loop is causinng some errors 
            for(int j=i+1;j<t-1;j++){
                if(__gcd(j,i)==1) ++prs;
            }
        }
        //cout<<prs<<endl;
         double ans=0.0;
        if(!prs) printf("No estimate for this data set.\n");
        else{
            ans=sqrt(60.00/prs);
            printf("%.6f\n",ans);
        }
        
    }
}*/
 
 int main()  
 {  
   int n,GCD;  
   double ans=0;  
   while(true)
   
   {
       n=IN();
     if(n==0)  
     break;  
     int num[n+2];  
     int flag=0;  
     int count=0,count1=0;  
     for(int i=1;i<=n;i++)  
     {  
       num[i]=IN();  
     }  
     for(int i=1;i<=n;i++)  
     {  
       for(int j=1;j<=n;j++)  
       {  
        if(i!=j)  
        {  
          count1++;  
        }  
        if(i!=j)  
        {  
        GCD=__gcd(num[i],num[j]);  
        if(GCD==1)  
         {  
           flag=1;  
           count++;  
         }  
        }  
       }  
     }  
     if(flag==1)  
     {ans=(double(count)/2.0)/(double(count1)/2.0);  
     printf("%.6lf\n",sqrt(6.0/ans));}  
     else  
     printf("No estimate for this data set.\n");  
   }  
   return 0;  
 }  

