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

ll n, m;

ll N = 3e5+7;
ll mod = 998244353;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    vector<vector<ll>> adj(n+1);
    vector<ll> par(n+1);
    vector<ll> visited(n+1);
    vector<ll> dist(n+1, -1);
    LOOP(0,m){
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }       
    queue<ll> q;
    visited[1] = true;
    par[1] = -1;
    dist[1] = 0;
    q.push(1);
    while(!q.empty()){
        ll v = q.front();
        q.pop();
        for(auto u : adj[v]){
            if(!visited[u]){
                visited[u] = true;
                par[u] = v;
                dist[u] = 1 + dist[v];
                q.push(u);
            }
        }
    }
    if (dist[n] == -1){
        cout << "IMPOSSIBLE\n";
    }
    else{
        cout << dist[n]+1 << "\n";
        vector<ll> tempp;
        for(auto c = n; c!= -1; c = par[c]){           
            tempp.push_back(c);
        }
        reverse(tempp.begin(), tempp.end());
        LOOP(0, tempp.size()){
            cout << tempp[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}