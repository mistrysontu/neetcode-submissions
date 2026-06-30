class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> stk;

        for(auto ch: s){
            if(ch == '(' || ch == '{' || ch == '['){
                stk.push(ch);
            }
            else{
                if(stk.size() == 0) return false;
                if((ch == ')' && stk.top() == '(') || (ch == '}' && stk.top() == '{') || (ch == ']' && stk.top() == '[')){
                    stk.pop();
                }
                else{
                    return false;
                }
            }
        }
        return stk.size() == 0;
    }
};
