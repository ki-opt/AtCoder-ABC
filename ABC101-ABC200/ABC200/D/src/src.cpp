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
	int N; cin >> N;
	vector<int> A(N); rep(i,N) cin >> A[i];
	vector<vector<int>> a(200);
	
	int v = min(N,8);
	for (int i = 1; i < (1 << v); i++) {
		int val = 0;
		vector<int> s;
		for (int j = 0; j < v; j++) {
			if ((i >> j) & 0x01 == 1) {
				val = (val + A[j]) % 200;
				s.push_back(j+1);
			}
		}
		if (a[val].size() != 0) {
			cout << "Yes" << endl;
			cout << a[val].size() << " ";
			for (auto j : a[val]) cout << j << " ";
			cout << endl;
			cout << s.size() << " ";
			for (auto j : s) cout << j << " ";
			cout << endl;
			return 0;
		} 
		a[val] = s;
	}
	cout << "No" << endl;
	return 0;
}