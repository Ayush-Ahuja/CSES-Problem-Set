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
vector<vector<char>> grid;
vector<vector<pair<ll, ll>>> dist;
vector<vector<char>> par;
vector<vector<bool>> visited;

bool is_valid(pair<ll, ll> p){
    if((p.first>=0) && (p.first< n) && (p.second >=0) && (p.second < m)){
        return true;
    }
    return false;
}

void bfs(vector<pair<ll, ll>> starts){
    queue<pair<ll ,ll>> q;
    for (auto start : starts){
        par[start.first][start.second] = '0';
        visited[start.first][start.second] = true;
        q.push(start);
    }
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
                dist[left.first][left.second] = {1 + dist[temp.first][temp.second].first, dist[temp.first][temp.second].second};
                q.push(left);
            }
            if (dist[temp.first][temp.second].second == 1 && dist[temp.first][temp.second].first + 1 == dist[left.first][left.second].first){
                dist[left.first][left.second].second = 1;
            }
        }
        if(is_valid(right)){
            if(grid[right.first][right.second] == '.' && !visited[right.first][right.second]){
                visited[right.first][right.second] = true;
                par[right.first][right.second] = 'R';
                dist[right.first][right.second] = {1 + dist[temp.first][temp.second].first, dist[temp.first][temp.second].second};
                q.push(right);
            }
            if (dist[temp.first][temp.second].second == 1 && dist[temp.first][temp.second].first + 1 == dist[right.first][right.second].first){
                dist[right.first][right.second].second = 1;
            }
        }
        if(is_valid(up)){
            if(grid[up.first][up.second] == '.' && !visited[up.first][up.second]){
                visited[up.first][up.second] = true;
                par[up.first][up.second] = 'U';
                dist[up.first][up.second] = {1 + dist[temp.first][temp.second].first, dist[temp.first][temp.second].second};
                q.push(up);
            }
            if (dist[temp.first][temp.second].second == 1 && dist[temp.first][temp.second].first + 1 == dist[up.first][up.second].first){
                dist[up.first][up.second].second = 1;
            }
        }
        if(is_valid(down)){
            if(grid[down.first][down.second] == '.' && !visited[down.first][down.second]){
                visited[down.first][down.second] = true;
                par[down.first][down.second] = 'D';
                dist[down.first][down.second] = {1 + dist[temp.first][temp.second].first, dist[temp.first][temp.second].second};
                q.push(down);
            }
            if (dist[temp.first][temp.second].second == 1 && dist[temp.first][temp.second].first + 1 == dist[down.first][down.second].first){
                dist[down.first][down.second].second = 1;
            }
        }
    }
}

ll N = 3e5+7;
ll mod = 998244353;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    dist.resize(n, vector<pair<ll, ll>>(m, {-1, -1}));
    par.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m, false));
    vector<pair<ll, ll>> monsters; 
    pair<ll, ll> start;
    LOOP(0, n){
        LOOP_(0, m, j){
            cin >> grid[i][j];
            if(grid[i][j] == 'A'){
                start = {i, j};
                grid[i][j] = '.';
                dist[i][j] = {0, 0};
            }
            if(grid[i][j] == 'M'){
                monsters.push_back({i, j});
                grid[i][j] = '.';
                dist[i][j] = {0, 1};
            }
        }
    } 
    monsters.push_back(start);
    bfs(monsters);   
    LOOP(0, n){
        LOOP_(0, m, j){
            if (grid[i][j] == '.' && (i == 0 || j == 0 || i == n-1 || j == m-1)){
                if (dist[i][j].second == 0){
                    cout << "YES\n";
                    cout << dist[i][j].first << "\n";
                    vector<char> tempp;
                    pair<ll, ll> temp = {i, j};
                    for(auto c = par[i][j]; c!= '0'; ){
                        if(c == 'L'){
                            temp = {temp.first, temp.second+1};
                            // tempp.push_back('R');
                        }
                        else if(c == 'R'){
                            temp = {temp.first, temp.second-1};
                            // tempp.push_back('L');
                        }
                        else if(c == 'D'){
                            temp = {temp.first-1, temp.second};
                            // tempp.push_back('U');
                        }
                        else if(c == 'U'){
                            temp = {temp.first+1, temp.second};
                            // tempp.push_back('D');
                        }       
                        tempp.push_back(c);    
                        c = par[temp.first][temp.second];
                    }
                    reverse(tempp.begin(), tempp.end());
                    LOOP_(0, tempp.size(), k){
                        cout << tempp[k];
                    }
                    cout << "\n";
                    return 0;
                }
            } 
        }
    }
    cout << "NO\n";
    return 0;
}