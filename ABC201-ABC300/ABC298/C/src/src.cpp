#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int N, Q;
	cin >> N >> Q;
	vector<vector<int>> query(Q,vector<int>(3));
	rep(q,Q) {
		cin >> query[q][0];
		if (query[q][0] == 1) cin >> query[q][1] >> query[q][2];
		else cin >> query[q][1];
	}

	vector<vector<int>> box(N+1), card(200001);
	rep(q,Q) {
		if (query[q][0] == 1) {
			int i = query[q][1], j = query[q][2];
			box[j].push_back(i);
			card[i].push_back(j);
		} else if (query[q][0] == 2) {
			int i = query[q][1];
			sort(box[i].begin(),box[i].end());
			rep(j,box[i].size()) cout << box[i][j] << " ";
			cout << endl;
		} else if (query[q][0] == 3) {
			int i = query[q][1];
			sort(card[i].begin(),card[i].end());
			card[i].erase(unique(card[i].begin(),card[i].end()),card[i].end());
			vector<bool> check(200001,false);
			rep(j,card[i].size()) {
				if (check[card[i][j]] == false) {
					check[card[i][j]] = true;
					cout << card[i][j] << " ";
				} 
			}
			cout << endl;
		}
	}

	/*
	vector<priority_queue<int, vector<int>, greater<int>>> hako(N+1), kazu(200001);
	rep(num,Q) {
		int q = query[num][0];
		if (q == 1) {
			int i = query[num][1], j = query[num][2];
			hako[j].push(i);
			kazu[i].push(j);
		} else if (q == 2) {
			int i = query[num][1];
			priority_queue<int, vector<int>, greater<int>> tmp = hako[i];
			while(!tmp.empty()) { cout << tmp.top() << " "; tmp.pop(); }
			cout << endl;
		} else {
			int i = query[num][1];
			vector<bool> check(N+1,false);
			priority_queue<int, vector<int>, greater<int>> tmp = kazu[i];
			while(!tmp.empty()) { 
				if (!check[tmp.top()]) {
					cout << tmp.top() << " ";
					check[tmp.top()] = true;
				}
				tmp.pop();
			}
			cout << endl;
		}
	}
	*/
	return 0;
}