#include <bits/stdc++.h>
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
        int pas=ss-es;
        if(sm<em) --pas;
        else if(sm==em)
            if(sh<eh) --pas;
        
        
        if(pas<0){
            //invalid birth can't be after
            cout<<"Invalid birth date\n";
        }
        else if(pas>130){
            //invalid again
            cout<<"Check birth date\n";
        }
        else {
            cout<<pas<<"\n";
        }
        
    }
    return 0;
}
