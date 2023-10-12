#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>

using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int N;
	cin >> N;
	vector<int> P(N);
	rep(i,N) cin >> P[i];
	int p1 = P[0];
	sort(P.begin(),P.end(),greater<int>());
	int max_val = P[0], next_max_val = P[1];

	if (p1 == max_val) {
		if (p1 == next_max_val) {
			cout << 1 << endl;
			return 0;
		} else {
			cout << 0 << endl;
			return 0;
		}
	} else {
		cout << max_val - p1 + 1 << endl;
		return 0;
	}

	return 0;
}