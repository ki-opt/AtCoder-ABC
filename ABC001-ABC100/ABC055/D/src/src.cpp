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

struct Node{
	vector<char> ans;
	int index;
};

int main() {
	int N; string s;
	cin >> N >> s;
	vector<string> init = { "SS","SW","WS","WW" };
	for (auto v : init) {
		string ans = v;
		repp(i,2,N) {
			if (s[i-1] == 'o') {
				if (ans[i-1] == 'S') {
					ans += ans[i-2];
				} else if (ans[i-1] == 'W') {
					if (ans[i-2] == 'S') ans += 'W';
					else ans += 'S';
				}
			} else if (s[i-1] == 'x') {
				if (ans[i-1] == 'S') {
					if (ans[i-2] == 'S') ans += 'W';
					else ans += 'S';
				} else if (ans[i-1] == 'W') {
					ans += ans[i-2];
				}
			}
		}
		// check
		bool isNotFound = false;
		if (s[0] == 'o') {
			if (ans[0] == 'S' && ans[N-1] != ans[1]) isNotFound = true;
			else if (ans[0] == 'W' && ans[N-1] == ans[1]) isNotFound = true;
		} else if (s[0] == 'x') {
			if (ans[0] == 'S' && ans[N-1] == ans[1]) isNotFound = true;
			else if (ans[0] == 'W' && ans[N-1] != ans[1]) isNotFound = true;
		}
		if (s[N-1] == 'o') {
			if (ans[N-1] == 'S' && ans[N-2] != ans[0]) isNotFound = true;
			else if (ans[N-1] == 'W' && ans[N-2] == ans[0]) isNotFound = true;
		} else if (s[N-1] == 'x') {
			if (ans[N-1] == 'S' && ans[N-2] == ans[0]) isNotFound = true;
			else if (ans[N-1] == 'W' && ans[N-2] != ans[0]) isNotFound = true;
		}
		if (!isNotFound) {
			cout << ans << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	
	/*
	vector<char> ans(N);
	queue<Node> que;
	ans[0]='S'; ans[1] = 'S'; que.push({ans,2});
	ans[1]='W'; que.push({ans,2});
	ans[0]='W'; ans[1]='S'; que.push({ans,2});
	ans[1]='W'; que.push({ans,2});
	while (!que.empty()) {
		Node tmp = que.front(); que.pop();
		if (tmp.index == N) {
			bool isFound = false;
			if (s[N-1] == 'o') {
				if (tmp.ans[N-1] == 'S' && tmp.ans[N-2] == tmp.ans[0]) isFound = true;
				else if (tmp.ans[N-1] == 'W' && tmp.ans[N-2] != tmp.ans[0]) isFound = true;
			} else if (s[N-1] == 'x') {
				if (tmp.ans[N-1] == 'S' && tmp.ans[N-2] != tmp.ans[0]) isFound = true;
				else if (tmp.ans[N-1] == 'W' && tmp.ans[N-2] == tmp.ans[0]) isFound = true;
			}
			if (isFound) {
				for (auto a : tmp.ans) cout << a;
				return 0;
			}
		} else {
			if (s[tmp.index-1] == 'o') {
				if (tmp.ans[tmp.index-1] == 'S') {
					tmp.ans[tmp.index] = tmp.ans[tmp.index-2];
				} else if (tmp.ans[tmp.index-1] == 'W') {
					if (tmp.ans[tmp.index-2] == 'S') tmp.ans[tmp.index] = 'W';
					else tmp.ans[tmp.index] = 'S';
				}
			} else if (s[tmp.index-1] == 'x') {
				if (tmp.ans[tmp.index-1] == 'S') {
					if (tmp.ans[tmp.index-2] == 'S') tmp.ans[tmp.index] = 'W';
					else tmp.ans[tmp.index] = 'S';
				} else if (tmp.ans[tmp.index-1] == 'W') {
					tmp.ans[tmp.index] = tmp.ans[tmp.index-2];
				}
			}
			que.push({tmp.ans,tmp.index+1});
		}
	}
	cout << -1 << endl;
	*/
	return 0;
}