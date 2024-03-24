
struct Node{ ll v, prev, next; };
struct bidirectional_list {
	vector<Node> vec;
	// コンストラクタ1
	bidirectional_list() { }
	// コンストラクタ2
	bidirectional_list(const vector<ll> &A) {
		ll N = A.size();
		vec.resize(N);
		rep(i,N) {
			if (i != N-1) vec[i] = {A[i],i-1,i+1};
			else vec[i] = {A[i],i-1,-1};
		}
	}

	// cur_indexの次にvalを挿入
	void insert(ll cur_index, ll val) {
		// vectorが空のとき
		if (vec.size() == 0) {
			vec.push_back({val,-1,-1});
		// 先頭への要素の追加
		} else if (cur_index == -1) {
			vec[0].prev = vec.size();
			vec.push_back({val,-1,0});
		// 先頭以外への要素の追加
		} else {
			ll next_index = vec[cur_index].next, last_index = vec.size();
			vec.push_back({val,cur_index,next_index});
			vec[cur_index].next = last_index;
			if (next_index != -1) vec[next_index].prev = last_index;
		}
	}
	// cur_indexを削除
	void erase(ll cur_index) {
		ll next_index = vec[cur_index].next, prev_index = vec[cur_index].prev;
		if (next_index != -1) vec[next_index].prev = prev_index;
		if (prev_index != -1) vec[prev_index].next = next_index;
		vec[cur_index] = {-1,-1,-1};
	}
	// serach first index
	ll search_first_index() {
		ll start_index;
		rep(i,vec.size()) {
			Node n = vec[i];
			if (n.v != -1 && n.prev == -1) start_index = i;
		}
		return start_index;
	}
};
