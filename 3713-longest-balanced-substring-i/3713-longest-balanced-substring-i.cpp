class Solution {
public:
   
    int longestBalanced(string s) {
        int n = s.length();
        int maxlen = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mp;

            for (int j = i; j < n; j++) {

                mp[s[j]]++;

                if (mp.size() == 1) {
                    maxlen = max(maxlen, j - i + 1);
                    continue;
                }

                int freq = mp.begin()->second;
                bool ok = true;

                for (auto& it : mp) {
                    if (it.second != freq) {
                        ok = false;
                        break;
                    }
                }

                if (ok) {
                    maxlen = max(maxlen, j - i + 1);
                }
            }
        }

        return maxlen;
    }
};