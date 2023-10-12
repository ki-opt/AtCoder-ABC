#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, limit, init) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	string S;
	cin >> S;
	if (S[0] != 'A') {
		cout << "WA" << endl;
		return 0;
	}
	int sum = 0;
	repp(i,S.size()-1,2) {
		if (S[i] == 'C') sum++;
	}
	if (sum != 1) {
		cout << "WA" << endl;
		return 0;
	}
	rep(i,S.size()) {
		if (!(S[i] == 'A' || S[i] == 'C')) {
			if ((S[i] >= 'A') && (S[i] <= 'Z')) {
				cout << "WA" << endl;
				return 0;
			}
		}
	}
	cout << "AC" << endl;
	return 0;
}