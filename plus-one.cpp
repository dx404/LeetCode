class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> v;
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; i--){
            int nd = digits[i] + carry;
            int d = nd % 10;
            carry = nd /10;
            v.push_back(d);
        }
        if (carry != 0) {
            v.push_back(carry);
        }
        int n = v.size();
        for (int i = 0; i < n / 2; i++){
            int temp = v[i];
            v[i] = v[n-1-i];
            v[n-1-i] = temp;
        }
        return v;
    }
};