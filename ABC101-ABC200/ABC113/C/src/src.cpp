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

struct City{
	ll P, Y, num;
	string str;
};

bool asc(const City& left, const City& right) {
	if (left.P != right.P) { return left.P < right.P; }
	else { return left.Y < right.Y; }
}
bool num_asc(const City& left, const City& right) {
	return left.num < right.num;
}

int main() {
	ll N, M;
	cin >> N >> M;
	vector<ll> P(M), Y(M);
	vector<City> city(M);
	rep(i,M) {
		cin >> P[i] >> Y[i];
		city[i] = {P[i],Y[i],i};
	}

	vector<ll> num(N+1,1);
	sort(city.begin(),city.end(),asc);
	rep(i,M) {
		string s_pref = to_string(city[i].P);
		s_pref = string(max(0,6-(int)s_pref.size()),'0') + s_pref;	

		string s_num = to_string(num[city[i].P]);
		s_num = string(max(0,6-(int)s_num.size()),'0') + s_num;
		
		city[i].str = s_pref + s_num;

		num[city[i].P]++;
	}
	sort(city.begin(),city.end(),num_asc);
	rep(i,M) cout << city[i].str << endl;
	return 0;
}