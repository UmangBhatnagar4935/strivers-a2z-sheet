#include<bits/stdc++.h>
using namespace std;


// #striversAtoZSheet
// #45Days

class Solution
{
    public:
		long long int reverse_digit(long long int n)
		{
		    // start code
		    int newdigit = 0;
		    
		    while(n > 0){
		        
		        int lastdigits = n % 10;
		        n = n / 10;
		        
		        newdigit = newdigit * 10 + lastdigits;
		    }
		    return newdigit;
		}
};

int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int n;
    	cin >> n;
    	Solution ob;
    	long long int  ans = ob.reverse_digit(n);
    	cout << ans <<"\n";
    }
	return 0;
}