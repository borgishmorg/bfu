#ifndef __Vector3__
#define __Vector3__

#include <iostream>

template <typename T> 
class Vector3{
	private:
		T x, y, z;
	public:
		Vector3();
		Vector3(T x, T y, T z);
		
		Vector3<T> operator+ (Vector3 const &b) const;
		Vector3<T> operator- (Vector3 const &b) const;
		T operator* (Vector3 const &b) const;
		Vector3<T> operator* (T b) const;
		T operator[] (int i) const;
		Vector3<T> operator+= (Vector3 const &b);
		Vector3<T> operator-= (Vector3 const &b);
		Vector3<T> operator*= (T b);
		
		T squareOfNorm() const;
		
		static T scalarProduct(Vector3 const &a, Vector3 const &b);
		static Vector3<T> vectorProduct(Vector3 const &a, Vector3 const &b);
		static T mixedProduct(Vector3 const & a, Vector3 const & b, Vector3 const & c);
		
	static_assert(std::is_floating_point<T>::value, "Vector3 requires floating-point type!");
};

template <typename T> 
Vector3<T>::Vector3(){
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

template <typename T> 
Vector3<T>::Vector3(T x, T y, T z){
	this->x = x;
	this->y = y;
	this->z = z;
}

template <typename T> 
T Vector3<T>::operator*(Vector3 const &b) const{
	return scalarProduct(*this, b);
}

template <typename T> 
Vector3<T> Vector3<T>::operator*(T b) const{
	return Vector3<T>(this->x*b, this->y*b, this->z*b);
}

template <typename T> 
Vector3<T> Vector3<T>::operator+(Vector3 const &b) const{
	return Vector3<T>(x + b.x, y + b.y, z + b.z);
}

template <typename T> 
Vector3<T> Vector3<T>::operator-(Vector3 const &b) const{
	return Vector3<T>(x - b.x, y - b.y, z - b.z);
}

template <typename T> 
T Vector3<T>::operator[](int i) const{
	if(i == 1) return x;
	if(i == 2) return y;
	return z;
}

template <typename T> 
Vector3<T> Vector3<T>::operator+=(Vector3 const &b){
	*this = *this + b;
	return *this;
}

template <typename T> 
Vector3<T> Vector3<T>::operator-=(Vector3 const &b){
	*this = *this - b;
	return *this;
}

template <typename T> 
Vector3<T> Vector3<T>::operator*=(T b){
	*this = (*this) * b;
	return *this;
}

template <typename T> 
T Vector3<T>::squareOfNorm() const{
	return x*x+y*y+z*z;
}

template <typename T> 
T Vector3<T>::scalarProduct(Vector3 const &a, Vector3 const &b){
		return a.x*b.x + a.y*b.y + a.z*b.z;
}

template <typename T> 
Vector3<T> Vector3<T>::vectorProduct(Vector3 const &a, Vector3 const &b){
	return Vector3<T>(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);
}

template <typename T> 
T Vector3<T>::mixedProduct(Vector3 const & a, Vector3 const & b, Vector3 const & c){
	return Vector3<T>::scalarProduct(a, (Vector3<T>::vectorProduct(b, c)));
}
#endif
