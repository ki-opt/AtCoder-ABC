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
	string S;
	cin >> S;

	//vector<int> rl;
	//rep(i,S.size()-1) if (S[i] == 'R' && S[i+1] == 'L') rl.push_back(i);

	int r_index;
	vector<int> tmp, ans(S.size(),0);
	rep(i,S.size()) {
		if (S[i] == 'R') {
			tmp.push_back(i);
		} else if (S[i] == 'L' && S[i-1] == 'R') {
			for (auto n : tmp) {
				if ((i-n) % 2 == 0) ans[i]++;
				else ans[i-1]++; 
			}
			ans[i]++;
			r_index = i;
			tmp = vector<int>();
		} else {
			if ((i-r_index) % 2 == 0) ans[r_index]++;
			else ans[r_index-1]++;
		}
	}
	for (auto n : ans) cout << n << " ";;
	cout << endl;
	return 0;
}