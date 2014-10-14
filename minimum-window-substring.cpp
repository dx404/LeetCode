class Solution {  
public:  
    string minWindow(string S, string T) {  
        int data[260],i,j;  
        memset(data,0,sizeof(data));  
        for(i=0;i<T.length();++i)  
            data[T[i]]++;  
        int now[260],left,right,minn=1<<29,num=0;  
        memset(now,0,sizeof(now));  
        for(i=0,j=0;i<S.length();++i)   
        {  
            if(num<T.length())  
            {  
                if(now[S[i]]<data[S[i]])num++;  
                now[S[i]]++;  
            }  
            if(num==T.length())  
            {  
                while(j<=i&&now[S[j]]-1>=data[S[j]])  
                {  
                    --now[S[j]];  
                    ++j;                      
                }  
                if(minn>i-j+1)left=j,right=i,minn=i-j+1;  
            
                while(j<=i&&num==T.length())  
                {  
                    now[S[j]]--;  
                    if(now[S[j]]<data[S[j]])num--;  
                    ++j;  
                }    
            }  
        }  
        string temp;  
        if(minn<1<<29)return temp.assign(S,left,right-left+1);  
        else return "";  
    }  
};  