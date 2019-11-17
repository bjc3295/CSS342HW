#include <list>

#define MAX_SIZE 100

void _possibleParenthesis(int pos, int n, int open, int close, std::list<std::string> & result) {
    static char str[MAX_SIZE];

    if (close == n) {
        result.push_back(str);
        return;
    }
    if (open > close) {
        str[pos] = '}';
        _possibleParenthesis(pos + 1, n, open, close + 1, result);
    }
    if (open < n) {
        str[pos] = '{';
        _possibleParenthesis(pos + 1, n, open + 1, close, result);
    }
}

// n: size of the problem
// result: a list of string, each string represents a case of valid parentheses of size n
void possibleParenthesis(int n, std::list<std::string> & result) {
    // homework
     if (n > 0) {
         _possibleParenthesis(0, n, 0, 0, result);
     }
}