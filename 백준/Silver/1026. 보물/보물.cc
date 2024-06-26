#include <iostream>
# include <algorithm>

bool desc(int a, int b) {
    return a > b;
}

int main() {
    int n;
    std::cin >> n;
    int sum = 0;

    int* a = new int[n];
    int* b = new int[n];

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::sort(a, a + n);

    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    std::sort(b, b + n, desc);


    for (int i = 0; i < n; i++) {
        sum += a[i] * b[i];
    }
    std::cout << sum;
    return 0;
}