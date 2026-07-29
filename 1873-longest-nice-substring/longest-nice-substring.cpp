class Solution {
public:
    bool isNice(string sub) {
        unordered_set<char> st;
        for (char ch : sub) {
            st.insert(ch);
        }

        for(char ch : sub) {
        if(islower(ch)) {
            if(!st.count(toupper(ch))) {
                return false;
            }
        }
        else {
            if(!st.count(tolower(ch))) {
                return false;
            }
        }
    }
        return true;
    }
    string longestNiceSubstring(string s) {
        string ans = "";
        for(int i = 0; i<s.size(); i++) {
            for(int j = i; j<s.size(); j++) {
                string sub = s.substr(i, j-i+1);

                if(isNice(sub)) {
            if(sub.size()>ans.size()) {
                ans = sub;
            }
        }
    }
}
        
     return ans;
    }
};