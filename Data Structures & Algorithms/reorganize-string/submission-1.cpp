class Solution {
public:
    string reorganizeString(string s) {
        // 1. Count frequencies using a fast fixed-size array
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        // 2. Early exit: If the most frequent character is too dominant
        int maxLimit = (s.size() + 1) / 2;
        priority_queue<pair<int, char>> heap;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] > 0) {
                if (freq[i] > maxLimit) return ""; 
                heap.push({freq[i], 'a' + i});
            }
        }

        string res = "";
        // This pair holds the character we just used so it isn't picked immediately next
        pair<int, char> prev = {-1, '#'}; 

        // 3. Process one character at a time
        while (!heap.empty()) {
            pair<int, char> current = heap.top();
            heap.pop();

            // Append the highest frequency available character
            res += current.second;
            current.first--;

            // If the PREVIOUS character still has remaining counts, 
            // it is now safe to put back into the heap
            if (prev.first > 0) {
                heap.push(prev);
            }

            // Keep track of the current character to delay it in the next loop iteration
            prev = current;
        }

        return res;
    }
};
