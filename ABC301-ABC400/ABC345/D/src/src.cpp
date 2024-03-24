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

int N, H, W; 
struct Cand{int a, b;};

bool rec_func(const vector<vector<bool>> &seen, vector<Cand> &vec, int index) {
	int val_i = -1, val_j = -1;
	bool isFound = false;
	rep(i,H) {
		rep(j,W) {
			if (!seen[i][j]) {
				val_i = i, val_j = j; 
				isFound = true;	
				break;
			}
		}
		if (isFound) break;
	}
	if (!isFound) return true;
	if (index >= vec.size()) return false;

	Cand tmp = vec[index];
	vector<vector<bool>> copy_seen = seen;
	if (val_i + tmp.a > H || val_j + tmp.b > W) return false;

	bool isPut = true;
	for (int m = val_i; m < val_i + tmp.a; m++) {
		for (int n = val_j; n < val_j + tmp.b; n++) {
			if (copy_seen[m][n]) { isPut = false; }
			copy_seen[m][n] = true;
		}
	}
	if (isPut) {
		if (rec_func(copy_seen,vec,index+1)) return true;
	}

	for (int m = val_i; m < val_i + tmp.a; m++) {
		for (int n = val_j; n < val_j + tmp.b; n++) {
			copy_seen[m][n] = false;
		}
	}
	return false;
}

int main() {
	cin >> N >> H >> W;
	vector<int> A(N), B(N);
	vector<pair<int,int>> block;
	rep(i,N) {
		cin >> A[i] >> B[i];
		block.push_back({A[i],B[i]}); block.push_back({B[i],A[i]});
	}

	for(int i = 1; i < (1 << (2 * N)); i++) {
		vector<Cand> vec; bool isSame = false;
		for (int z = 0; z < 2 * N; z+=2) {
			if ((i >> z) & 0x0001 && (i >> (z+1)) & 0x0001) isSame = true;
			else if ((i >> z) & 0x0001) vec.push_back({A[z/2],B[z/2]});
			else if ((i >> (z+1)) & 0x0001) vec.push_back({B[z/2],A[z/2]});
		}
		if (isSame) continue;

		vector<int> nums; rep(i,vec.size()) nums.push_back(i);
		vector<vector<bool>> seen(H,vector<bool>(W,false));
		do {
			vector<Cand> v;
			for (auto n : nums) v.push_back(vec[n]);
			if (rec_func(seen,v,0)) {
				cout << "Yes" << endl;
				return 0;
			}
		} while (next_permutation(nums.begin(),nums.end()));
		//cout << vec.size() << endl;
	}
	cout << "No" << endl;
	return 0;
}