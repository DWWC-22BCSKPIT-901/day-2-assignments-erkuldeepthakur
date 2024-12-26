#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <climits> // Include this for INT_MAX
#include <cstdio>  // For printf

using namespace std;

int minTeach(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
    int m = languages.size();
    
    // Convert each person's languages into a set for quick lookup
    vector<unordered_set<int>> languageSet(m);
    for (int i = 0; i < m; ++i) {
        languageSet[i] = unordered_set<int>(languages[i].begin(), languages[i].end());
    }
    
    // Find all friend pairs who cannot communicate
    vector<pair<int, int>> cannotCommunicate;
    for (const auto& f : friendships) {
        int a = f[0] - 1, b = f[1] - 1; // Convert to 0-based indexing
        bool canCommunicate = false;
        for (int lang : languageSet[a]) {
            if (languageSet[b].count(lang)) {
                canCommunicate = true;
                break;
            }
        }
        if (!canCommunicate) {
            cannotCommunicate.emplace_back(a, b);
        }
    }
    
    // If all friends can already communicate, no teaching is required
    if (cannotCommunicate.empty()) {
        return 0;
    }
    
    // Try teaching each language and calculate the minimum number of people to teach
    int minTeachCount = INT_MAX;
    for (int lang = 1; lang <= n; ++lang) {
        unordered_set<int> toTeach; // Set of people to teach the current language
        
        for (const auto& pair : cannotCommunicate) {
            int a = pair.first, b = pair.second;
            if (!languageSet[a].count(lang)) {
                toTeach.insert(a);
            }
            if (!languageSet[b].count(lang)) {
                toTeach.insert(b);
            }
        }
        
        minTeachCount = min(minTeachCount, static_cast<int>(toTeach.size()));
    }
    
    return minTeachCount;
}

int main() {
    vector<vector<int>> languages = {{1, 2}, {3, 4}, {1, 3}};
    vector<vector<int>> friendships = {{1, 2}, {2, 3}, {1, 3}};
    int n = 4;

    int result = minTeach(n, languages, friendships);
    printf("Minimum people to teach: %d\n", result); // Output: 1
    return 0;
}
