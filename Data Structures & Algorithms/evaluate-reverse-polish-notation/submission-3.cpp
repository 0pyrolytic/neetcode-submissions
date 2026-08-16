class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>currStack;
        int result, top;
        for(string & c : tokens){
            if(!isdigit(c[0]) && c.size() == 1){
                top = currStack.top();
                currStack.pop();
                switch(c[0]){
                    case'+':
                        result = (currStack.top()) + top;
                        break;
                    case'-':
                        result = (currStack.top()) - top;
                        break;
                    case'*':
                        result = (currStack.top()) * top;
                        break;
                    case'/':   
                        result = (currStack.top()) / top;
                        break;
                }
                currStack.pop();
                currStack.push(result);
            }else{
                currStack.push(stoi(c));
            }
        }

        return currStack.top();
    }
};
