#include <math/vector3.h>

namespace my_math
{
    vector3::vector3() : x{ 0 }, y{ 0 }, z{ 0 }, w{ 0 } { }

    vector3::vector3(float x, float y, float z, float w) : x{ x }, y{ y }, z{ z }, w{ w } { }

    vector3::~vector3() { }

    vector3 vector3::operator+(const vector3& other) const
    {
        vector3 vec2;

        vec2.x = x + other.x;
        vec2.y = y + other.y;
        vec2.z = z + other.z;
        vec2.w = w + other.w;

        return vec2;
    }

    vector3 vector3::operator-(const vector3& other) const
    {
        vector3 vec2;

        vec2.x = x - other.x;
        vec2.y = y - other.y;
        vec2.z = z - other.z;
        vec2.w = w - other.w;

        return vec2;
    }

    vector3 vector3::operator*(const vector3& other) const
    {
        vector3 vec2;

        vec2.x = x * other.x;
        vec2.y = y * other.y;
        vec2.z = z * other.z;
        vec2.w = w * other.w;

        return vec2;
    }

    vector3 vector3::operator*(const float other) const
    {
        vector3 vec2;

        vec2.x = x * other;
        vec2.y = y * other;
        vec2.z = z * other;
        vec2.w = w * other;

        return vec2;
    }

    vector3& vector3::operator+=(const vector3& other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
        w += other.w;

        return *this;
    }

    vector3& vector3::operator-=(const vector3& other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        w -= other.w;

        return *this;
    }

    vector3& vector3::operator*=(const vector3& other)
    {
        x *= other.x;
        y *= other.y;
        z *= other.z;
        w *= other.w;

        return *this;
    }

    vector3& vector3::operator=(const vector3& other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
        w = other.w;

        return *this;
    }

    bool vector3::operator==(const vector3& other) const
    {
        return x == other.x && y == other.y && z == other.z && w == other.z;
    }

    bool vector3::operator!=(const vector3& other) const
    {
        return !(*this == other);
    }

    float& vector3::operator[](const int index)
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

    std::ostream& operator<<(std::ostream& out, const vector3& vec)
    {
        out << " " << vec.x << " " << vec.y << " " << vec.z << " " << vec.w;

        return out; // return std::ostream so we can chain calls to operator<<
    }

    //vec4 methods
    void vector3::set(float x, float y, float z, float w)
    {
        x = x;
        y = y;
        z = z;
        w = w;
    }

    void vector3::normalize()
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

    vector3 vector3::normalized() const
    {
        vector3 vector3 = *this;
        vector3.normalize();
        return vector3;
    }

    float vector3::length() const
    {
        double len_squared = ((double)x * x) + ((double)y * y) + ((double)z * z) + ((double)w * w);

        if (len_squared == 0.0f)
            return 0.0f;

        float square = (float)(sqrt(len_squared));

        return square;
    }

    float vector3::length_squared() const
    {
        return (x * x) + (y * y) + (z * z) + (w * w);
    }

    vector3 lerp(vector3& a, vector3& b, const float blend)
    {
        vector3 res;

        res.x = ((blend * (b.x - a.x)) + a.x);
        res.y = ((blend * (b.y - a.y)) + a.y);
        res.z = ((blend * (b.z - a.z)) + a.z);
        res.w = ((blend * (b.w - a.w)) + a.w);

        return res;
    }

    //using Construct On First Use Idiom
    const vector3& vector3::unit_x()
    {
        static const vector3 unit_x = vector3(1.0f, 0.0f, 0.0f, 0.0f);
        return unit_x;
    }

    const vector3& vector3::unit_y()
    {
        static const vector3 unit_y = vector3(0.0f, 1.0f, 0.0f, 0.0f);
        return unit_y;
    }

    const vector3& vector3::unit_z()
    {
        static const vector3 unit_z = vector3(0.0f, 0.0f, 1.0f, 0.0f);
        return unit_z;
    }

    const vector3& vector3::unit_w()
    {
        static const vector3 unit_w = vector3(0.0f, 0.0f, 0.0f, 1.0f);
        return unit_w;
    }

    const vector3& vector3::zero()
    {
        static const vector3 zero = vector3(0.0f, 0.0f, 0.0f, 0.0f);
        return zero;
    }

    const vector3& vector3::one()
    {
        static const vector3 one = vector3(1.0f, 1.0f, 1.0f, 1.0f);
        return one;
    }

    //return a pointer to an array of float on the heap
    float* vector3::to_float_array() const
    {
        float* values = new float[4];
        values[0] = this->x;
        values[1] = this->y;
        values[2] = this->z;
        values[3] = this->w;

        return values;
    }
}