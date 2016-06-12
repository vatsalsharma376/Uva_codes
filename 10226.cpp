#include <iostream>
#include <vector>
using namespace std;

int main() {
	int ld, nRec;
	double dp, loan, decP[101];

	while (true) {
		cin >> ld >> dp >> loan >> nRec;
		if (ld < 0)
			break;

		int m;
		double p;
		while (nRec--) {
			cin >> m >> p;
			for (int i = m; i < 101; i++)
				decP[i] = p;
		}

		int now = 0;
		double mp = loan / ld;
		double curVal = (loan + dp) * (1 - decP[0]);
		double curLoan = loan;
		while (curVal < curLoan) {
			now++;
			curLoan -= mp;
			curVal = curVal * (1-decP[now]);
		}

		cout << now << " month";
		if (now != 1)
			cout << "s";
		cout << endl;
	}

	return 0;
}
