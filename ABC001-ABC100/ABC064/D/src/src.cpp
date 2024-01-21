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
	int N;
	string S;
	cin >> N >> S;
	int cnt = 0, pre = 0;
	rep(i,N) {
		if (S[i] == '(') {
			cnt++;
		} else if (S[i] == ')') {
			cnt--;
			if (cnt < 0) {
				pre++;
				cnt = 0;
			}
		}
	}
	string ans;
	rep(i,pre) ans += '(';
	rep(i,N) ans += S[i];
	
	cnt = 0;
	rep(i,ans.size()) {
		if (ans[i] == '(') {
			cnt++;
		} else if (ans[i] == ')') {
			cnt--;
		}
	}
	rep(i,cnt) ans += ')';
	cout << ans << endl;
	return 0;
}