class Solution {
public:
    string simplifyPath(string path) {
        string pc;
        vector<string> p ;
        path += "/";
        int n = path.length();
        int state = 0;
        string token = "";
        for(int i = 0; i < n; i++){
            char c = path[i];
            //Here is the DFA-driven
            switch(state){
                case 0:
                    if (c == '.'){
                        state = 2;
                    }
                    else if (c == '/'){
                        state = 0;
                    }
                    else {
                        token += c;
                        state = 1;   
                    }
                    break;
                case 1:
                    if (c == '/') {
                        p.push_back(token);
                        token = "";
                        state = 0;
                    }
                    else {
                        token += c;
                    }
                    break;
                case 2:
                    if (c == '.') {
                        state = 3;
                    }
                    else if (c == '/'){
                        state = 0;
                    }
                    else {
                        token = string(".") + c;
                        state = 1;
                    }
                    break;
                case 3:
                    if (c == '/') {
                        if (p.size() > 0)
                            p.pop_back();
                        state = 0;
                    }
                    else {
                        token = string("..") + c;
                        state = 1;
                    }
                    break;
                default:
                    break;
            }
        }
        pc = (p.size() == 0) ? "/" : "";
        for (int i = 0; i < p.size(); i++){
            pc = pc + "/" + p[i];
        }
        return pc;
    }
};

