class Solution {
public:
    // Math Computation
    vector<int> factorial = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    string nums = "123456789";
    string getPermutation(int n, int k) {
        string result;
        int r = k - 1;
        for (int pos = 0; pos < n; pos++) {
            int x =  r / factorial[n - pos - 1];
            result += nums[x];
            nums.erase(x,1);
            r %= factorial[n - pos - 1];
        }
        return result;
    }
};
