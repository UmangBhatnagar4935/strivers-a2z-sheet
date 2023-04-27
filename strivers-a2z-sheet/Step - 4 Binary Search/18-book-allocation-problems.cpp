#include<bits/stdc++.h>
using namespace std;


/*
This Question is based on the Binary search + Search Space concept 
*/

class Solution {
    private: 
    bool validAllocation(int A[], int N, int M, int mid){
        
        int pagesum=0;
        int stucount=1;

        for(int i=0;i<N;i++){
           if(pagesum+A[i]<=mid) 
               pagesum+=A[i];
           else{
               stucount++;
               if(stucount > M || A[i]>mid){
                    return false;
               }
                pagesum=A[i];
           }
        }
        return true;
    }
    public:
    //Function to find minimum number of pages.
    int findPages(int arr[], int N, int M) 
    {
        // kya pata humre pass array size 1 ho or student 2 ho tab alllocation possible hi nahi hai
        // return -1;
        if(N < M)
        return -1;
        
        int maxElement = INT_MIN;
        int sum = 0;
        
        for(int i = 0; i<N; i++){
            sum = sum + arr[i];
            maxElement = max(maxElement,arr[i]);
        }
        
        // we can set start and end variable using maxElement and sum of the array 
        int start = maxElement;
        int end = sum;
        int result = -1;
        
        while(start<=end){
            int mid=start+(end-start)/2;
            // if you are able to allocate books then this function would return true
            if(validAllocation(arr,N,M,mid) == true){
                result = mid;
                end = mid -1;
            }else{
                start = mid + 1;
            }
        }
        return result;
    }
};


int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
