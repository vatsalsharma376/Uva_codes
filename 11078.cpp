#include <bits/stdc++.h>
#define getcx getchar_unlocked
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
int main() {
  int T=IN(), n;
  
  while (T--) {
    n=IN();
    int i, j, max, ans = -2e9;
    max=IN();
    for (i = 1; i < n; i++) {
      j=IN();
      ans = max - j > ans ? max - j : ans;
      max = j > max ? j : max;
    }
    printf("%d\n", ans);
  }
  return 0;
}
