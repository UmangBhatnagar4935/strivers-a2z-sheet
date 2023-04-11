#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int largest(vector<int> &arr, int n) {
        
        // bruthforce approach 
        // - sort the array 
        // - return arr[n-1]
        
        // start code
        int large = arr[0];
        for(int i = 1 ; i< n; i++){
            if(arr[i] > large){
                large = arr[i];
            }
        }
        return large;
    }
};


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int>arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        cout << ob.largest(arr, n) << "\n";
    }
    return 0;
}
