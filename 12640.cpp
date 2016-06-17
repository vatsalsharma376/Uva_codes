#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define vi vector<int> 
#define pb push_back
#define ff(x,y) for(int i=x;i<y;i++)
#define ffr(x,y) for(int i=x;i<=y;i++)     
#define getcx getchar_unlocked
#define pcx putchar_unlocked            
#define MX INT_MAX


int sub(vector<int> a , int size)
{
   int max_so_far = 0, max_ending_here = 0;
   for (int i = 0; i < size; i++)
   {
       max_ending_here = max_ending_here + a[i];
       if (max_ending_here < 0)
           max_ending_here = 0;

       else if (max_so_far < max_ending_here)
           max_so_far = max_ending_here;
   }
   return max_so_far;
}

int main(){
    //ios_base:sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    while(getline(cin,s)){
        stringstream ss(s);
        
        vector<int> a;
        int x;
        while(ss>>x) a.pb(x);
        cout<<sub(a,a.size())<<"\n";
    }
}
