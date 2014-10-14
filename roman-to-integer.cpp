class Solution {
public:
    int romanToInt(string s) {
        map<char, int> tr = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int preDigitVal = 0;
        int sum = 0;
        for (char c : s){
            int curDigitVal = tr[c];
            sum = (curDigitVal <= preDigitVal) ? sum + preDigitVal : sum - preDigitVal; 
            preDigitVal = curDigitVal;
        }
        sum += preDigitVal;
        return sum;
    }
};