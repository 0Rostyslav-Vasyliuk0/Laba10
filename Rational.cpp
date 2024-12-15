#include "Rational.h"

// Конструктор
Rational::Rational(int num, int denom) : numerator(num), denominator(denom) {
    if (denominator == 0) {
        std::cout << "Помилка: знаменник не може бути нульовим!" << std::endl;
        denominator = 1; // Змінюємо знаменник на 1, щоб уникнути ділення на 0
    }
}

// Перевантаження оператора >
bool Rational::operator>(const Rational& other) const {
    return (double(numerator) / denominator) > (double(other.numerator) / other.denominator);
}

// Перевантаження оператора +
Rational Rational::operator+(const Rational& other) const {
    int new_numerator = numerator * other.denominator + other.numerator * denominator;
    int new_denominator = denominator * other.denominator;
    return Rational(new_numerator, new_denominator);
}

// Перевантаження оператора виведення <<
std::ostream& operator<<(std::ostream& os, const Rational& r) {
    os << r.numerator << "/" << r.denominator;
    return os;
}

// Статичний метод для обчислення середнього значення дробів
Rational Rational::calculateAverage(const std::vector<Rational>& fractions) {
    int total_numerator = 0;
    int total_denominator = 1;
    for (const auto& fraction : fractions) {
        total_numerator = total_numerator * fraction.denominator + fraction.numerator * total_denominator;
        total_denominator *= fraction.denominator;
    }
    return Rational(total_numerator, total_denominator);
}
