#include <math/vector4.h>

namespace my_math
{
    vector4::vector4() : x{ 0 }, y{ 0 }, z{ 0 }, w{ 0 } { }

    vector4::vector4(float x, float y, float z, float w) : x{ x }, y{ y }, z{ z }, w{ w } { }

    vector4::~vector4() { }

    //vec4 operators
    vector4 vector4::operator+(const vector4& other) const
    {
        vector4 vec2;

        vec2.x = x + other.x;
        vec2.y = y + other.y;
        vec2.z = z + other.z;
        vec2.w = w + other.w;

        return vec2;
    }

    vector4 vector4::operator-(const vector4& other) const
    {
        vector4 vec2;

        vec2.x = x - other.x;
        vec2.y = y - other.y;
        vec2.z = z - other.z;
        vec2.w = w - other.w;

        return vec2;
    }

    vector4 vector4::operator*(const vector4& other) const
    {
        vector4 vec2;

        vec2.x = x * other.x;
        vec2.y = y * other.y;
        vec2.z = z * other.z;
        vec2.w = w * other.w;

        return vec2;
    }

    vector4 vector4::operator*(const float other) const
    {
        vector4 vec2;

        vec2.x = x * other;
        vec2.y = y * other;
        vec2.z = z * other;
        vec2.w = w * other;

        return vec2;
    }

    vector4& vector4::operator+=(const vector4& other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
        w += other.w;

        return *this;
    }

    vector4& vector4::operator-=(const vector4& other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        w -= other.w;

        return *this;
    }

    vector4& vector4::operator*=(const vector4& other)
    {
        x *= other.x;
        y *= other.y;
        z *= other.z;
        w *= other.w;

        return *this;
    }

    vector4& vector4::operator=(const vector4& other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
        w = other.w;

        return *this;
    }

    bool vector4::operator==(const vector4& other) const
    {
        return x == other.x && y == other.y && z == other.z && w == other.z;
    }

    bool vector4::operator!=(const vector4& other) const
    {
        return !(*this == other);
    }

    float& vector4::operator[](const int index)
    {
        switch (index)
        {
        case 0:
            return x;
            break;
        case 1:
            return this->y;
            break;
        case 2:
            return this->z;
            break;
        case 3:
            return this->w;
            break;
        default:
            throw "error index";
            break;
        }
    }

    std::ostream& operator<<(std::ostream& out, const vector4& vec)
    {
        out << " " << vec.x << " " << vec.y << " " << vec.z << " " << vec.w;

        return out; // return std::ostream so we can chain calls to operator<<
    }

    //vec4 methods
    void vector4::set(float x, float y, float z, float w)
    {
        x = x;
        y = y;
        z = z;
        w = w;
    }

    void vector4::normalize()
    {
        float l = x * x + y * y + z * z + w * w;

        if (l != 0 && l != 1)
        {
            l = sqrt(l); //make this 1/sqrt, make below *
            x /= l;
            y /= l;
            z /= 1;
        }
    }

    vector4 vector4::normalized() const
    {
        vector4 vector4 = *this;
        vector4.normalize();
        return vector4;
    }

    float vector4::length() const
    {
        double len_squared = ((double)x * x) + ((double)y * y) + ((double)z * z) + ((double)w * w);

        if (len_squared == 0.0f)
            return 0.0f;

        float square = (float)(sqrt(len_squared));

        return square;
    }

    float vector4::length_squared() const
    {
        return (x * x) + (y * y) + (z * z) + (w * w);
    }

    vector4 lerp(vector4& a, vector4& b, const float blend)
    {
        vector4 res;

        res.x = ((blend * (b.x - a.x)) + a.x);
        res.y = ((blend * (b.y - a.y)) + a.y);
        res.z = ((blend * (b.z - a.z)) + a.z);
        res.w = ((blend * (b.w - a.w)) + a.w);

        return res;
    }

    //using Construct On First Use Idiom
    const vector4& vector4::unit_x()
    {
        static const vector4 unit_x = vector4(1.0f, 0.0f, 0.0f, 0.0f);
        return unit_x;
    }

    const vector4& vector4::unit_y()
    {
        static const vector4 unit_y = vector4(0.0f, 1.0f, 0.0f, 0.0f);
        return unit_y;
    }

    const vector4& vector4::unit_z()
    {
        static const vector4 unit_z = vector4(0.0f, 0.0f, 1.0f, 0.0f);
        return unit_z;
    }

    const vector4& vector4::unit_w()
    {
        static const vector4 unit_w = vector4(0.0f, 0.0f, 0.0f, 1.0f);
        return unit_w;
    }

    const vector4& vector4::zero()
    {
        static const vector4 zero = vector4(0.0f, 0.0f, 0.0f, 0.0f);
        return zero;
    }

    const vector4& vector4::one()
    {
        static const vector4 one = vector4(1.0f, 1.0f, 1.0f, 1.0f);
        return one;
    }

    //return a pointer to an array of float on the heap
    float* vector4::to_float_array() const
    {
        float* values = new float[4];
        values[0] = this->x;
        values[1] = this->y;
        values[2] = this->z;
        values[3] = this->w;

        return values;
    }
}