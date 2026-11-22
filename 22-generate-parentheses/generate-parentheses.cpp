
class Solution {
    void parren(int n, string &output, int indx,
                int oc, int cc, vector<string>& ans) {

        if (indx == 2*n) {
            ans.push_back(output);
            return;
        }
        if (oc < n) {
            output[indx] = '(';
            parren(n, output, indx+1, oc+1, cc, ans);
        }
        if (cc < oc) {
            output[indx] = ')';
            parren(n, output, indx+1, oc, cc+1, ans);
        }
    }

public:
    vector<string> generateParenthesis(int n) {

        vector<string> ans;
        string output(2*n, ' ');

        parren(n, output, 0, 0, 0, ans);

        return ans;
    }
};
