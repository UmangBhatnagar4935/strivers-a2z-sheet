#include <bits/stdc++.h> 
using namespace std;

class Solution{
    public:
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searche
    // TC = 0(n) - becasue we are traversaling the entire array 
    int searchInSorted(int arr[], int N, int K){ 
       // Your code here
       for(int index = 0; index < N; index++){
           if(arr[index] == K){
               return 1;
           }
       }
       return -1;
       
    }

    // we want to optimize the time complexity 
    // we can use binary search algorithm to search the element in the sorted the array
    // tc = 0(logN)
    // sc = 0(1)
      int searchInSorted(int arr[], int N, int K){ 
       // Your code here
        int start = 0; 
        int end = N - 1;
        
        int mid = start + (end - start)/2;
        
        while(start <= end){
            if(arr[mid] == K){
                return 1;
            }else if(arr[mid] < K){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
            // when you update the start and end any one of the them
            // you need to update the middle value 
            mid = start + (end - start)/2;
        }
        return -1;
    }


};

int main(void) {    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        cout << ob.searchInSorted(arr, n, k) << endl;

    }

	return 0; 
} 
