#include<bits/stdc++.h>
using namespace std;


/*
Bruth-force appraoch 
- try out the all the possible way - subarray
- find out the maximum sum 

*/


/*
kadane's Algorithm
- set two variable maximum_sum and current_sum
- array ke element ko add karte jao
- agar currsum maxisum se zada to maximum sum ko update kar do
- agar currsum negive side zara raha hai to currsum ko 0 bana do
*/

// agar negitve zara raha to 0 kar do baki kahani suru rakho addtion wali 


class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        long long maxisum = INT_MIN;
        long long currsum = 0;
        
        for(int i = 0; i<n; i++){
            currsum = currsum + arr[i];
            if(currsum > maxisum){
                maxisum = currsum;
            }
            // if currsum is gonna to negetive side we have to set currsum = 0;
            if(currsum < 0){
                currsum = 0;
            }
        }
        return maxisum;
    }
};


int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
