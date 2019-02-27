#include <iostream>
#include <complex>
#include "Vector3.hpp"
#include "Quaternion.hpp"


using std::cin;
using std::endl;
using std::cout;

template <typename T> std::ostream& operator<< (std::ostream& out, Vector3<T> const &b){
	out << "(" << b[1] << "," << b[2] << "," << b[3] <<")";
	return out;
}
template <typename T> std::ostream& operator<< (std::ostream& out, Quaternion<T> const &b){
	out << "(" << b[1] << "," << b[2] << "," << b[3] << "," << b[4] <<")";
	return out;
}

template <typename T> Vector3<T> rotationOfVectorOnQuaternion(Vector3<T> const& v, Quaternion<T> const& q){
	Quaternion<T> t = q*Quaternion<T>(0, v);
	t = t*q.reverse();
	return t.getVector();
}

int main(int argc, char* argv[]){
	Vector3<double> a(2, 3, 5);
	Quaternion<double> q1(std::complex<double>(10, -5), std::complex<double>(7, -3)), 
					q2(1, 2, 3, 4), 
					q3(-5, a);
	
	cout << q1 << " " << q2 << " " << q3 << " " << q2*q3 << " " << (q2*q3).conjugate() << endl;

	
	Vector3<float> v(0, 0, 1);
	Quaternion<float> q(0, 1, 0, 1);
	
	cout << rotationOfVectorOnQuaternion(v, q);
	
	return 0;
}
