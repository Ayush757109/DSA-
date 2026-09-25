class Solution {
public:
    string s;
    int i = 0;
    set<string> parseExpr() {
        set<string> result = parseTerm();

        while (i < s.size() && s[i] == ',') {
            ++i;  // skip ','

            set<string> next = parseTerm();
            result.insert(next.begin(), next.end());
        }

        return result;
    }
    set<string> parseTerm() {
        set<string> result = {""};

        while (i < s.size() && s[i] != '}' && s[i] != ',') {
            set<string> factor = parseFactor();

            set<string> combined;

            for (const string& a : result) {
                for (const string& b : factor) {
                    combined.insert(a + b);
                }
            }

            result = move(combined);
        }

        return result;
    }
    set<string> parseFactor() {
        if (s[i] == '{') {
            ++i;  

            set<string> result = parseExpr();

            ++i; 
            return result;
        }
        return {string(1, s[i++])};
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        i = 0;

        set<string> result = parseExpr();

        return vector<string>(result.begin(), result.end());
    }
};