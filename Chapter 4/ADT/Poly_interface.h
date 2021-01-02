#pragma once

template <class Number>
class POLY_interface {
	public:
	POLY_interface<Number>(Number, int);
	const float eval(float);
	friend POLY_interface operator + (POLY_interface&, POLY_interface&);
	friend POLY_interface operator * (POLY_interface&, POLY_interface&);
};