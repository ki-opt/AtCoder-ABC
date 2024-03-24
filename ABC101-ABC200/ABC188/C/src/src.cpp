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
	ll N; cin >> N;
	vector<ll> A(2 * (1 << (N-1))); 
	rep(i,A.size()) cin >> A[i];

	while (true) {
		vector<ll> vec;
		rep(i,A.size()) if (A[i] != -1) vec.push_back(i);
		if (vec.size() == 2) {
			cout << (A[vec[0]] > A[vec[1]] ? vec[1]+1 : vec[0]+1) << endl;
			return 0;
		}
		for (int i = 0; i < vec.size(); i+=2) {
			if (A[vec[i]] > A[vec[i+1]]) A[vec[i+1]] = -1;
			else A[vec[i]] = -1;
		}
	}
	
	/*
	ll max_val = *max_element(A.begin(),A.end());
	ll second_val = -1, index = -1;
	rep(i,A.size()) {
		if (A[i] != max_val && A[i] > second_val) {
			second_val = A[i];
			index = i + 1;
		}
	}
	cout << index << endl;
	*/

	return 0;
}