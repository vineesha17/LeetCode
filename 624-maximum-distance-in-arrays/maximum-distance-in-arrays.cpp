class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int ans = 0;
        int minValue = arrays[0][0];
        int maxValue = arrays[0].back();

        for(int i = 1; i < arrays.size(); i++) {
            ans = max(ans, max( arrays[i].back() - minValue, maxValue - arrays[i][0]));

            minValue = min(minValue, arrays[i][0]);
            maxValue = max(maxValue, arrays[i].back());
        }
        return ans;
    }
};