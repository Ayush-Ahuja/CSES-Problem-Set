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
ll mod2 = 1e9 + 7;
vector<vector<char>> grid;
vector<vector<ll>> paths;
ll n;

ll findPaths(ll row, ll col){
  ll ans = 0;
  if (grid[row][col] == '*') return 0;
  if (row == 0 && col == 0) return 1;
  if (paths[row][col] != -1) return paths[row][col];
  if ((row-1) >= 0 && grid[row-1][col] == '.'){
    ans = (ans + findPaths(row-1, col))%mod2;
  }
  if ((col-1) >= 0 && grid[row][col-1] == '.'){
    ans = (ans + findPaths(row, col-1))%mod2;
  }
  return paths[row][col] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    grid.resize(n, vector<char>(n));
    paths.resize(n, vector<ll>(n, -1));
    LOOP(0, n){
      LOOP_(0, n, j){
        cin >> grid[i][j];
      }
    }
    cout << findPaths(n-1, n-1) << "\n";
    return 0;
}