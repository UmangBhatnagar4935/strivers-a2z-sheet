
#include <bits/stdc++.h>
using namespace std;

// Company Tags -:
// PaytmGoldman SachsFab.com

class Solution{   
public:
    // approach 1 used : couting approach - we will count 0 and 1 using two variable 
    void segregate0and1(int arr[], int n) {
        // code here
        int count0 = 0;
        int count1 = 0;
        
        for(int i = 0; i<n; i++){
            if(arr[i] == 0){
                count0 ++;
            }else{
                count1 ++;
            }
        }
        
        for(int i = 0; i<count0; i++){
            arr[i] = 0;
        }
        
        for(int i = count0; i < n; i++){
            arr[i] = 1;
        }
    }
    // approach used - 2 : we can use two pointer algoritm 
     void segregate0and1(int arr[], int n) {
        // code here
        int start = 0;
        int end = n - 1;

        while(start < end){
            if(arr[start] ==  0 && start < end){
                start++;
            }else if(arr[end] == 1 &&start < end ){
                end--;
            }else if(arr[start] != 0 && arr[end] != 1 && start < end){
                swap(arr[start],arr[end]);
                start++;
                end--;
            } 
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.segregate0and1(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends