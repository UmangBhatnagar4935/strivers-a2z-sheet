
/*
Approach simple - 
1 - you can simple count the number how many times comes but only 1 numbers
2 - whenver consectiveness break then you can set count = 0

*/


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxi = 0;

        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 1){
                count = count + 1;
                maxi = max(maxi,count);
            }else{
                count = 0;
            }
        }
        return maxi;
    }
};