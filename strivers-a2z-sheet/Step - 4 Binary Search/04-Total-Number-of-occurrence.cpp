#include<bits/stdc++.h>
using namespace std;

// total Occurence = lastindex - firstindex + 1;


//User function template for C++
class Solution{
private:
  int binarysearchForFirst(int arr[], int n, int x){
      int start = 0;
      int end = n;
      int key = x;
      
      int mid = start + (end- start)/2;
      
      int result1 = -1;
      
      while(start<=end){
          if(arr[mid] == key){
              result1 = mid;
              end = mid-1;
          }else if(arr[mid] < key){
              start = mid + 1;
          }else{
              end = mid -1;
          }
          mid = start + (end- start)/2;
      }
      return result1;
  }
  int binarysearchForLast(int arr[], int n, int x){
      int start = 0;
      int end = n;
      int key = x;
      
      int mid = start + (end- start)/2;
      
      int result2 = -1;
      
      while(start<=end){
          if(arr[mid] == key){
              result2 = mid;
              start = mid + 1;
          }else if(arr[mid] < key){
              start = mid + 1;
          }else{
              end = mid -1;
          }
          mid = start + (end- start)/2;
      }
      return result2;
  }
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    // according to questions - Given a sorted array Arr of size N and a number X
	    // we can use binary search mindset
	    int firstPostion = binarysearchForFirst(arr,n,x);
	    int lastPostion = binarysearchForLast(arr,n,x);
	    
	    if(firstPostion == -1 && lastPostion == -1)
	    return 0;
	      
	    int NumberOccurrence = lastPostion - firstPostion +1;
	    return NumberOccurrence;
	}
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}
