
class Solution {
public:
    bool isPalindrome(int n) {

        if (n < 0)
            return false;

        int revNum = 0;
        int dup = n;

        while (n > 0) {

            int lastDigit = n % 10;

            n = n / 10;
        if(revNum > INT_MAX / 10 || revNum < INT_MIN / 10)
            return 0;

            revNum = revNum * 10 + lastDigit;
        }

        return dup == revNum;
    }
};
