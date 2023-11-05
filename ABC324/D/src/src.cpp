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
	vector<int> num(10,0);
	rep(i,N) num[S[i]-'0']++;

	int ans = 0;
	for (ull i = 0; i * i < pow(10,N); i++) {
		ull tmp = i * i;
		ull cnt = 0;
		vector<int> check(10,0);
		while (tmp != 0) {
			check[tmp % 10]++;
			tmp /= 10;
			cnt++;
		}
		if (cnt < N) {
			repp(j,cnt,N) check[0]++;
		}
		bool isFound = true;
		rep(j,10) if (check[j] != num[j]) {
			isFound = false;
			break;
		}
		if (isFound) ans++;
	}
	cout << ans << endl;

	return 0;
}