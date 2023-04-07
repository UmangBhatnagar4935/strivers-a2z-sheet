#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
// find out the First occurrences of x
int binarysearch1(int arr[], int n, int key){
    
    int start = 0;
    int end = n - 1;
    int mid = 0;
     
    int postion_first = -1;
     
    while(start <= end){
      mid = (start) + (end - start)/2;
        
        if(arr[mid] == key){
            postion_first = mid;
            end = mid - 1;
        }else if(arr[mid] < key){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    return postion_first;
}

// find out the last occurrences of x
int binarysearch2(int arr[], int n, int key){
    
    int start = 0;
    int end = n - 1;
    int mid = 0;
     
    int postion_last = -1;
     
    while(start <= end){
      mid = (start) + (end - start)/2;
        
        if(arr[mid] == key){
          postion_last = mid;
          start = mid + 1;
        }else if(arr[mid] < key){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    return postion_last;
}
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    int first_postion = binarysearch1(arr,n,x);
	    int last_postion = binarysearch2(arr,n,x);
	    
	    int total_occurrence = last_postion - first_postion + 1;
	    
        if(first_postion == -1 && last_postion == -1){
            return 0;
        }else{
            return total_occurrence;
        }

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
