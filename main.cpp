#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;
void test();

int main() {
    string examples[] = {"5*20", "1+2", "6/2", "3-2"};

    srand(time(nullptr));
    int s = rand() % 3 + 1;
    cout << "Type an expression." << endl;
    cout << "i.e. " + examples[s] << endl;
    string expression;
    cin >> expression;
    cout << expression;
    return 0;
}

void test() {
    for (int i = 0; i < 3; ++i) {
        std::cout << i;
    }
}


