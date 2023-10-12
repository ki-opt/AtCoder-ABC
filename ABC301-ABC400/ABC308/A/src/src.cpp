#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>

using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, limit, init) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	vector<int> S(8);
	rep(i,8) cin >> S[i];

	rep(i,7) {
		if (S[i] > S[i+1]) {
			cout << "No" << endl;
			return 0;
		}
	}
	rep(i,8) {
		if ((S[i] < 100 || S[i] > 675) || S[i] % 25 != 0) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;

	return 0;
}