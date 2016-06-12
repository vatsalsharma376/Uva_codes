#include<bits/stdc++.h>
using namespace std;
int T, N, P;
int h[110];
 
int main() {
    cin>>T;
    while(T--) {
        cin>>N;
        cin>>P;
        for(int i = 0; i < P; i++) {
            scanf("%d", &h[i]);
        }
 
        int day = 1;
        int hartals = 0;
        while(day <= N) {
            // fri sat no hartal
            int mod = (day) % 7;
            if(mod != 0 && mod != 6) {
                bool hartal = false;
                for(int i = 0; i < P; i++) {
                    if((day) % h[i] == 0) {
                        hartal = true;
                    }
                }
                if(hartal) hartals++;
            }
 
            ++day;
        }
 
        cout<<hartals<<endl;
    }
}
