#include <bits/stdc++.h>
#define getcx getchar_unlocked
#define putcx putchar_unlocked
    using namespace std;

int main()
{  
    int t;
    cin>>t;
    int p=0;
    while(t--){
        printf("Case #%d: ",++p);
        int sh,sm,ss,eh,em,es;
        scanf("%d/%d/%d",&sh,&sm,&ss);  //current date
        scanf("%d/%d/%d",&eh,&em,&es);  //birth date
        int k=ss-es;
        if(sm<em) --k;
        else if(sm==em)
            if(sh<eh) --k;
        
        
        if(k<0){
            //invalid birth can't be after
            cout<<"Invalid birth date\n";
        }
        else if(k>130){
            //invalid again
            cout<<"Check birth date\n";
        }
        else {
            //invalid again
            cout<<k<<"\n";
        }
        
    }
    return 0;
}
