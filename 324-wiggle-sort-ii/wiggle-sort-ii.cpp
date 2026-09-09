class Solution {
public:
    void wiggleSort(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> ans(n);

        int left = (n-1) / 2;
        int right = n - 1;

        for(int i = 0; i < nums.size(); i++) {
            if(i % 2 == 0) {
                ans[i] = nums[left--];
            }
            else {
                ans[i] = nums[right--];
            }
        }
        nums = ans;
        
    }
};