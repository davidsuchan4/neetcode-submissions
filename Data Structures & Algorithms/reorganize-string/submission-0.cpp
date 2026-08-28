class Solution {
   public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        for (int i{}; i < s.size(); ++i) {
            ++freq[s[i]];
        }
        priority_queue<pair<int, char>> heap;
        for(auto& [key, value] : freq){
            heap.push({value, key});
        }

        string res{};
        while(!heap.empty()){
            pair<int, char> top = heap.top();
            heap.pop();
            if(heap.empty()){
                res += top.second;
                --top.first;
                if(top.first > 0){
                    heap.push(top);
                }
                break;
            }
            else{
                pair<int, char> second = heap.top();
                heap.pop();
                res += top.second;
                res += second.second;
                --top.first;
                --second.first;
                if(top.first > 0){

                    heap.push(top);
                }
                if(second.first > 0){

                    heap.push(second);
                }
            }
        }
        if(heap.empty()){
            return res;
        }
        return "";


    }
};