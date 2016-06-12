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

string s;
bool card[5][15]; int cnt[5], pnt; bool stop[5];

int kind(char c)
{
    if( c == 'S' ) return 0;
    if( c == 'H' ) return 1;
    if( c == 'D' ) return 2;
    if( c == 'C' ) return 3;

    return -1;
}

int num(char c)
{
    if( c == 'A' ) return 1;
    if( c == 'T' ) return 10;
    if( c == 'J' ) return 11;
    if( c == 'Q' ) return 12;
    if( c == 'K' ) return 13;

    return c-'0';
}

int main()
{
    while(getline(cin,s))
    {
        memset(card, false, sizeof(card));
        memset(cnt, 0, sizeof(cnt));
        memset(stop, false, sizeof(stop));

        for(int i = 0; i < 13; i++)
        {
            card[ kind(s[i*3+1]) ][ num(s[i*3]) ] = true;
            cnt[ kind(s[i*3+1]) ]++;
        }

        pnt = 0;

        for(int i = 0; i < 4; i++)
        {
            if( card[i][1] ){ pnt += 4; stop[i] = true; }
            if( card[i][13] )
            {
                pnt += 3;
                if( cnt[i] < 2 ) pnt--;
                else stop[i] = true;
            }
            if( card[i][12] )
            {
                pnt += 2;
                if( cnt[i] < 3 ) pnt--;
                else stop[i] = true;
            }
            if( card[i][11] )
            {
                pnt += 1;
                if( cnt[i] < 4 ) pnt--;
            }
        }

        if( pnt >= 16 && stop[0] && stop[1] && stop[2] && stop[3] )
        {
            printf("BID NO-TRUMP\n");
            continue;
        }

        for(int i = 0; i < 4; i++)
        {
            if( cnt[i] == 2 ) pnt += 1;
            if( cnt[i] <= 1 ) pnt += 2;
        }

        //printf("pnt %d", pnt); puts("");

        if( pnt < 14 ){ printf("PASS\n"); 
        continue; }

        int mxi = 0;
        for(int i = 1; i < 4; i++)
        {
            if( cnt[i] > cnt[mxi] ) mxi = i;
        }

        printf("BID ");

        if( mxi == 0 ){ printf("S"); }
        if( mxi == 1 ){ printf("H"); }
        if( mxi == 2 ){ printf("D"); }
        if( mxi == 3 ){ printf("C"); }

        //puts("");
        cout<<"\n";
    }
}
