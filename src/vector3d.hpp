#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP

#include <bits/stdc++.h>

const long double EPS = 1e-6;

class Vector3D {
private:
	long double X, Y, Z;
	friend Vector3D operator + (const Vector3D &lhs, const Vector3D &rhs);
	friend Vector3D operator * (const long double &num, const Vector3D &vec);
	friend Vector3D operator - (const Vector3D &lhs, const Vector3D &rhs);
	friend std::ostream & operator << (std::ostream &out, const Vector3D &vec);
	friend std::istream & operator >> (std::istream &in,  Vector3D &vec);
	friend bool operator == (Vector3D &lhs, Vector3D &rhs);
	friend bool operator < (Vector3D &lhs, Vector3D &rhs);
	friend bool operator > (Vector3D &lhs, Vector3D &rhs);
public:
	Vector3D() : X(NAN), Y(NAN), Z(NAN) {};
	Vector3D(long double x, long double y, long double z) : X(x), Y(y), Z(z) {};
	~Vector3D() {};
	long double Length();
	bool IsNaN();
	static bool Equal(const Vector3D &lhs, const Vector3D &rhs);
	static Vector3D CrossProduct(const Vector3D &lhs, const Vector3D &rhs);
	static long double DotProduct(const Vector3D &lhs, const Vector3D &rhs);
	static long double Angle(Vector3D &lhs, Vector3D &rhs);
};

Vector3D operator"" _vector3d(const char *str, size_t n);

#endif // VECTOR3D_HPP
