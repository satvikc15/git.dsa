class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int count=0;
        int sum=0;
        mpp[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            //if(sum==k) count++;
            if(mpp.find(sum-k)!=mpp.end()){
                count+=mpp[sum-k];
            }
            mpp[sum]++;
        }
        return count;
    }
};