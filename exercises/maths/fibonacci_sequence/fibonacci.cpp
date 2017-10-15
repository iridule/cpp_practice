#include <iostream>;
using namespace std;

void printFib (int amt) {
    int i, a, b, n;
    for (i = 0; i < amt; i++) {
        n = a + b;
        a = b;
        b = n;
        cout << n;
    }
}

int main() {
    return 0;
}