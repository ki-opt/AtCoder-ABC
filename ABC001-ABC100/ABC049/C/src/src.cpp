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
	string S, T;
	vector<string> moji = {"dream","dreamer","erase","eraser"};
	cin >> S;
	queue<int> que;

	rep(i,moji.size()) {
		if (S.compare(0,moji[i].size(),moji[i]) == 0) {
			que.push(moji[i].size());
		}	
	}

	while(que.empty() == false) {
		int tmp = que.front(); que.pop();
		if (tmp == S.size()) {
			cout << "YES" << endl;
			return 0;
		}
		rep(i,moji.size()) {
			if (S.compare(tmp,moji[i].size(),moji[i]) == 0) {
				que.push(tmp+moji[i].size());
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}