#include <iostream>
#include <vector>

using namespace std;

int main() {
	string S;
	cin >> S;

	int x;
	for (int i = 0; i < S.size(); i++) {
		if (S.substr(i,1) == "B") {
			x = i;
			break;
		}
	}
	int y;
	for (int i = 0; i < S.size(); i++) {
		if (S.substr(i,1) == "B") {
			y = i;
		}
	}
	if (!((x % 2 == 0 && y % 2 == 1) || (x % 2 == 1 && y % 2 == 0))) {
		cout << "No";
		return 0;
	}

	int i, j;
	for (i = 0; i < S.size(); i++) {
		if (S.substr(i,1) == "R") {
			for (j = i + 1; j < S.size(); j++) {
				if (S.substr(j,1) == "R") goto A;
			}			
		}
	}
A:
	for (int m = i + 1; m < j; m++) {
		if (S.substr(m,1) == "K") {
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	return 0;
}