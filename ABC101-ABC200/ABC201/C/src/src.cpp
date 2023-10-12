#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>

using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	string S;
	cin >> S;
	vector<int> check(10,0);
	rep(i,S.size()) {
		if (S[i] == 'o') check[i] = 1;
		else if (S[i] == 'x') check[i] = -1;
		else check[i] = 0;
	}

	int maru_sum = 0;
	rep(i,10) { if (check[i] == 1) maru_sum++; }
	if (maru_sum > 4) { cout << 0 << endl; return 0; }

	ll ans = 0;
	rep(i,10000) {
		//unordered_map<int,int> umap;
		vector<int> check_tmp(10,0);
		if (i < 1000) { check_tmp[0] = 1; } 
		int tmp = i;
		while(tmp != 0) {
			int val = tmp % 10;
			//umap[val] = 1;
			check_tmp[val] = 1;
			tmp /= 10;
		}

		int flag = 0;
		rep(j,10) {
			if (check[j] == 1 && check_tmp[j] == 0) { flag = 1; break; }
			if (check[j] == -1 && check_tmp[j] == 1) { flag = 1; break; }
		}
		if (flag == 0) ans++;
	} 
	cout << ans << endl;
	/*
	if (check[0] > 4) {
		cout << 0 << endl;
		return 0;
	}

	int sum = 0;
	int ans = 1;
	rep(i,4) {
		if (check[0] <= 0) break;
		ans *= check[0];
		sum++;
		check[0]--;
	}
	if (sum == 4 && check[0] == 0) {
		cout << ans << endl;
		return 0;
	}

	if (check[2] >= 4 - sum) {
		rep(i,4) {
			if (4 - sum == 0) break;
			ans *= check[2];
			check[2]--;
			sum++;
		}
		cout << ans << endl;
	} else {
		cout << 0 << endl;
	}*/
	return 0;
}