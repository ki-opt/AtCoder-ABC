#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, limit, init) for (int iter = (int)init; iter < (int)(limit); iter++)



int main() {
	int W, H, N;
	cin >> W >> H >> N;
	//vector<pair<int,int>> xy(N);
	vector<int> p(N),q(N);
	rep(i,N) {
		int tmp1,tmp2;
		cin >> tmp1 >> tmp2;
		//xy[i] = make_pair(tmp1,tmp2);
		p[i] = tmp1;
		q[i] = tmp2;
	}

	int A, B;
	cin >> A;
	vector<int> a(A);
	rep(i,A) cin >> a[i];
	a.push_back(W);
	cin >> B;
	vector<int> b(B);
	rep(i,B) cin >> b[i];
	b.push_back(H);
	
	map<pair<int,int>,int> mp;
	rep(i,N){
		auto pos_x = lower_bound(a.begin(),a.end(),p[i]);
		auto pos_y = lower_bound(b.begin(),b.end(),q[i]);
		mp[{*pos_x,*pos_y}]++;
		//if (mp.count({*pos_x,*pos_y}) == 0)  = 1;
		//cout << *pos_x << " " << *pos_y << endl;
	}

	int M = 0;
	for(auto p : mp) {
		M = max(M,p.second);
	}
	int m = INT_MAX;
	if (mp.size()==(A+1)*(B+1)) {
		for(auto p:mp) m = min(m,p.second);
	} else {
		m = 0;
	}
	cout << m << " " << M << endl;

	return 0;
}