class Solution {
public:
    void helper(int left, int right, string temp, vector<string> &res){
        if(left == 0 && right == 0){
            res.push_back(temp);
            return;
        }
        if(left > 0){
            helper(left-1, right, temp+"(", res);
        }
        if(right > left){
            helper(left, right-1, temp+")", res);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(n, n, "", res);
        return res;
    }
};
