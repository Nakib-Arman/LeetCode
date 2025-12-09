class Solution {
public:
    int getMin(vector<int>& nums,int start, int end){
        int middle = (end-start)/2 + start;
        if(nums[start]<nums[middle] && nums[middle]<nums[end]) return nums[start];
        if(end-start<=2){
            if(nums[start]>nums[middle]) return nums[middle];
            if(nums[middle]>nums[end]) return nums[end];
            return nums[start];
        }
        if(nums[start]>nums[middle]) return getMin(nums,start,middle);
        else return getMin(nums,middle,end);
    }

    int findMin(vector<int>& nums) {
        return getMin(nums,0,nums.size()-1);
    }
};