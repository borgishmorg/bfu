#ifndef ___Quaternion___
#define ___Quaternion___

#include "Vector3.hpp"
#include <iostream>
#include <complex>

template <typename T> 
class Quaternion{
	private:
		T a;
		Vector3<T> v;
	public:
		Quaternion(T a, T b, T c, T d);
		Quaternion(T a, Vector3<T> const& v);
		Quaternion(std::complex<T> const& a, std::complex<T> const& b);
		
		T operator[] (int i) const;
		Quaternion<T> operator*(Quaternion const&) const;
		Vector3<T> getVector() const;
		
		T squareOfNorm() const;
		Quaternion<T> conjugate() const;
		Quaternion<T> reverse() const;
		
	static_assert(std::is_floating_point<T>::value, "Quaternion requires floating-point type!");
};

template <typename T> 
Quaternion<T>::Quaternion(T a, T b, T c, T d){
	this->a = a;
	this->v = Vector3<T>(b, c, d);
}

template <typename T> 
Quaternion<T>::Quaternion(T a, Vector3<T> const &v){
	this->a = a;
	this->v = v;
}

template <typename T> 
Quaternion<T>::Quaternion(std::complex<T> const& a, std::complex<T> const& b){
	this->a = a.real();
	this->v = Vector3<T>(a.imag(), b.real(), b.imag());
}

template <typename T> 
T Quaternion<T>::operator[](int i) const{
	if(i>= 2 && i<= 4) return v[i-1];
	return a;
}

template <typename T> 
Quaternion<T> Quaternion<T>::operator*(Quaternion const& b) const{
	return Quaternion<T>(this->a*b.a - Vector3<T>::scalarProduct(this->v, b.v), (b.v)*(this->a) + (this->v)*(b.a) + Vector3<T>::vectorProduct(this->v, b.v));
}

template <typename T> 
Vector3<T> Quaternion<T>::getVector() const{
	return v;
}

template <typename T> 
T Quaternion<T>::squareOfNorm() const{
	return a*a + v.squareOfNorm();
}

template <typename T> 
Quaternion<T> Quaternion<T>::conjugate() const{
	return Quaternion<T>(a, v*(-1));
}

template <typename T> 
Quaternion<T> Quaternion<T>::reverse() const{
	return Quaternion<T>(a/this->squareOfNorm(), v*(-1/this->squareOfNorm()));
}
#endif
