#include <bits/stdc++.h>
using namespace std;

// Approach 1: Sorting Key
vector<vector<string>> groupAnagramsSort(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for (string s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        mp[key].push_back(s);
    }
    vector<vector<string>> result;
    for (auto& [k, group] : mp) {
        result.push_back(group);
    }
    return result;
}

// Approach 2: Frequency Count Key
vector<vector<string>> groupAnagramsFreq(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for (string s : strs) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c-'a']++;
        string key;
        for (int f : freq) key += "#" + to_string(f); // unique encoding
        mp[key].push_back(s);
    }
    vector<vector<string>> result;
    for (auto& [k, group] : mp) {
        result.push_back(group);
    }
    return result;
}

int main() {
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    auto res1 = groupAnagramsSort(strs);
    cout << "Sorting Key Approach:\n";
    for (auto& group : res1) {
        for (auto& w : group) cout << w << " ";
        cout << endl;
    }

    auto res2 = groupAnagramsFreq(strs);
    cout << "\nFrequency Count Approach:\n";
    for (auto& group : res2) {
        for (auto& w : group) cout << w << " ";
        cout << endl;
    }

    return 0;
}
