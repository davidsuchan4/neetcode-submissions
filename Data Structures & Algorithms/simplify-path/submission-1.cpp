class Solution {
   public:
    string simplifyPath(string path) {
        path.push_back('/');
        stack<string> st;
        string cur{};

        for (int i{}; i < path.size(); ++i) {
            if(path[i] == '/'){
                if(cur == ""){
                    continue;
                }
                if(cur == "."){
                    cur = "";
                    continue;
                }
                else if(cur == ".."){
                    if(!st.empty()){
                        st.pop();
                    }
                    cur = "";
                }
                else{
                    st.push(cur);
                    cur = "";
                }
            }
            else{
                cur += path[i];
            }
        }

        string ret{};
        if(st.empty()){
            return "/";
        }
        while(!st.empty()){
            ret = '/' + st.top() + ret;
            st.pop();
        }

        return ret;
    }
};