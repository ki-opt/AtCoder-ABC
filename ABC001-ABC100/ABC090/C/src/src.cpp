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
	long int N, M;
	cin >> N >> M;

	if (N == 2 || M == 2) cout << 0 << endl;
	else if (N == 1 || M == 1) {
		if (N == 1 && M == 1) cout << 1 << endl;
		else {
			long int tmp = max(N,M);
			cout << tmp - 2 << endl;
		}
	} else {
		cout << (N-2)*(M-2) << endl;
	}

	return 0;
}