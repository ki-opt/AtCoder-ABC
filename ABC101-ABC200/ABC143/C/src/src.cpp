#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>
#include <stack>
#include "atcoder/all"

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int N; cin >> N;
	string S; cin >> S;
	if (N == 1) {
		cout << 1 << endl;
		return 0;
	}

	int ans = 0;
	rep(i,N-1) {
		if (S[i] == S[i+1]) {
			ans++;
			int j = i + 1;
			while (j < N && S[i] == S[j]) j++;
			i = j - 1;
			//if (j != N && i + 1 == N - 1) ans++;
		} else {
			ans++;
		}
		if (i + 1 == N - 1) ans++;
	}
	cout << ans << endl;

	return 0;
}