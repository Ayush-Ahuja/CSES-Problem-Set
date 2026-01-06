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
vector<ll> subordinates;
vector<bool> visited;
vector<vector<ll>> adj;

void find_subordinates(ll u){
    visited[u] = true;
    subordinates[u] = 0;
    for(auto v : adj[u]){
        if(!visited[v]){
            find_subordinates(v);
            subordinates[u] += subordinates[v];
            subordinates[u]++;
        }
    }
}

ll N = 3e5+7;
ll mod = 998244353;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    adj.resize(n+1);
    visited.resize(n+1, false);
    subordinates.resize(n+1, 0);
    LOOP(2, n+1){
        ll v;
        cin >> v;
        adj[v].push_back(i);
        adj[i].push_back(v);
    } 
    find_subordinates(1);
    LOOP(1, n+1){
        cout << subordinates[i] << " ";
    }   
    visited.clear();
    subordinates.clear();
    adj.clear(); 
    return 0;
}