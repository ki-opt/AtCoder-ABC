#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>

using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int N;
	cin >> N;
	vector<string> s(N);
	rep(i,N) {
		string tmp;
		cin >> tmp;
		sort(tmp.begin(),tmp.end());
		s[i] = tmp;
	}

	unordered_map<string,int> umap;
	rep(i,N) {
		if (umap.count(s[i]) > 0) {
			if (umap[s[i]] == 0) umap[s[i]] = 2;
			else umap[s[i]]++;
			/*if (umap[s[i]] == 0) {
				umap[s[i]] = 1;
			} else {
				umap[s[i]] += umap[s[i]];
			}
			ans += umap[s[i]];*/
		}
		else umap[s[i]] = 0;
	}

	ll ans = 0;
	for (auto itr=umap.begin(); itr != umap.end(); itr++) {
		if (itr->second > 0) {
			if (itr->second == 1) {
				ans++;
			} else {
				ll tmp = itr->second;
				ans += tmp * (tmp - 1) / 2;
			}
		}
	}

	/*
	sort(s.begin(),s.end());
	ll ans = 0;
	rep(i,N) {
		if (s[i] == s[i+1]) {
			i++;
			ans++;
			repp(j,i+1,N) {
				if (s[i] == s[j]) {
					ans++;
				} else {
					if (i + 3 >= j) ans++;
					i = j - 1;
					break;
				}
			}
		} 
	}*/
	cout << ans << endl;

	return 0;
}