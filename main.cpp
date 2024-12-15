#include <iostream>
#include <vector>
#include <algorithm>
#include "Rational.h"

int main() {
    // Створення масиву дробів
    std::vector<Rational> fractions = {Rational(1, 2), Rational(2, 3), Rational(3, 4), Rational(4, 5)};

    // Сортування масиву за спаданням значень
    std::sort(fractions.begin(), fractions.end(), [](const Rational& a, const Rational& b) {
        return a > b;
    });

    // Виведення відсортованого масиву
    std::cout << "Дроби у спадному порядку:\n";
    for (const auto& fraction : fractions) {
        std::cout << fraction << std::endl;
    }

    // Обчислення середнього значення
    Rational average = Rational::calculateAverage(fractions);

    // Виведення середнього значення
    std::cout << "Середнє значення: " << average << std::endl;

    return 0;
}
