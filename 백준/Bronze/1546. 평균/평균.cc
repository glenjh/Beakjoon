#include <iostream>

int main() {
    int n;
    int M = 0;
    double n_grade_avg;
    double n_grade_sum = 0;

    std::cin >> n;

    double* grade = new double[n];
    double* n_grade = new double[n];

    for (int i = 0; i < n; i++) {
        std::cin >> grade[i];
        if (M < grade[i]) {
            M = grade[i];
        }
    }
    for (int j = 0; j < n; j++) {
        n_grade[j] = grade[j] / M * 100;
    }

    for (int j = 0; j < n; j++) {
        n_grade_sum += n_grade[j];
        n_grade_avg = n_grade_sum / n;
    }
    std::cout << n_grade_avg;
    return 0;
}