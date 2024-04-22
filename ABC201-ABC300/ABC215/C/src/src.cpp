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
#include <set>
#include <math.h>
#include <float.h>
#include "atcoder/all"

using namespace std;
using namespace atcoder;

using ull=unsigned long long;
using ll=long long;
//using mint = modint998244353;
//using mint = modint1000000007;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	string S; ll K; cin >> S >> K;

	vector<string> ans;
	vector<int> array;
	rep(i,S.size()) array.push_back(i);
	do {
		string tmp;
		rep(i,S.size()) tmp += S[array[i]];
		ans.push_back(tmp);
	} while(next_permutation(array.begin(),array.end()));

	sort(ans.begin(), ans.end());
	unique(ans.begin(),ans.end());
	cout << ans[K-1] << endl;

	return 0;
}