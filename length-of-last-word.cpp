class Solution {
public:
    int lengthOfLastWord(const char *s) {
        bool counting = true;
        int c = 0;
        for (char *p = const_cast<char *> (s); *p != '\0'; p++){
            if (*p != ' ' && counting){
                c++;
            }
            else if (*p != ' ' && !counting){
                c = 1;
                counting = true;
            }
            else if (*p == ' ' && counting){
                counting = false;
            }
            else {
                
            }
        }
        return c;
    }
};