class Solution {
   public:
    string decodeString(string s) {
        stack<string> stringStack;
        stack<int> times;
        string k{};
        string cur{};

        for (int i{}; i < s.size(); ++i) {
            if (isdigit(s[i])) {
                k += s[i];
            } else if (s[i] == '[') {
                times.push(stoi(k));
                stringStack.push(cur);
                k = "";
                cur = "";
            } else if (s[i] >= 'a' && s[i] <= 'z') {
                cur += s[i];
            } else if (s[i] == ']') {
                string temp = cur;
                cur = stringStack.top();
                stringStack.pop();

                string repeated;
                repeated.reserve(temp.size() * times.top());
                for (int i = 0; i < times.top(); i++) {
                    repeated += temp;
                }

                cur += repeated;
                times.pop();
            }
        }
        return cur;
    }
};