#include <bits/stdc++.h>
using namespace std;
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


// your code would be started ---------------
class Solution
{
    public:
    int select(int arr[], int i)
    {
        // code here such that selectionSort() sorts arr[]
        return 0;
    }
     
    void selectionSort(int arr[], int n)
    {
       //code here
       
    //   here  - mini = smallest value of index number 
       
        for(int i=0;i<=n-2;i++)
           {
              int mini=i;
            for(int j=i;j<=n-1;j++)
            {
                if(arr[j]<arr[mini])
                mini=j;
            }
            swap(arr[mini],arr[i]);
         }
    }
};

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
int main()
{
    int arr[1000],n,T,i;
  
    scanf("%d",&T);
    
    while(T--){
        
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      
    Solution ob;  
    ob.selectionSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}
