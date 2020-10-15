#include "vector3d.hpp"

Vector3D operator + (const Vector3D &lhs, const Vector3D &rhs) {
	return Vector3D(lhs.X + rhs.X, lhs.Y + rhs.Y, lhs.Z + rhs.Z);
}

Vector3D operator * (const long double &num, const Vector3D &vec) {
	return Vector3D(num * vec.X, num * vec.Y, num * vec.Z);
}

Vector3D operator - (const Vector3D &lhs, const Vector3D &rhs) {
	return lhs + (-1.0) * rhs;
}

std::ostream & operator << (std::ostream &out, const Vector3D &vec) {
	out << "(" << vec.X << ", "  << vec.Y << ", " << vec.Z << ")";
	return out;
}

std::istream & operator >> (std::istream &in,  Vector3D &vec) {
	in >> vec.X >> vec.Y >> vec.Z;
	return in;
}

bool operator == (Vector3D &lhs, Vector3D &rhs) {
	return std::abs(lhs.Length() - rhs.Length()) < EPS;
}

bool operator < (Vector3D &lhs, Vector3D &rhs) {
	return lhs.Length() < rhs.Length();
}

bool operator > (Vector3D &lhs, Vector3D &rhs) {
	return lhs.Length() > rhs.Length();
}

long double Vector3D::Length() {
	return std::sqrt(DotProduct(*this, *this));
}

bool Vector3D::IsNaN() {
	return std::isnan(this->X) or std::isnan(this->Y) or std::isnan(this->Z);
}

bool Vector3D::Equal(const Vector3D &lhs, const Vector3D &rhs) {
	return (std::abs(lhs.X - rhs.X) < EPS) && (std::abs(lhs.Y - rhs.Y) < EPS) && (std::abs(lhs.Z - rhs.Z) < EPS);
}

Vector3D Vector3D::CrossProduct(const Vector3D &lhs, const Vector3D &rhs) {
	return Vector3D(lhs.Y * rhs.Z - lhs.Z * rhs.Y, lhs.Z * rhs.X - lhs.X * rhs.Z, lhs.X * rhs.Y - lhs.Y * rhs.X);
}

long double Vector3D::DotProduct(const Vector3D &lhs, const Vector3D &rhs) {
	return lhs.X * rhs.X + lhs.Y * rhs.Y + lhs.Z * rhs.Z;
}

long double Vector3D::Angle(Vector3D &lhs, Vector3D &rhs) {
	long double res = std::acos(DotProduct(lhs, rhs) / (lhs.Length() * rhs.Length()));
	return std::isnan(res) ? 0 : res;
}

Vector3D operator"" _vector3d(const char *str, size_t n) {
	long double *cords = new long double[3];
	for (int i = 0; i < 3; ++i) {
		cords[i] = NAN;
	}
	std::string s(str);
	s = s + ',';
	size_t j = 0, last = 0;
	for (size_t i = 0; i < n + 1; ++i) {
		if (s[i] == ',' and j < 3) {
			try {
				cords[j] = std::stold(s.substr(last, i - last + 1));
			} catch (std::invalid_argument & ex) {
				;
			}
			last = i + 1;
			++j;
		}
	}
	return Vector3D(cords[0], cords[1], cords[2]);
}
