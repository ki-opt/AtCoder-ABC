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
#include <bitset>
#include "atcoder/all"

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

//*
void myfunc(int N) {
	int num = 1, M = 0;
	while (num < N) num *= 2, M++; 
	cout << M << endl;
	vector<vector<int>> ans(M,vector<int>());
	rep(i,N) {
		bitset<100> bs(i);
		rep(j,M) {
			if (bs[j] == 1) ans[j].push_back(i);
		}
	}
	rep(i,M) {
		cout << ans[i].size() << " ";
		for (auto a : ans[i]) cout << a+1 << " ";
		cout << endl;
	}
	
	string S; cin >> S;
	int v = 0;
	for (int i = 0; i < M; i++) {
		if (S[i] == '1') v |= 1 << i; 
	}
	cout << v + 1 << endl << endl;
}

int main() {
	int N; cin >> N;
	myfunc(N);
	return 0;
}