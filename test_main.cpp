#include <iostream>
#include "src.hpp"

using namespace std;

void testCallback(int argc, char** argv) {
    cout << "argc: " << argc << endl;
    for (int i = 0; i < argc; i++) {
        cout << "argv[" << i << "]: " << argv[i] << endl;
    }
}

int main() {
    // Test case 1: Basic command
    cout << "Test 1: Basic command" << endl;
    final::shell sh;
    sh.run(1, "ls -al /usr/bin", testCallback);
    sh.subprocessExit(1, 0);
    cout << endl;

    // Test case 2: Single argument
    cout << "Test 2: Single argument" << endl;
    sh.run(2, "pwd", testCallback);
    sh.subprocessExit(2, 0);
    cout << endl;

    // Test case 3: Multiple spaces
    cout << "Test 3: Multiple spaces" << endl;
    sh.run(3, "echo  hello  world", testCallback);
    sh.subprocessExit(3, 0);
    cout << endl;

    // Test case 4: Empty string
    cout << "Test 4: Empty string" << endl;
    sh.run(4, "", testCallback);
    sh.subprocessExit(4, 0);
    cout << endl;

    // Test case 5: Complex command
    cout << "Test 5: Complex command" << endl;
    sh.run(5, "gcc -o output main.cpp -std=c++11", testCallback);
    sh.subprocessExit(5, 0);
    cout << endl;

    return 0;
}
