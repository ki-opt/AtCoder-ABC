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
	string S; cin >> S;
	string ans;
	for (int i = S.size()-1; i >= 0; i--) {
		if (S[i] == '.') break;
		ans = S[i] + ans;
	}
	cout << ans << endl;
	return 0;
}