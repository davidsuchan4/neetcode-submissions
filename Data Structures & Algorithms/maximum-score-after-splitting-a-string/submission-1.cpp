class Solution {
public:
    int maxScore(string s) {
        int ret = 0;
        for(int i{ 1 }; i < s.size(); ++i){
            string sub1 = s.substr(0, i);
            string sub2 = s.substr(i);
            int score1{};
            int score2{};
            for(int w{ 0 }; w < sub1.size(); ++w){
                if(sub1[w] == '0'){
                    ++score1;
                }
            }
            for(int q{ 0 }; q < sub2.size(); ++q){
                if(sub2[q] == '1'){
                    ++score2;
                }
            }
            ret = max(ret, score1 + score2);
        }
        return ret;
    }
};