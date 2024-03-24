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
	string S; cin >> S;
	if (S[0] == '<' && S[S.size()-1] == '>') {
		repp(i,1,S.size()-1) {
			if (S[i] == '<' || S[i] == '>') {
				cout << "No" << endl;
				return 0;
			}
		}
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}


	return 0;
}