#include <bits/stdc++.h>
using namespace std;

class Solution {
    // for first occance of elemenet in the sorted array  
  public:
  int binarySearchFindFirst(vector<int> &arr, int target){
      int start = 0;
      int end = arr.size() - 1;
      
      int mid = start + (end - start)/2;
      int pahli_mohbbat = -1;
      while(start<=end){
          if(arr[mid] == target){
             pahli_mohbbat = mid;
             end = mid - 1;
          }else if(arr[mid] < target){
              start = mid + 1;
          }else{
              end = mid - 1;
          }
          mid = start + (end - start)/2;
      }
      
      return pahli_mohbbat;
  }
   //  for last occance of element in the sorted array 
  public:
  int binarySearchFindLast(vector<int> &arr, int target){
      int start = 0;
      int end = arr.size() - 1;
      
      int mid = start + (end - start)/2;
      int akhari_mohbbat = -1;
      while(start<=end){
          if(arr[mid] == target){
             akhari_mohbbat = mid;
             start = mid + 1;
          }else if(arr[mid] < target){
              start = mid + 1;
          }else{
              end = mid - 1;
          }
          mid = start + (end - start)/2;
      }
      
      return akhari_mohbbat;
  }
   
   
  public:
    vector<int> firstAndLast(vector<int> &arr, int n, int x) {
        if(n == 0){
            return {-1};
        }

        //Helper Calls
        int first = binarySearchFindFirst(arr, x);
        int last = binarySearchFindLast(arr, x);
        if(first == -1 && last == -1)return {-1};
        
        return {first, last};
        
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> ans= obj.firstAndLast(arr, n, x) ;
        for(int i:ans){
            cout<<i<<" ";
        }
        cout<< endl;
    }
    return 0;
}
