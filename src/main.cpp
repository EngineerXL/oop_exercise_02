#include "vector3d.hpp"

/*
 * Инютин М А М8О-207Б-19
 * Создать класс Vector3D, задаваемый тройкой координат.
 * Обязательно должны быть реализованы: операции сложения и
 * вычитания векторов, векторное произведение векторов,
 * скалярное произведение векторов, умножение на скаляр, сравнение
 * векторов на совпадение, вычисление длины вектора, сравнение
 * длин векторов, вычисление угла между векторами. Операции
 * сложения, вычитания, сравнений (на равенство, больше и меньше)
 * должны быть выполнены в виде перегрузки операторов.
 * Необходимо реализовать пользовательский литерал для работы
 * с константами типа Vector3D.
 */

signed main() {
	std::cout << "Ortonormal basis:" << "\n";
	std::cout << "i = " << "1,0,0"_vector3d << "\n";
	std::cout << "j = " << "0,1,0"_vector3d << "\n";
	std::cout << "k = " << "0,0,1"_vector3d << "\n";
	Vector3D a, b;
	std::cout << "Input three coordinates of first vector separated with \' \': ";
	std::cin >> a;
	std::cout << "Input three coordinates of second vector separated with \' \': ";
	std::cin >> b;
	if (a.IsNaN() or b.IsNaN()) {
		std::cout << "Invalid input! Programm terminates with exit code -1\n";
		return -1;
	}
	std::cout << "Your input:\n";
	std::cout << "a = " << a << "\n";
	std::cout << "b = " << b << "\n";
	std::cout << "Shortest vector: " << (a < b ? a : b) << "\n";
	std::cout << "Longest vector: " << (a > b ? a : b) << "\n";
	std::cout << "Dot product of your vectors: ";
	std::cout << Vector3D::DotProduct(a, b) << "\n";
	std::cout << "Angle between your vectors in radians: ";
	std::cout << Vector3D::Angle(a, b) << "\n";
	std::cout << "Cross product of your vectors: ";
	std::cout << Vector3D::CrossProduct(a, b) << "\n";
	return 0;
}