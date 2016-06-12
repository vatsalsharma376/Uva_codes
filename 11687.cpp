#include <bits/stdc++.h>
using namespace std;
char input[10000000];
int cnt;

 
int recursive (int x0)
{
    sprintf (input, "%d", x0);
    int x1 = strlen (input);
    cnt++;
    if ( x1 == x0 ) return cnt;
    recursive( x1 );
}
 
int main ()
{
    while ( cin>>input && strcmp (input, "END") ) {
        if ( strcmp (input, "1") == 0 ) {
            printf ("1\n");
            continue;
        }
        cnt = 1;
        printf ("%d\n", recursive (strlen (input)));
    }
 
    return 0;
}
