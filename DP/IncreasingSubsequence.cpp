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

class Solution {
    private:
        int tails[200007];
    public:
        int lengthOfLIS(vector<int>& nums) {
            memset(tails, 0, sizeof(tails));
            int size = 1;
            tails[1] = nums[0];
            for(int i = 0; i< nums.size(); i++){
                int l = 1, r = size;
                int mid = (l+r)/2;
                while(l != r){
                    mid = (l+r)/2;
                    if (tails[mid] < nums[i]){
                        l = mid+1;
                    }
                    else{
                        r = mid;
                    }
                }
                if (nums[i] > tails[r]){
                    tails[r+1] = nums[i];
                    size++;
                }
                else{
                    tails[l] = min(nums[i], tails[l]); 
                }
            }
            return size;
        }
    };

ll N = 3e5+7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    vector<int> arr;
    cin >> n;
    LOOP(0, n){
      int s;
      cin >> s;
      arr.push_back(s);
    }
    Solution ss;
    cout << ss.lengthOfLIS(arr);
}