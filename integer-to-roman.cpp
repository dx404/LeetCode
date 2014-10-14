class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, string> tr = {
            {0, ""}, 
            {1, "I"},   {10, "X"},    {100, "C"}, {1000, "M"},
            {2, "II"},  {20, "XX"},   {200, "CC"}, {2000, "MM"},
            {3, "III"}, {30, "XXX"},  {300, "CCC"}, {3000, "MMM"},
            {4, "IV"},  {40, "XL"},   {400, "CD"},
            {5, "V"},   {50, "L"},    {500, "D"},
            {6, "VI"},  {60, "LX"},   {600, "DC"},
            {7, "VII"}, {70, "LXX"},  {700, "DCC"},
            {8, "VIII"},{80, "LXXX"}, {800, "DCCC"},
            {9, "IX"},  {90, "XC"},   {900, "CM"}
        };
        string roman = "";
        for (int x = num, base = 1; x != 0; x /= 10, base *= 10){
            roman = tr[(x % 10)*base] + roman;
        }
        return roman;
        
    }
};