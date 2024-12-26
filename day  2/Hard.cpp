#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        vector<int> count(batchSize, 0);
        for (int group : groups) {
            count[group % batchSize]++;
        }
        int happyGroups = count[0];
        unordered_map<string, int> memo;
        return happyGroups + dfs(batchSize, count, memo);
    }

private:
    int dfs(int batchSize, vector<int>& count, unordered_map<string, int>& memo) {
        string key = encode(count);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        int maxHappy = 0;

        for (int i = 1; i < batchSize; i++) {
            if (count[i] > 0) {
                count[i]--;
                int additionalHappy = (i == batchSize - 1 || sum(count) % batchSize == 0) ? 1 : 0;
                maxHappy = max(maxHappy, additionalHappy + dfs(batchSize, count, memo));
                count[i]++;
            }
        }

        memo[key] = maxHappy;
        return maxHappy;
    }

    string encode(vector<int>& count) {
        string key = "";
        for (int c : count) {
            key += to_string(c) + ",";
        }
        return key;
    }

    int sum(vector<int>& count) {
        int total = 0;
        for (int c : count) {
            total += c;
        }
        return total;
    }
};

int main() {
    Solution solution;

    int batchSize1 = 3;
    vector<int> groups1 = {1, 2, 3, 4, 5, 6};
    cout << "Maximum Happy Groups: " << solution.maxHappyGroups(batchSize1, groups1) << endl;

    int batchSize2 = 4;
    vector<int> groups2 = {1, 3, 2, 5, 2, 2, 1, 6};
    cout << "Maximum Happy Groups: " << solution.maxHappyGroups(batchSize2, groups2) << endl;

    return 0;
}
