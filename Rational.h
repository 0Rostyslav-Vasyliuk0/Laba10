#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <vector>

class Rational {
private:
    int numerator;   // Чисельник
    int denominator; // Знаменник

public:
    // Конструктор
    Rational(int num = 0, int denom = 1);

    // Перевантаження оператора >
    bool operator>(const Rational& other) const;

    // Перевантаження оператора +
    Rational operator+(const Rational& other) const;

    // Перевантаження оператора виведення <<
    friend std::ostream& operator<<(std::ostream& os, const Rational& r);

    // Статичний метод для обчислення середнього значення дробів
    static Rational calculateAverage(const std::vector<Rational>& fractions);

    // Деструктор
    ~Rational() {}
};

#endif
