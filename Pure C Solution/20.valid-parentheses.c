/*
 * @lc app=leetcode id=20 lang=c
 *
 * [20] Valid Parentheses
 */

// @lc code=start


bool isValid(char * s){
    char brackets[10000];
    int top = -1;
    while (*s) {
        if (*s == '(' || *s == '[' || *s == '{') {
            brackets[++top] = *s;
        } else {
            if (top < 0) {
                return false;
            } else {
                if (*s == ')' && brackets[top] != '(') return false; 
                if (*s == ']' && brackets[top] != '[') return false;
                if (*s == '}' && brackets[top] != '{') return false;
                top--;
            }
        } 
        s++;
    }
    return top == -1;
}
// @lc code=end

