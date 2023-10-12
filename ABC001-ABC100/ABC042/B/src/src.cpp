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
	int N, L;
	cin >> N >> L;
	vector<string> S(N);
	rep(i,N) cin >> S[i];

	sort(S.begin(), S.end());
	rep(i,S.size()) cout << S[i];

	return 0;
}