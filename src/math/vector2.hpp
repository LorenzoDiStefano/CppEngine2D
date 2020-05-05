#ifndef MATH_VECTOR2
#define MATH_VECTOR2

#include <cmath>
#include <array>

namespace my_math
{
    struct vector2
    {
        //constructors
        vector2();
        vector2(const vector2& other);
        vector2(float px, float py);

        ~vector2();

        //operators
        vector2 operator+(const vector2& other) const;
        vector2 operator-(const vector2& other) const;
        vector2 operator*(const vector2& other) const;
        vector2 operator*(const float other) const;

        vector2& operator+=(const vector2& other);
        vector2& operator-=(const vector2& other);
        vector2& operator*=(const vector2& other);
        vector2& operator=(const vector2& other);

        bool operator==(const vector2& other) const;
        bool operator!=(const vector2& other) const;
        float& operator[](const int index);

        friend std::ostream& operator<<(std::ostream& out, const vector2& point);

        //member functions
        void set(float x, float y);
        void normalize();

        //const member functions
        float length() const;
        float length_squared() const;
        std::array<float,2> to_float_array() const;
        vector2 lerp(const vector2& b, const float blend) const;
        vector2 normalized() const;

        //members
        float x;
        float y;

        //static suff
        static const vector2& one();
        static const vector2& zero();
        static const vector2& unit_x();
        static const vector2& unit_y();
    };
}

#endif