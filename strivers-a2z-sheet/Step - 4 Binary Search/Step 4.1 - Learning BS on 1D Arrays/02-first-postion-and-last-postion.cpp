#include<bits/stdc++.h>
using namespace std;


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

vector<int> find(int arr[], int n , int x )
{
    // code here
    int first_occurrence = binarysearch1(arr,n,x);
    int last_occurrence = binarysearch2(arr,n,x);
    
    return {first_occurrence , last_occurrence };
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}