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
#include <set>
#include "atcoder/all"

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	ull X;
	cin >> X;
	
	set<ull> ans;
	for (int first = 1; first <= 9; first++) {
		ans.insert((ull)first);
		for (int d = -9; d <= 9; d++) {
			string v = to_string(first);
			int bef = first;
			for (int keta = 2; keta < 18; keta++) {
				int diff = bef + d;
				if (diff < 0 || diff > 9) break;
				bef = diff;
				v += to_string(diff);
				ans.insert(stoll(v));
			}
		}
	}
	ans.insert(111111111111111111);
	cout << *ans.lower_bound(X) << endl;
	
	/*
	vector<int> val;
	ull x = X;
	while (x != 0) {
		val.push_back(x % 10);
		x /= 10;
	}
	reverse(val.begin(),val.end());
	
	if (val.size() > 10) {
		rep(i,val.size()) cout << 1;
		return 0;
	} else if (val.size() <= 2) {
		cout << X << endl;
		return 0;
	} else {
		vector<ull> ans;
		vector<int> keta(val.size());
		int diff = val[1] - val[0];
		keta[0] = val[0]; keta[1] = val[1];
		ull tmp = (ull)pow(10,val.size()-1)*(ull)val[0] + (ull)pow(10,val.size()-2)*(ull)val[1]; 
		bool isFound = true;
		repp(i,1,val.size()-1) {
			int next = keta[i] - diff;
			if (next < 0 || next >= 10) { isFound = false; break; }
			keta[i+1] = next;
			tmp += (ull)pow(10,val.size()-i-2)*(ull)next;
		}
		if (isFound) ans.push_back(tmp);

		tmp = (ull)pow(10,val.size()-1)*(ull)val[0];
		repp(i,1,val.size()) tmp += (ull)pow(10,val.size()-i-1)*(ull)val[i];
		ans.push_back(tmp);
		if (val[0] != 9) {
			tmp = (ull)pow(10,val.size()-1)*(ull)(val[0] + 1);
			repp(i,1,val.size()) tmp += (ull)pow(10,val.size()-i-1)*((ull)val[i] + 1);
			ans.push_back(tmp);
		}
		tmp = (ull)pow(10,val.size()+1);
		rep(i,val.size()) tmp += (ull)pow(10,val.size()-i);
		ans.push_back(tmp);

		for (int zyoi = val.size(); zyoi <= 9; zyoi++) {

		}

		tmp = ULLONG_MAX;
		for (ull v : ans) {
			if (v >= X) tmp = min(tmp,v);
		}
		cout << tmp;

		//cout << *min_element(ans.begin(),ans.end());
	}
	*/
	return 0;
}