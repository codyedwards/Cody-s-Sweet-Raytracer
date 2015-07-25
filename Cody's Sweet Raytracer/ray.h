#ifndef RAY_H
#define RAY_H

#include "vector2.h"
#include "vector3.h"
#include "Shape.h"

class ray
{
public:
	enum RayType 
	{
		VISIBILITY,
		REFLECTION,
		REFRACTION,
		SHADOW
	};

	ray(const vector3d& d, const vector3d& p, RayType t = VISIBILITY)
		:direction(d), position(p), type(t) {}

	ray(const ray& r)
		:direction(r.direction), position(r.position), type(r.type) {}

	~ray() {}

	ray& operator=(const ray& r)
	{
		position = r.position;
		direction = r.direction;
		type = r.type;
		return *this;
	}

	vector3d line(double time) const
	{
		return position + (time * direction);
	}

	vector3d getDirection() const
	{
		return direction;
	}

	vector3d getPosition() const
	{
		return position;
	}

	RayType getType() const
	{
		return type;
	}

private:
	RayType type;
	vector3d direction;
	vector3d position;
};

class intersection
{
public:
	intersection()
		:shape(nullptr), time(0.0), normal(), uv() {}

	~intersection() {}

	void setShape(const Shape *s)
	{
		shape = s;
	}

	void setTime(double t)
	{
		time = t;
	}

	void setNormal(const vector3d& n)
	{
		normal = n;
	}

	void setUV(const vector2d& u)
	{
		uv = u;
	}

	Shape getShape()
	{
		return *shape;
	}

	double getTime()
	{
		return time;
	}

	vector3d* getNormal()
	{
		return &normal;
	}

	vector2d* getUV()
	{
		return &uv;
	}

private:
	const Shape *shape;
	double time;
	vector3d normal;
	vector2d uv;
};

const double RAY_EPSILON = 0.00001;
const double NORMAL_EPSILON = 0.00001;

#endif RAY_H