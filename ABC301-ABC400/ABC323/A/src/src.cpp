#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	string S;
	cin >> S;
	rep(i,S.size()) {
		if (i % 2 == 1) {
			if (S[i] != '0') {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;

	return 0;
}