class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st; // Assuming 'st' is a stack<int>, defined here for completeness
        int n = tokens.size();
        
        for(int i = 0; i < n; i++) {
            if (tokens[i] == "+") {
                int x = st.top(); st.pop();
                int y = st.top(); st.pop();
                st.push(y + x);
            }
            else if (tokens[i] == "-") {
                int x = st.top(); st.pop();
                int y = st.top(); st.pop();
                st.push(y - x); // Order matters: second popped minus first popped
            }
            else if (tokens[i] == "*") {
                int x = st.top(); st.pop();
                int y = st.top(); st.pop();
                st.push(y * x);
            }
            else if (tokens[i] == "/") {
                int x = st.top(); st.pop();
                int y = st.top(); st.pop();
                st.push(y / x); // Order matters: second popped divided by first popped
            }
            else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};