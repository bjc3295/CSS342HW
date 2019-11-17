## Complete the parentheses project (20pt)

Use folder ```problem_1```.

In the class we have discussed the problem of outputing all valid parentheses of size N. The code we saw in class is [here](https://github.com/pdgetrf/UWB_CSS342_2019_Fall/tree/master/class7/possible_parentheses). That code is good for demo but it's not completed with proper tests. The task of this problem is to finish up the project. 

You could choose to follow the in-class demo code, or use your own implementation. **The only requirement is to use backtracking.**

As an extension info, this parentheses problem belongs to a category of math problem call [Catalan Number](https://en.wikipedia.org/wiki/Catalan_number)


### 1. (10pt) Rewrite the possibleParenthesis function with the following signature:

```c++
// n: size of the problem
// result: a list of string, each string represents a case of valid parentheses of size n
void possibleParenthesis(int n, std::list<std::string> & result)
```

*n* is the size of the problem and *result* is a list of strings where each string is a case of valid parentheses of size n.

For example
- when n = 1, *result* will consist of only 1 string: "{}"
- when n = 2, *result* will consist of 2 strings: '{}{}' and "{{}}"
- when n = 3, *result* will contain the following 5 strings:
"{}{}{}", 
"{}{{}}",
"{{}}{}",
"{{}{}}",
"{{{}}}"

Order of each string in the list does not matter.

### 2. (10pt) Write unit tests to verify your possibleParenthesis. You need to at least verify the cases of n being zero to three.
