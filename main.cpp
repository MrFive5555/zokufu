#include <iostream>

using namespace std;

int main() {
	cout << "hello" << endl;
    [](int i) {cout << ++i << endl; }(10);
}
