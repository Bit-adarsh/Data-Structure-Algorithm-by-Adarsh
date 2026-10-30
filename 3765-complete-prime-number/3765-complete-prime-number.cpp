class Solution {
public:

    bool isPrime(int n) {
        if (n <= 1)
            return false;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }

        return true;
    }

    bool completePrime(int num) {

        string s = to_string(num);
        int n = s.length();

        // Check prefixes
        for (int i = 1; i <= n; i++) {
            int prefix = stoi(s.substr(0, i));

            if (!isPrime(prefix))
                return false;
        }

        // Check suffixes
        for (int i = 0; i < n; i++) {
            int suffix = stoi(s.substr(i));

            if (!isPrime(suffix))
                return false;
        }

        return true;
    }
};