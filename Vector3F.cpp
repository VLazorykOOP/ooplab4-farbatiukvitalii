#include "Vector3F.h"

int Vector3F::objectCount = 0;

float Vector3F::length(const Vector3F& v) {
    return std::sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}

Vector3F::Vector3F() : x(0), y(0), z(0), State(0) {
    objectCount++;
}

Vector3F::Vector3F(float value) : x(value), y(value), z(value), State(0) {
    objectCount++;
}

Vector3F::Vector3F(float X, float Y, float Z)
    : x(X), y(Y), z(Z), State(0) {
    objectCount++;
}

Vector3F::Vector3F(const float* p) {
    if (p == nullptr) {
        x = y = z = 0;
        State = -1;
    } else {
        x = p[0]; y = p[1]; z = p[2];
        State = 0;
    }
    objectCount++;
}

Vector3F::~Vector3F() {
    objectCount--;
}

Vector3F::Vector3F(const Vector3F& other)
    : x(other.x), y(other.y), z(other.z), State(other.State) {
    objectCount++;
}

Vector3F& Vector3F::operator=(const Vector3F& other) {
    if (this != &other) {
        x = other.x; y = other.y; z = other.z;
        State = other.State;
    }
    return *this;
}

// Унарні
Vector3F& Vector3F::operator++() {
    x++; y++; z++;
    return *this;
}

Vector3F Vector3F::operator++(int) {
    Vector3F temp = *this;
    ++(*this);
    return temp;
}

Vector3F& Vector3F::operator--() {
    x--; y--; z--;
    return *this;
}

Vector3F Vector3F::operator--(int) {
    Vector3F temp = *this;
    --(*this);
    return temp;
}

bool Vector3F::operator!() const {
    return !(x != 0 && y != 0 && z != 0);
}

Vector3F Vector3F::operator-() const {
    return Vector3F(-x, -y, -z);
}

Vector3F Vector3F::operator~() const {
    return Vector3F(-y, x, z);
}

// Присвоєння з операцією
Vector3F& Vector3F::operator+=(const Vector3F& rhs) {
    x += rhs.x; y += rhs.y; z += rhs.z;
    return *this;
}

Vector3F& Vector3F::operator-=(const Vector3F& rhs) {
    x -= rhs.x; y -= rhs.y; z -= rhs.z;
    return *this;
}

Vector3F& Vector3F::operator*=(float k) {
    x *= k; y *= k; z *= k;
    return *this;
}

Vector3F& Vector3F::operator/=(float k) {
    if (k != 0) {
        x /= k; y /= k; z /= k;
    } else {
        State = -2;
    }
    return *this;
}

Vector3F& Vector3F::operator&=(const Vector3F& rhs) {
    float nx = y*rhs.z - z*rhs.y;
    float ny = z*rhs.x - x*rhs.z;
    float nz = x*rhs.y - y*rhs.x;
    x = nx; y = ny; z = nz;
    return *this;
}

Vector3F& Vector3F::operator%=(int k) {
    if (k != 0) {
        x = (int)x % k;
        y = (int)y % k;
        z = (int)z % k;
    } else State = -3;
    return *this;
}

// Бінарні
Vector3F Vector3F::operator+(const Vector3F& rhs) const { Vector3F t=*this; t+=rhs; return t; }
Vector3F Vector3F::operator-(const Vector3F& rhs) const { Vector3F t=*this; t-=rhs; return t; }
Vector3F Vector3F::operator*(float k) const { Vector3F t=*this; t*=k; return t; }
Vector3F Vector3F::operator/(float k) const { Vector3F t=*this; t/=k; return t; }
Vector3F Vector3F::operator%(int k) const { Vector3F t=*this; t%=k; return t; }

// Порівняння
bool Vector3F::operator==(const Vector3F& rhs) const { return x==rhs.x && y==rhs.y && z==rhs.z; }
bool Vector3F::operator!=(const Vector3F& rhs) const { return !(*this==rhs); }
bool Vector3F::operator>(const Vector3F& rhs) const { return length(*this)>length(rhs); }
bool Vector3F::operator>=(const Vector3F& rhs) const { return length(*this)>=length(rhs); }
bool Vector3F::operator<(const Vector3F& rhs) const { return length(*this)<length(rhs); }
bool Vector3F::operator<=(const Vector3F& rhs) const { return length(*this)<=length(rhs); }

// Індексатор
float& Vector3F::operator[](int index) {
    switch (index) {
        case 0: return x;
        case 1: return y;
        case 2: return z;
        default: State=1; return z;
    }
}

const float& Vector3F::operator[](int index) const {
    switch (index) {
        case 0: return x;
        case 1: return y;
        case 2: return z;
        default: return z;
    }
}

float Vector3F::operator()() const {
    return length(*this);
}

void* Vector3F::operator new(size_t size) {
    return ::operator new(size);
}

void Vector3F::operator delete(void* ptr) {
    ::operator delete(ptr);
}

int Vector3F::getObjectCount() {
    return objectCount;
}

std::ostream& operator<<(std::ostream& os, const Vector3F& v) {
    os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Vector3F& v) {
    is >> v.x >> v.y >> v.z;
    return is;
}
