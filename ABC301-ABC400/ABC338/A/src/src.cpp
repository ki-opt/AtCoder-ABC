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
	bool isFound = true;
	rep(i,S.size()) {
		if (i == 0 && !isupper(S[i])) isFound = false;
		if (i > 0 && isupper(S[i])) isFound = false;
	}
	if (isFound) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}