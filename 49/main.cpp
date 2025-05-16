#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<vector<string>> groupAnagrams(const vector<string> &strs) {
        vector<pair<string, int>> sis(strs.size()); // sorted str, original index
        for (int i = 0; i < strs.size(); i++) {
            sis[i].first = strs[i];
            sort(sis[i].first.begin(), sis[i].first.end());
            sis[i].second = i;
        }

        sort(sis.begin(), sis.end(), [](const auto &a, const auto &b) {
            return a.first < b.first;
        });
        vector<vector<string>> anagrams;
        vector<string> group = {strs[sis[0].second]};
        for (int i = 1; i < sis.size(); i++) {
            if (sis[i - 1].first != sis[i].first) {
                anagrams.push_back(group);
                group = {strs[sis[i].second]};
            } else {
                group.push_back(strs[sis[i].second]);
            }
        }
        anagrams.push_back(group);

        return anagrams;
    }
};
