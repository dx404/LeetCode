class Solution {
public:
    int evalRPN(vector<string> &tokens) {
    	int n = (int) tokens.size();
    	stack<string> evalStack;
    	for (int i = 0; i < n; i++){
    	    string token = tokens[i];
    		if (token == "+" || token == "-" ||
    		    token == "*" || token == "/" ) {
    			int b = stoi(evalStack.top());
    			evalStack.pop();
    			int a = stoi(evalStack.top());
    			evalStack.pop();
    			int c;
    			if (token == "+"){
    			    c = a + b;
    			}else if (token == "-") {
    			    c = a - b;
    			}else if (token == "*") {
    			    c = a * b;
    			}else if (token == "/") {
    			    c = a / b;
    			}
    			else{
    				cout << "error" << endl;
    			}
    			evalStack.push(to_string(c));
    		}
    		else{
    		    evalStack.push(tokens[i]);
    		}
    	}
        return stoi(evalStack.top());
    }
};