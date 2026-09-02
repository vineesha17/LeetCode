class Solution {
public:
    int maxArea(vector<int>& height) {
      int  n = height.size();
        int maxWt= 0;
      int lp = 0, rp = n - 1;
      while(lp<rp) {
        int w = rp - lp;
        int ht = min(height[lp], height[rp]);
        int currWt = w*ht;
        maxWt = max(maxWt, currWt);
        height[lp] < height[rp] ? lp++ : rp--;
      }
      return maxWt;
    }
};