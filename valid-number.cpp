class Solution {
public:
    bool isNumber(const char *s) {
        char *c = const_cast<char *> (s);
        while (isspace(*c)) c++;
        if (*c == '+' || *c == '-'){
            c++;
        }
        bool iPart;
        if (!(iPart = isdigit(*c)) && *c != '.') 
            return false;
        while (isdigit(*c)) c++;      
        
        if (*c == '.'){
            c++;
            if (!iPart && !isdigit(*c)) 
                return false;
            while (isdigit(*c)) c++;
        }  
        
        if (*c == 'e' || *c == 'E'){
            c++;
            if (*c == '+' || *c == '-'){
                c++;
            }
            if (!isdigit(*c)) return false;
            while (isdigit(*c)) c++;
        }
        while (isspace(*c)) c++;
        return (*c=='\0');
    }
};