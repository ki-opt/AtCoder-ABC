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

	vector<int> v(10,0);
	rep(i,S.size()) {
		int n = int(S[i]-'0');
		v[n]++;
	}

	if (S.size() == 1) {
		if (S[0] == '8') cout << "Yes" << endl;
		else cout << "No" << endl;
	} else if (S.size() == 2) {
		if ((int(S[0]-'0')*10+int(S[1]-'0')) % 8 == 0) cout << "Yes" << endl;
		else if ((int(S[1]-'0')*10+int(S[0]-'0')) % 8 == 0) cout << "Yes" << endl;
		else cout << "No" << endl;
	} else {
		int n = 104;
		while (n < 1000) {
			vector<int> tmp(10,0);
			int n_dash = n;
			while (n_dash > 0) {
				tmp[n_dash%10]++;
				n_dash /= 10;
			}
			n += 8;
			if (tmp[0] > 0) continue;
		
			int i = 1;
			while (v[i] >= tmp[i]) {
				i++;
				if (i == 10) break;
			}
			if (i == 10) {
				cout << "Yes" << endl;
				return 0;
			}
		}
		cout << "No" << endl;
	}

	return 0;
}