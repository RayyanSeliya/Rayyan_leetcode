class Solution {
public:

    string fn(string x) {
        string clc = "";
        int i = 0;
        int n = x.length();

        while (i < n) {
            int count = 1;
            while (i + 1 < n && x[i] == x[i + 1]) {
                count++;
                i++;
            }
            clc += to_string(count) + x[i];
            i++;  // Don't forget to move to the next character
        }

        return clc;
    }

    string solve(int n) {
        if (n == 1) return "1";

        string previous = solve(n - 1);
        string ans = fn(previous);
        cout << ans << " see this " << endl;

        return ans;
    }

    string countAndSay(int n) {
        return solve(n);
    }
};
