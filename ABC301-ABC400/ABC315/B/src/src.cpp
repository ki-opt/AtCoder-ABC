#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>

using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int M;
	cin >> M;
	vector<int> D(M);
	int total = 0;
	rep(i,M) {
		cin >> D[i];
		total += D[i];
	}

	int day = (total + 1) / 2;
	int tmp = 0, before_tmp = 0;
	rep(i,M) {
		tmp += D[i];
		if (tmp >= day) {
			int target = day - before_tmp;
			cout << i + 1 << " " << target << endl;
			return 0;
		}
		before_tmp += D[i];
	}


	return 0;
}