#pragma once
#include <iostream>
namespace my_math
{
    class vector3
    {

    public:

        vector3();
        vector3(float x, float y, float z, float w);
        ~vector3();

        vector3 operator+(const vector3& other) const;
        vector3 operator-(const vector3& other) const;
        vector3 operator*(const vector3& other) const;
        vector3 operator*(const float other) const;
        vector3& operator+=(const vector3& other);
        vector3& operator-=(const vector3& other);
        vector3& operator*=(const vector3& other);
        vector3& operator=(const vector3& other);
        bool operator==(const vector3& other) const;
        bool operator!=(const vector3& other) const;
        float& operator[](const int index);

        friend std::ostream& operator<< (std::ostream& out, const vector3& point);

        void set(float x, float y, float z, float w);
        void normalize();
        float* to_float_array()const;
        float length()const;
        float length_squared()const;
        vector3 lerp(const vector3& b, const float blend)const;
        vector3 normalized()const;

        float x;
        float y;
        float z;
        float w;

        static const vector3& unit_x();
        static const vector3& unit_y();
        static const vector3& unit_z();
        static const vector3& unit_w();
        static const vector3& zero();
        static const vector3& one();
    };
}