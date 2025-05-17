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

ll N = 3e5+7;
ll mod = 998244353;

int main(){
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n+1);
    vector<vector<ll>> comp;
    vector<bool> visited(n+1);
    LOOP(0, m){
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<ll> q;
    LOOP(1, n+1){
        if (!visited[i]){
            vector<ll> curr;
            curr.push_back(i);
            q.push(i);
            visited[i] = true;
            while(!q.empty()){
                ll u = q.front();
                q.pop();
                for(auto v : adj[u]){
                    if(!visited[v]){
                        visited[v] = true;
                        q.push(v);
                        curr.push_back(v);
                    }
                }
            }
            comp.push_back(curr);
        }
    }
    cout << comp.size() - 1 << "\n";
    LOOP(0, comp.size()-1){
        cout << comp[i][0] <<  " " << comp[i+1][0] << "\n"; 
    }
    return 0;
}