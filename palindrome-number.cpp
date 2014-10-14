class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) 
            return false;
        if (!(x % 10) && x)  // A corner case : 10 or 010 ? 
            return false;
        int y = 0;
        while (x > y) { //meet in the middle
            y = 10 * y + x % 10;
            x /= 10;
        }
        return (x == y || x == y / 10);
    }
};