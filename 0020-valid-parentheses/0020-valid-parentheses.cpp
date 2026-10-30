
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char ch : s) {

            // If opening bracket, push into stack
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }

            // If closing bracket
            else {
                if (st.empty()) {
                    return false;
                }

                char top = st.top();

                if ((ch == ')' && top == '(') ||
                    (ch == '}' && top == '{') ||
                    (ch == ']' && top == '[')) {

                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        // Stack must be empty
        return st.empty();
    }
};
