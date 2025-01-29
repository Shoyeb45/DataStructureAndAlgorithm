#include<bits/stdc++.h>
using namespace std;


int num = 0;
void genParanthesis(string s, int n,  int openingBrackets = 0, int closingBrackets = 0) {
    if (s.size() == 2 * n) {
        cout << "Valid Paranthesis - " << ++num << "  : " << s << "\n";
        return;
    }

    if (openingBrackets == 0 && closingBrackets == 0) {
        genParanthesis(s + '(', n, openingBrackets + 1, closingBrackets);
    }
    else {
        if (openingBrackets + 1 <= n) {
            genParanthesis(s + '(', n,  openingBrackets + 1, closingBrackets);
        }
        if (closingBrackets + 1 <= openingBrackets) {
            genParanthesis(s + ')', n,  openingBrackets, closingBrackets + 1);
        }
    }
}

int main() {
    int n;
    cin >> n;
    genParanthesis("", n);
    return 0;
}