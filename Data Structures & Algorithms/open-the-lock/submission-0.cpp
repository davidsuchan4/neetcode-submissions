class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<string, int>> q;
        set<string> st;

        for (int i = 0; i < deadends.size(); ++i) {
            st.insert(deadends[i]);
        }

        if (st.count("0000")) {
            return -1;
        }

        q.push({"0000", 0});
        st.insert("0000");

        while (!q.empty()) {
            string front = q.front().first;
            int moves = q.front().second;
            q.pop();

            if (front == target) {
                return moves;
            }

            for (int i = 0; i < 4; ++i) {
                string up = front;
                up[i] = (up[i] == '9') ? '0' : up[i] + 1;

                if (!st.count(up)) {
                    q.push({up, moves + 1});
                    st.insert(up);
                }

                string down = front;
                down[i] = (down[i] == '0') ? '9' : down[i] - 1;

                if (!st.count(down)) {
                    q.push({down, moves + 1});
                    st.insert(down);
                }
            }
        }

        return -1;
    }
};