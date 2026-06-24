class StockSpanner {
public:
    stack<pair<int, int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(st.empty()){
            st.push({price, 1});
            return 1;
        }
        else{
            int temp{1};
            if(st.top().first <= price){
                while(!st.empty() && st.top().first <= price){
                    temp += st.top().second;
                    st.pop();
                }
                st.push({price, temp});
                return temp;
            }
            else{
                st.push({price, 1});
                return 1;
            }
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */