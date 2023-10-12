#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <deque>

using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	string S;
	int Q;
	cin >> S >> Q;
	int T_flag = 0;
	deque<char> deq;
	rep(i,S.size()) deq.push_back(S[i]);

	rep(i,Q) {
		int T;
		cin >> T;
		if (T == 1) {
			T_flag = 1 - T_flag;
		} else {
			int F;
			char C;
			cin >> F >> C;
			if (T_flag == 0) {
				if (F == 1) {
					deq.push_front(C);
					//S = C + S;
				} else if (F == 2) {
					deq.push_back(C);
					//S = S + C;
				}
			} else if (T_flag == 1) {
				if (F == 1) {
					deq.push_back(C);
					//S = S + C;
				} else if (F == 2) {
					deq.push_front(C);
					//S = C + S;
				}
			}
		}
	}
	if (T_flag == 1) {
		while(!deq.empty()) {
			cout << deq.back();
			deq.pop_back();
		}
	} else {
		while(!deq.empty()) {
			cout << deq.front();
			deq.pop_front();
		}
	}

	return 0;
}