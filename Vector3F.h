#pragma once
#include <iostream>
#include <cmath>

class Vector3F {
private:
    float x, y, z;
    int State;
    static int objectCount;

    static float length(const Vector3F& v);

public:
    // Конструктори
    Vector3F();
    Vector3F(float value);
    Vector3F(float X, float Y, float Z);
    Vector3F(const float* p);

    // Деструктор
    ~Vector3F();

    // Копіювання
    Vector3F(const Vector3F& other);
    Vector3F& operator=(const Vector3F& other);

    // Унарні
    Vector3F& operator++();
    Vector3F operator++(int);
    Vector3F& operator--();
    Vector3F operator--(int);
    bool operator!() const;
    Vector3F operator-() const;
    Vector3F operator~() const;

    // Присвоєння з операцією
    Vector3F& operator+=(const Vector3F& rhs);
    Vector3F& operator-=(const Vector3F& rhs);
    Vector3F& operator*=(float k);
    Vector3F& operator/=(float k);
    Vector3F& operator&=(const Vector3F& rhs);
    Vector3F& operator%=(int k);

    // Бінарні
    Vector3F operator+(const Vector3F& rhs) const;
    Vector3F operator-(const Vector3F& rhs) const;
    Vector3F operator*(float k) const;
    Vector3F operator/(float k) const;
    Vector3F operator%(int k) const;

    // Порівняння
    bool operator==(const Vector3F& rhs) const;
    bool operator!=(const Vector3F& rhs) const;
    bool operator>(const Vector3F& rhs) const;
    bool operator>=(const Vector3F& rhs) const;
    bool operator<(const Vector3F& rhs) const;
    bool operator<=(const Vector3F& rhs) const;

    // Індексатор
    float& operator[](int index);
    const float& operator[](int index) const;

    // Оператор виклику (довжина)
    float operator()() const;

    // new/delete
    static void* operator new(size_t size);
    static void operator delete(void* ptr);

    // Статичний лічильник
    static int getObjectCount();

    // Потоки
    friend std::ostream& operator<<(std::ostream& os, const Vector3F& v);
    friend std::istream& operator>>(std::istream& is, Vector3F& v);
};
