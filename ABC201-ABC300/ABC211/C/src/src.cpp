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
using mint = modint1000000007;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	string S; cin >> S;
	/*vector<vector<int>> num(26);
	rep(i,S.size()) {
		num[S[i]-'a'].push_back(i);
	}*/

	//vector<int> vec = {'c'-'a','h'-'a','o'-'a','k'-'a','u'-'a','d'-'a','a'-'a','i'-'a'};
	//vector<int> vec = {'h'-'a','o'-'a','k'-'a','u'-'a','d'-'a','a'-'a','i'-'a'};
	vector<char> vec = {'c','h','o','k','u','d','a','i'};
	vector<vector<mint>> dp(vec.size(),vector<mint>(S.size(),0));
	rep(i,S.size()) if (S[i] == 'c') dp[0][i]++;

	repp(i,1,vec.size()) {
		mint tmp = 0;
		rep(j,S.size()) {
			tmp += dp[i-1][j];
			if (S[j] == vec[i]) {
				dp[i][j] += tmp;
			}
		}
	}
	
	mint ans = 0;
	rep(i,S.size()) ans += dp[vec.size()-1][i];
	cout << ans.val() << endl;

	return 0;
}