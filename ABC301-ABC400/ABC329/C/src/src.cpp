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
	//unordered_map<string,int> umap;
	int ans = 0;
	vector<int> check(26,0);
	rep(i,S.size()) {
		string tmp;
		tmp += S[i];
		int num = S[i] - 'a';
		if (check[num] == 0) {
			ans++;
			check[num]++;
		}
		int j = i + 1;
		while(j < S.size()) {
			if (S[i] == S[j]) {
				if (check[num] <= j - i) {
					ans++;
					check[num]++;
				}
			} else {
				i = j - 1;
				break;
			}
			j++;
		}
		if (j == S.size()) break;
	}
	cout << ans << endl;

	return 0;
}