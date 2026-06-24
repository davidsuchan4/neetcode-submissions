class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ret{};
        for(int i { 0 }; i < words.size(); ++i){
            for(int w{i + 1}; w < words.size(); ++w){
                ret += isPrefix(words[i], words[w]);
            }
        }
        return ret;
    }

    int isPrefix(string small, string big){
        int bigsize = big.size();
        int smallsize = small.size();

        for(int i{ 0 }; i < small.size(); ++i){
            if(small[i] == big[i] && small[smallsize - 1 - i] == big[bigsize - 1 - i]){

            }
            else if(smallsize > bigsize){
                return 0;
            }
            else{
                return 0;
            }
        }
        return 1;
        

    }
};