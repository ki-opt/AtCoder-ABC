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
	int N;
	cin >> N;
	vector<int> C(N-1), S(N-1), F(N-1);
	rep(i,N-1) {
		cin >> C[i] >> S[i] >> F[i];
	}

	repp(i,0,N-1) {
		int ans = 0;
		repp(j,i,N-1) {
			if (ans >= S[j]) {
				if (ans % F[j] == 0) {	}
				else { ans = ((ans / F[j]) + 1) * F[j]; }
			} else {
				ans = S[j];
			}
			ans += C[j];
		}
		cout << ans << endl;
	}
	cout << 0 << endl;
	return 0;


	return 0;
}