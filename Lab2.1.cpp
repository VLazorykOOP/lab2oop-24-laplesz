#include <iostream>
using namespace std;

int main() {
	int a, b, c, d;
	cout << "Input a, b, c and d: ";
	cin >> a >> b >> c >> d;
	int result = (((a << 4) + ((c << 8) + (c << 6) - (c << 3))) >> 5) - ((b << 7) - (b << 3)) + ((d << 7) - d);
	cout << "Result: " << result << endl;
	cout << "Result with normal operators: " << ((17 * a + 312 * c) / 32) - 120 * b + 127 * d;
	return 0;
}
