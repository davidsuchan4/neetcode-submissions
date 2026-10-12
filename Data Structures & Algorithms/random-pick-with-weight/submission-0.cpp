#include <vector>
#include <numeric>
#include <random>

class Solution {
private:
    std::vector<int> probabilities;
    std::mt19937 gen;

public:
    Solution(std::vector<int>& w) : gen(std::random_device{}()) {
        // Push index 'i' into the array w[i] times to create exact weighted proportions
        for (int i = 0; i < w.size(); ++i) {
            for (int j = 0; j < w[i]; ++j) {
                probabilities.push_back(i); // Store the index 'i', not the weight 'w[i]'
            }
        }
    }
    
    int pickIndex() {
        std::uniform_int_distribution<size_t> dist(0, probabilities.size() - 1);
        return probabilities[dist(gen)];
    }
};
