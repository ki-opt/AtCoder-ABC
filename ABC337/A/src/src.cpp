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
	vector<int> X(N), Y(N);
	int x = 0, y = 0;
	rep(i,N) {
		cin >> X[i] >> Y[i];
		x += X[i]; y += Y[i];
	}
	if (x > y) cout << "Takahashi" << endl;
	else if (x < y) cout << "Aoki" << endl;
	else cout << "Draw" << endl;


	return 0;
}