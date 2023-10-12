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

bool desc_asc(pair<int, int>& left, pair<int, int>& right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

int main() {
	unordered_map<ll,ll> mp;
	mp[1] += 100;
	mp[2] += 200;	
	for (auto iter = mp.begin(); iter != mp.end(); iter++) {
		cout << iter->first << " " << iter->second << endl;
		if (iter->first == 1) mp[3] += 300;
	}	
	/*
	map<ll,ll> mp;
	mp[1] += 100;
	mp[2] += 200;
	
	for (auto iter = mp.begin(); iter != mp.end(); iter++) {
		cout << iter->first << " " << iter->second << endl;
		if (iter->first == 1) mp[3] += 300;
	}*/
	/*
	auto iter = mp.begin();
	while(iter != mp.end()) {
		cout << iter->first << " " << iter->second << endl;
		if (iter->first == 1) mp[3] += 300;
		iter++;
	}*/
	
	/*
	ll N;
	cin >> N;
	vector<ll> S(N),C(N);
	//vector<pair<ll,ll>> SC;
	map<ll,ll> mp;
	rep(i,N) {
		cin >> S[i] >> C[i];
		mp[S[i]] += C[i];
	}

	ll ans = 0;
	auto iter = mp.begin();
	while(iter != mp.end()) {	
		ll s = iter->first;
		ll c = iter->second;
		if (c > 1) mp[2*s] += (c/2);
		if (c % 2 == 1) ans++;
		iter++;
		/*
		if (mp.count(2*s) > 0) {
			mp[2*s] += (c/2);
			if (c % 2 == 1) ans++;
		} else {
			mp[2*s] = (c/2);
		}
		if (c%2==1) ans++;
		iter++;
	}
	cout << ans << endl;*/

	return 0;
}