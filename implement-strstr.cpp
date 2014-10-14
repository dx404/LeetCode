class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if (*needle == '\0')
            return haystack;
        char *pStart = haystack;
        
        int needleSum = 0;
        int needleCount = 0;
        for(char *p = needle; *p != '\0'; p++) {
            needleSum += *p;
            needleCount++;
        }
        int pStartSum = 0;
        for(int i = 0; i < needleCount; i++) {
            if (pStart[i] == '\0')
                return NULL;
            pStartSum += pStart[i];
        }
        while (*pStart) {
            if (pStartSum == needleSum && sameString(pStart, needle, needleCount)){
                return pStart;
            }
            pStartSum -= *pStart;
            pStart++;
            pStartSum += pStart[needleCount-1];
        }
        return NULL;
    }
    
    bool sameString(char *a, char *b, int n) {
        int i = 0;
        while (i < n && *a && *b && *a == *b) {
            a++;
            b++;
        }
        return (*b == '\0');
    }
};
