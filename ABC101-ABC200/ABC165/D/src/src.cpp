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
	ll A, B, N; cin >> A >> B >> N;
	if (N < B) cout << A * N / B << endl;
	else if (N == B) cout << A * (N - 1) / B << endl;
	else cout << A * (B - 1) / B - A * (ll)((B - 1) / B) << endl;
	return 0;
}