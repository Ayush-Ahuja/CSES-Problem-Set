#include <bits/stdc++.h>

using namespace std;

#define LOOP(p, q) for(int i = (p); i < (q); i++)
#define LOOP_(p,q,i) for(int i = (p); i < (q); i++)
#define ll long long
#define all(x) x.begin(), x.end()
long long GCD(long long a,long long b){
  if(b==0LL) return a;
  else return GCD(b,a%b);
}
long long LCM(long long a,long long b){
  return (a*b)/GCD(a,b);
}
ll N = 3e5+7;

// O(1) for idempotent O(logN) for general
// Supports multiple sparse tables with minor change in Node

template<typename Node>
struct SparseTable {
	vector<vector<Node>> table;
	vector<ll> logValues;
	int n;
	int maxLog;
	vector<ll> a;
	SparseTable(int n1, vector<ll> &arr) {
		n = n1;
		a = arr;
		table.resize(n);
		logValues.resize(n + 1);
		maxLog = log2(n);
		logValues[1] = 0;
		for (int i = 2; i <= n; i++) {
			logValues[i] = logValues[i / 2] + 1;
		}
		for (int i = 0; i < n; i++) {
			table[i].resize(maxLog + 1);
			fill(all(table[i]), Node());
		}
		build();
	}
	void build() {
		for (int i = 0; i < n; i++) {
			table[i][0] = Node(a[i]);
		}
		for (int i = 1; i <= maxLog; i++) {
			for (int j = 0; (j + (1 << i)) <= n; j++) {
				table[j][i].merge(table[j][i - 1], table[j + (1 << (i - 1))][i - 1]);
			}
		}
	}
	Node queryNormal(int left, int right) {
		Node ans = Node();
		for (int j = logValues[right - left + 1]; j >= 0; j--) {
			if ((1 << j) <= right - left + 1) {
				ans.merge(ans, table[left][j]);
				left += (1 << j);
			}
		}
		return ans;
	}
	Node queryIdempotent(int left, int right) {
		int j = logValues[right - left + 1];
		Node ans = Node();
		ans.merge(table[left][j], table[right - (1 << j) + 1][j]);
		return ans;
	}
};
struct Node1 {
	ll val; // store more info if required
	Node1() { // Identity Element
		val = LLONG_MAX; //This stores a default value 
	}
	Node1(ll v) {
		val = v;
	}
	void merge(Node1 &l, Node1 &r) {
		val = min(l.val, r.val); //Change the operation here
	}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // ll tt;
    // cin >> tt;
    // while(tt--){
    // // Example
    // //   vector<ll> arr = {2, 4, 6, 8, 10};
    // // SparseTable<Node1> st(arr.size(), arr);
    
    // // // Query for XOR in range [1, 3] (0-based indexing)
    // // // This will XOR elements at indices 1, 2, and 3 (4 ^ 6 ^ 8)
    // // Node1 result = st.queryNormal(1, 3); // Pass Index
    // // cout << "XOR of range [1, 3]: " << result.val << "\n";


    // }  
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    LOOP(0,n){
        cin >> a[i];
    }
    SparseTable<Node1> st(n, a);
    while(q--){
        ll l,r;
        cin >> l >> r;
        Node1 result = st.queryIdempotent((l-1), (r-1));
        cout << result.val << "\n";
    }
    return 0;
}