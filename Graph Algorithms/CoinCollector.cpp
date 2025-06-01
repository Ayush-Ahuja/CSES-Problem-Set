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
vector<ll> max_coins;

void dfs(ll s, vector<vector<ll>>& adj, vector<ll>& order){
  visited[s] = true;
  for (auto v : adj[s]){
    if(!visited[v]){
      dfs(v, adj, order);
    }
  }
  order.push_back(s);
}

void find_max_coins(ll s, vector<set<ll>>& adj, vector<ll>& coins){
  visited[s] = true;
  ll ans = 0;
  for (auto v : adj[s]){
    if(!visited[v]){
      find_max_coins(v, adj, coins);
    }
    ans = max(ans, max_coins[v]);
  }
  ans += coins[s];
  max_coins[s] = ans;
}

ll N = 3e5+7;
ll mod = 998244353;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>> adj(n+1);
  vector<ll> coins(n+1);
  LOOP(1, n+1){
    cin >> coins[i];
  }
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
  visited.assign(n+1, false);
  vector<ll> kingdom(n+1, 0);
  ll k = 0;
  vector<ll> new_coins(n+1);
  LOOP(0, order.size()){
    if (!visited[order[i]]){
      vector<ll> component;
      dfs(order[i], transpose, component);
      k++;
      ll coin = 0;
      for (auto j : component){
        kingdom[j] = k;
        coin += coins[j];
      }
      new_coins[k] = coin;
    }
  }
  vector<set<ll>> new_graph(k+1);
  LOOP(1, n+1){
    for (auto u : adj[i]){
      if (kingdom[i] != kingdom[u]){
        new_graph[kingdom[i]].insert(kingdom[u]);
      }
    }
  }
  ll ans = 0;
  visited.assign(k+1, false);
  max_coins.assign(k+1, 0);
  LOOP(1, k+1){
    if (!visited[i]){
      find_max_coins(i, new_graph, new_coins);
    }
    ans = max(ans, max_coins[i]);
  }
  cout << ans << "\n";
  return 0;
}