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
int lp(int y){
    if(y%400==0) return true;
    else if(y%100==0) return false;
    else if(y%4==0) return true;
    return false;
}
int dam(int mon,int y){
    if(mon==1) return 31;
    if(mon==2 and !lp(y)) return 28;
    else if(mon==2)return 29;
    if(mon==3) return 31;
    if(mon==4) return 30;
    if(mon==5) return 31;
    if(mon==6) return 30;
    if(mon==7) return 31;
    if(mon==8) return 31;
    if(mon==9) return 30;
    if(mon==10) return 31;
    if(mon==11) return 30;
    if(mon==12) return 31;
    return 31;
}
string sign(int day,int month){
    if (day >= 21 && month == 1 || day <= 19 && month == 2)
    return "aquarius";
  if (day >= 20 && month == 2 || day <= 20 && month == 3)
    return "pisces";
  if (day >= 21 && month == 3 || day <= 20 && month == 4)
    return "aries";
  if (day >= 21 && month == 4 || day <= 21 && month == 5)
    return "taurus";
  if (day >= 22 && month == 5 || day <= 21 && month == 6)
    return "gemini";
  if (day >= 22 && month == 6 || day <= 22 && month == 7)
    return "cancer";
  if (day >= 23 && month == 7 || day <= 21 && month == 8)
    return "leo";
  if (day >= 22 && month == 8 || day <= 23 && month == 9)
    return "virgo";
  if (day >= 24 && month == 9 || day <= 23 && month == 10)
    return "libra";
  if (day >= 24 && month == 10 || day <= 22 && month == 11)
    return "scorpio";
  if (day >= 23 && month == 11 || day <= 22 && month == 12)
    return "sagittarius";
  if (day >= 23 && month == 12 || day <= 20 && month == 1)
    return "capricorn";
    return "leo";
}
int main(){
       int t=IN();
       int p=1;
       while(t--){
           printf("%d ",p++);
        string s;
        cin>>s;
        int m=((s[0]-'0')*10)+(s[1]-'0');
        int d=((s[2]-'0')*10)+(s[3]-'0');
        int y=((s[4]-'0')*1000)+((s[5]-'0')*100)+((s[6]-'0')*10)+(s[7]-'0');       // 4567---2009
        int pre=280;
       // cout<<d<<" "<<m<<" "<<y<<endl;
        while(pre--){
            //flag=true;
            if(d!=dam(m,y)) {
                ++d;
            }
            else{
                d=1;
                ++m;
                
            }
            if(m==13 and d==1){
                ++y;
                m=1;
            }
            
       }
       //cout<<m<<"/"<<d<<"/"<<y<<" "<<sign(d,m)<<"\n";
       if(m<=9) cout<<"0"<<m<<"/";
       else cout<<m<<"/";
       if(d<=9) cout<<"0"<<d<<"/";
       else cout<<d<<"/";
       cout<<y<<" "<<sign(d,m)<<"\n";
       
}
}
