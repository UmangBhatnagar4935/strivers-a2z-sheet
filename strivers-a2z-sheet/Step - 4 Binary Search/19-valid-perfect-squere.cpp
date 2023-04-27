#include<bits/stdc++.h> 
using namespace std; 


/*
 ( this question is based on the binary search + search space concept )
*/

class Solution{   
public:
    int checkPerfectSquare(int N){
        // code here 
        int start = 0;
        int end = N;
        int mid = start + (end-start)/2;
        
        while(start<=end){
            int value = mid * mid;
            if(value == N) return 1;
            if(value < N ) start = mid + 1;
            if(value > N ) end = mid - 1;
            mid = start + (end-start)/2;
        }
        return 0;
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.checkPerfectSquare(N) << endl;
    }
    return 0; 
} 
