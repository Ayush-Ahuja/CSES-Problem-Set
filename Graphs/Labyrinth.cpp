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

bool is_valid(pair<ll, ll> p){
    if((p.first>=0) && (p.first< n) && (p.second >=0) && (p.second < m)){
        return true;
    }
    return false;
}

ll N = 3e5+7;
ll mod = 998244353;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<ll>> dist(n, vector<ll>(m, 0));
    vector<vector<char>> par(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m));
    pair<ll, ll> start;
    pair<ll, ll> end;
    LOOP(0, n){
        LOOP_(0, m, j){
            cin >> grid[i][j];
            if(grid[i][j] == 'A'){
                start = {i, j};
                grid[i][j] = '.';
            }
            if(grid[i][j] == 'B'){
                end = {i, j};
                grid[i][j] = '.';
            }
        }
    }    
    queue<pair<ll ,ll>> q;
    par[start.first][start.second] = '0';
    visited[start.first][start.second] = true;
    q.push(start);
    while(!q.empty()){
        pair<ll, ll> temp = q.front();
        q.pop();
        pair<ll, ll> left = {temp.first, temp.second-1};
        pair<ll, ll> right = {temp.first, temp.second+1};
        pair<ll, ll> down = {temp.first+1, temp.second};
        pair<ll, ll> up = {temp.first-1, temp.second};
        if(is_valid(left)){
            if(grid[left.first][left.second] == '.' && !visited[left.first][left.second]){
                visited[left.first][left.second] = true;
                par[left.first][left.second] = 'L';
                dist[left.first][left.second] = 1 + dist[temp.first][temp.second];
                q.push(left);
            }
        }
        if(is_valid(right)){
            if(grid[right.first][right.second] == '.' && !visited[right.first][right.second]){
                visited[right.first][right.second] = true;
                par[right.first][right.second] = 'R';
                dist[right.first][right.second] = 1 + dist[temp.first][temp.second];
                q.push(right);
            }
        }
        if(is_valid(up)){
            if(grid[up.first][up.second] == '.' && !visited[up.first][up.second]){
                visited[up.first][up.second] = true;
                par[up.first][up.second] = 'U';
                dist[up.first][up.second] = 1 + dist[temp.first][temp.second];
                q.push(up);
            }
        }
        if(is_valid(down)){
            if(grid[down.first][down.second] == '.' && !visited[down.first][down.second]){
                visited[down.first][down.second] = true;
                par[down.first][down.second] = 'D';
                dist[down.first][down.second] = 1 + dist[temp.first][temp.second];
                q.push(down);
            }
        }
    }
    if (dist[end.first][end.second] == 0){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
        cout << dist[end.first][end.second] << "\n";
        vector<char> tempp;
        pair<ll, ll> temp = end;
        for(auto c = par[end.first][end.second]; c!= '0'; ){
            if(c == 'L'){
                temp = {temp.first, temp.second+1};
            }
            else if(c == 'R'){
                temp = {temp.first, temp.second-1};
            }
            else if(c == 'D'){
                temp = {temp.first-1, temp.second};
            }
            else if(c == 'U'){
                temp = {temp.first+1, temp.second};
            }
            tempp.push_back(c);
            c = par[temp.first][temp.second];
        }
        reverse(tempp.begin(), tempp.end());
        LOOP(0, tempp.size()){
            cout << tempp[i];
        }
        cout << "\n";
    }

    return 0;
}