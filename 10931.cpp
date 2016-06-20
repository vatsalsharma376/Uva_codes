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


int main(){
    int n;
    while(true){
        n=IN();
        if(!n) break;
        //string ton=to_string(n);
        //int l=ton.size();
        bitset<32> a(n);
        string ton=a.to_string();
        ton.erase(0, ton.find_first_not_of('0'));
        //int l=a;
        //The parity of 1 is 1 (mod 2).
        cout<<"The parity of "<<ton<<" is "<<a.count()<<" (mod 2).\n";
    }
}
