#include "../src/math/vector2.hpp"

namespace my_math
{
    vector2::vector2(float x, float y) : x{ x }, y{ y } { }

    vector2::vector2() : x{ 0 }, y{ 0 } { };

    vector2::vector2(const vector2& other) : x{ other.x }, y{ other.y } { };

    vector2::~vector2() = default;

    //operators
    vector2 vector2::operator+(const vector2& other) const
    {
        vector2 vec2;

        vec2.x = x + other.x;
        vec2.y = y + other.y;

        return vec2;
    }

    vector2 vector2::operator-(const vector2& other) const
    {
        vector2 vec2;

        vec2.x = x - other.x;
        vec2.y = y - other.y;

        return vec2;
    }

    vector2 vector2::operator*(const vector2& other) const
    {
        vector2 vec2;

        vec2.x = x * other.x;
        vec2.y = y * other.y;

        return vec2;
    }

    vector2 vector2::operator*(const float other) const
    {
        vector2 vec2;

        vec2.x = x * other;
        vec2.y = y * other;

        return vec2;
    }

    vector2& vector2::operator+=(const vector2& other)
    {
        x += other.x;
        y += other.y;

        return *this;
    }

    vector2& vector2::operator-=(const vector2& other)
    {
        x -= other.x;
        y -= other.y;

        return *this;
    }

    vector2& vector2::operator*=(const vector2& other)
    {
        x *= other.x;
        y *= other.y;

        return *this;
    }

    vector2& vector2::operator=(const vector2& other)
    {
        x = other.x;
        y = other.y;

        return *this;
    }

    bool vector2::operator==(const vector2& other) const
    {
        return x == other.x && y == other.y;
    }

    bool vector2::operator!=(const vector2& other) const
    {
        return !(*this == other);
    }

    float& vector2::operator[](const int index)
    {
        switch (index)
        {
        case 0:
            return x;
            break;
        case 1:
            return y;
            break;
        default:
            throw "error index";
            break;
        }
    }

    std::ostream& operator<<(std::ostream& out, const vector2& vec)
    {
        out << " " << vec.x << " " << vec.y << " ";

        return out; // return std::ostream so we can chain calls to operator<<
    }

    //methods
    void vector2::set(float x, float y)
    {
        this->x = x;
        this->y = y;
    }

    void vector2::normalize()
    {
        float l = x * x + y * y;

        if (l != 0 && l != 1)
        {
            l = sqrt(l); //make this 1/sqrt, make below *
            x /= l;
            y /= l;
        }
    }

    vector2 vector2::normalized() const
    {
        vector2 vector2 = *this;
        vector2.normalize();
        return vector2;
    }

    float vector2::length() const
    {
        double len_squared = (x * x) + (y * y);

        if (len_squared == 0.0f)
            return 0.0f;

        float square = static_cast<float>(sqrt(len_squared));

        return square;
    }

    float vector2::length_squared() const
    {
        return (x * x) + (y * y);
    }

    vector2 vector2::lerp(const vector2& b, const float blend) const
    {
        vector2 res;

        res.x = ((blend * (b.x - x)) + x);
        res.y = ((blend * (b.y - y)) + y);

        return res;
    }

    //using Construct On First Use Idiom
    const vector2& vector2::unit_x()
    {
        static const vector2 unit_x{ 1.0f, 0.0f };
        return unit_x;
    }

    const vector2& vector2::unit_y()
    {
        static const vector2 unit_y{ 0.0f, 1.0f };
        return unit_y;                                  
    }                                                   
                                                    
    const vector2& vector2::zero()                      
    {                                                   
        static const vector2 zero{ 0.0f, 0.0f };
        return zero;                                    
    }                                                   
                                                    
    const vector2& vector2::one()                       
    {                                                   
        static const vector2 one{ 1.0f, 1.0f };
        return one;
    }

    std::array<float,2> vector2::to_float_array() const
    {
        std::array<float, 2> values;
        values[0] = this->x;
        values[1] = this->y;

        return values;
    }
}