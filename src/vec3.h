
#ifndef vec3_h__
#define vec3_h__

struct Vec3
{
    Vec3() 
        : Vec3(0,0,0) 
    { }
    

    Vec3(int x, int y, int z) 
        : x{ x } , y{ y } , z{ z } 
    { }


    Vec3(Vec3 const &o) 
        : x{ o.x }, y{ o.y }, z{ o.z } 
    { }



    bool operator==(Vec3 const &o)
    {
        return x == o.x && y == o.y && z == o.z;
    }


    Vec3& operator+=(Vec3 const &rhs)
    {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;

        return *this;
    }


    friend Vec3 operator+(Vec3 lhs, int rhs)
    {
        lhs += Vec3{ rhs, rhs, rhs };
        return lhs;
    }

    friend Vec3 operator+(Vec3 lhs, Vec3 const& rhs)
    {
        lhs += rhs;
        return lhs;
    }


    Vec3& operator-=(Vec3 const &rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;

        return *this;
    }


    friend Vec3 operator-(Vec3 lhs, Vec3 const& rhs)
    {
        lhs -= rhs;
        return lhs;
    }


    friend Vec3 operator-(Vec3 lhs, int rhs)
    {
        lhs -= Vec3{ rhs,rhs,rhs };
        return lhs;
    }


    int x;
    int y;
    int z;
};


struct Plane
{
    Plane()
        : Plane({ 0,0,0 }, { 0,0,0 })
    { }

    Plane(const Vec3 &vmin, const Vec3 &vmax)
        : m_min{vmin}, m_max{vmax}
    { }

    Plane(const Plane &o)
        : m_min{ o.m_min }, m_max{ o.m_max }
    { }

    bool operator==(const Plane &o)
    {
        return m_min == o.m_min && m_max == o.m_max;
    }

    const Vec3& min() const { return m_min; }
    void min(const Vec3 &m) { m_min = m; }

    const Vec3 & max() const { return m_max; }
    void max(const Vec3 &m) { m_max = m; }

private:
    Vec3 m_min;
    Vec3 m_max;
};

#endif // !vec3_h__
