#include <bits/stdc++.h>
using namespace std;


// book Allocation - Variations Questions 

class Solution {
  private:
    bool valid(vector<int>& piles,long long int speed, int H){
        long long count = 0;
        
        for(auto it: piles){
            count += it/speed;
            if(it % speed != 0){
                count ++;
            }
        }
       return count <= H;
    }
  public:
    int Solve(int N, vector<int>& piles, int H) {
        // Code here
        int start = 1;
        int end = 1e9; // maximum element of the array
        int result = -1;
        
        while(start<=end){
            long long int mid = start + (end-start)/2;
            if(valid(piles,mid,H)){
                result = mid;
                end = mid - 1;
            }else{
                start = mid +1;
            }
        }
        return result;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}