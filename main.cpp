#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <map>
#include <functional>
#include <regex>

using namespace std;

int main() {
    while (true) {
        vector<string> examples = {"5*2", "1+2", "6/2", "3-2"};
        vector<string> signs = {"*", "+", "-", "/"};

        srand(time(nullptr));
        int ie = rand() % 3 + 1;

        cout << "Type an expression (" << "i.e. " + examples[ie] << ")" << endl;

        string expression;
        getline(cin, expression);
        // remove whitespaces
        expression.erase(std::remove_if(expression.begin(), expression.end(), ::isspace), expression.end());

        string delim;

        for (auto &sign : signs) {
            if (expression.find(sign) != std::string::npos) {
                delim = sign;
            }
        }

        auto start = 0U;
        auto end = expression.find(delim);
        double val1;
        double val2;

        while (end != string::npos) {
            val1 = stoi(expression.substr(start, end - start));
            start = end + delim.length();
            end = expression.find(delim, start);
        }

        val2 = stoi(expression.substr(start, end));

        double answer;
        if (delim == "+") {
            answer = val1 + val2;
        } else if (delim == "-") {
            answer = val1 - val2;
        } else if (delim == "*") {
            answer = val1 * val2;
        } else if (delim == "/") {
            answer = val1 / val2;
        } else {
            cout << "The answer could not be determined!" << endl;
            return 0;
        }

        cout << "Answer: " << answer << endl << endl;
    }
    return 0;
}

