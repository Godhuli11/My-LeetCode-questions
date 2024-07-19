class Solution {
public:
     bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        unordered_map<int, int> count;
        for (int card : hand) {
            count[card]++;
        }

        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (const auto& pair : count) {
            minHeap.push(pair.first);
        }

        while (!minHeap.empty()) {
            int start = minHeap.top();
            for (int i = 0; i < groupSize; ++i) {
                if (count[start + i] == 0) {
                    return false;
                }
                count[start + i]--;
                if (count[start + i] == 0) {
                    if (start + i != minHeap.top()) {
                        return false;
                    }
                    minHeap.pop();
                }
            }
        }

        return true;
    }
};