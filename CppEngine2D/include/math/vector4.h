#include <iostream>

namespace my_math
{
    class vector4
    {
    public:
        vector4();
        vector4(float x, float y, float z, float w);
        ~vector4();

        vector4 operator+(const vector4& other) const;
        vector4 operator-(const vector4& other) const;
        vector4 operator*(const vector4& other) const;
        vector4 operator*(const float other) const;
        vector4& operator+=(const vector4& other);
        vector4& operator-=(const vector4& other);
        vector4& operator*=(const vector4& other);
        vector4& operator=(const vector4& other);
        bool operator==(const vector4& other) const;
        bool operator!=(const vector4& other) const;
        float& operator[](const int index);

        friend std::ostream& operator<< (std::ostream& out, const vector4& point);

        void set(float x, float y, float z, float w);
        void normalize();
        float* to_float_array()const;
        float length()const;
        float length_squared()const;
        vector4 lerp(const vector4& b, const float blend)const;
        vector4 normalized()const;

        float x;
        float y;
        float z;
        float w;

        static const vector4& unit_x();
        static const vector4& unit_y();
        static const vector4& unit_z();
        static const vector4& unit_w();
        static const vector4& zero();
        static const vector4& one();
    };
}