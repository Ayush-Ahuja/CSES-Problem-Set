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
ll mod = 998244353;

vector<vector<char>> visited;
vector<vector<char>> mp;
ll n, m;

void dfs(ll s_i, ll s_j){
    visited[s_i][s_j] = true;
    vector<pair<ll, ll>> near = {{s_i+1, s_j}, {s_i-1, s_j}, {s_i, s_j+1}, {s_i, s_j-1}};
    for (auto p : near){
        if (p.first >=0 && p.first < n && p.second >=0 && p.second < m 
            && !visited[p.first][p.second] && mp[p.first][p.second] == '.'){
                dfs(p.first, p.second);
        }
    }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  mp.resize(n, vector<char>(m));
  visited.resize(n, vector<char>(m, false));
  LOOP(0, n){
    LOOP_(0, m, j){
        cin >> mp[i][j];
    }
  } 
  ll ans = 0;
  LOOP(0, n){
    LOOP_(0, m, j){
        if (!visited[i][j] && mp[i][j] == '.'){
            dfs(i, j);
            ans++;
        }
    }
  }
  cout << ans << "\n";
  return 0;  
}