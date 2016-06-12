// TIME TAKEN: 0.060s I know prettty bad :D
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
bool chk(int i,int j,int k,int a,int b,int c){
    int s=0;
    if((i+j+k)==a) ++s;
    if((i*j*k)==b) ++s;
    if(((i*i)+(j*j)+(k*k))==c) ++s;
    return s==3? true:false;
}
int main(){
    int t=IN();
    while(t--){
        int a,b,c;
        a=IN(); b=IN(); c=IN();
        bool flag=true;
        int x=-1,y=-1,z=-964;
        for(int i=-100;i<100;i++){
            flag=true;
            for(int j=-100;j<100;j++){
                
                for(int k=-100;k<100;k++){
                    
                    if(chk(i,j,k,a,b,c) and i!=j and j!=k and i!=k){
                        x=i; y=j; z=k;
                        flag=false;
                        break;
                    }
                }
                if(!flag) break;
            }
            if(!flag) break;
        }
        if(z==-964) printf("No solution.\n");
        else printf("%d %d %d\n",x,y,z);
    }
    return 0;
}
