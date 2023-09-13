// #include<bits/stdc++.h>
#include<vector>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>m;

        // for(auto str: strs) {
        //     string key = getKey(str);
        //     m[key].push_back(str);
        // }
        // vector<vector<string>> result;
        // for(auto it = m.begin(); it!= m.end(); it++) {
        //     result.push_back(it->second);
        // }
        // return result;

        for(auto s : strs) {
            string word = s;
            sort(word.begin(), word.end());
            m[word].push_back(s);
        }

        vector<vector<string>>res;
        for(auto i: m) {
            res.push_back(i.second);
        }
        return res;
    }

    private:
    string getKey(string str) {
        vector<int>count(26);

        for(int i=0;i<str.size();i++) {
            count[str[i]-'a']++;
        }

        string key ="";

        for(auto i: count) {
            key.append(to_string(i) + "#");
        }
        return key;
    }
};