class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i{}; i < tokens.size(); ++i){
            int temp{};
            int temp2{};
            if(isdigit(tokens[i].back())){
                st.push(stoi(tokens[i]));
            }
            else if(tokens[i][0] == '+'){
                temp = st.top();
                st.pop();
                temp2 = st.top();
                st.pop();
                st.push(temp2 + temp);
            }
            else if(tokens[i][0] == '-' && tokens[i].size() == 1){
                temp = st.top();
                st.pop();
                temp2 = st.top();
                st.pop();
                st.push(temp2 - temp);
            }
            else if(tokens[i][0] == '*'){
                temp = st.top();
                st.pop();
                temp2 = st.top();
                st.pop();
                st.push(temp2 * temp);
            }
            else if(tokens[i][0] == '/'){
                temp = st.top();
                st.pop();
                temp2 = st.top();
                st.pop();
                st.push(temp2 / temp);
            }
        }
        return st.top();
    }
};