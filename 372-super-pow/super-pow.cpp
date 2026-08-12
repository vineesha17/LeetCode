class Solution {
public:
    int powmod(int a, int n) {
        int result = 1;
        for(int i = 0; i < n; i++) {
            result = (result * a) % 1337;
        }
        return result;
    }
    int superPow(int a, vector<int>& b) {
        a = a % 1337;

        int result = 1;

        for(int digit : b) {
            result = powmod(result, 10) * powmod(a, digit) % 1337;
        }
        return result;
    }
};