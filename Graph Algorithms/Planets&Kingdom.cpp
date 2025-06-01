#include <bits/stdc++.h>

using namespace std;

#define LOOP(p, q) for(int i = (p); i < (q); i++)
#define LOOP_(p,q,i) for(int i = (p); i < (q); i++)
#define ll long long
long long GCD(long long a,long long b){
  if(b==0LL) return a;
  else return GCD(b,a%b);
}
long long LCM(long long a,long long b){
  return (a*b)/GCD(a,b);
}

vector<bool> visited;

void dfs(ll s, vector<vector<ll>>& adj, vector<ll>& order){
  visited[s] = true;
  for (auto v : adj[s]){
    if(!visited[v]){
      dfs(v, adj, order);
    }
  }
  order.push_back(s);
}

ll N = 3e5+7;
ll mod = 998244353;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>> adj(n+1);
	LOOP(0, m){
		ll u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
  visited.assign(n+1, false);
  vector<ll> order;
  LOOP(1, n+1){
    if(!visited[i]){
      dfs(i, adj, order);
    }
  }
  reverse(order.begin(), order.end());
  vector<vector<ll>> transpose(n+1);
  LOOP(1, n+1){
    for(auto v : adj[i]){
      transpose[v].push_back(i);
    }
  }
  ll f = 0;
  visited.assign(n+1, false);
  vector<ll> kingdom(n+1, 0);
  ll k = 0;
  LOOP(0, order.size()){
    if (!visited[order[i]]){
      vector<ll> component;
      dfs(order[i], transpose, component);
      k++;
      for (auto j : component){
        kingdom[j] = k;
      }
    }
  }
  cout << k << "\n";
  LOOP(1, n+1){
    cout << kingdom[i] << " ";
  }
  cout << "\n";
  return 0;
}