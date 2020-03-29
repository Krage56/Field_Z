//
// Created by krage56 on 28.03.2020.
//

#include "Field_Z.h"

Field_Z::Field_Z() {
    _base = 0;
    _data = 0;
}


Field_Z::Field_Z(const size_t newBase, const long long newData) {
    _base = newBase;
    _data = newData % (long long)newBase;
}
Field_Z::Field_Z(const Field_Z& newObj) {
    _base = newObj._base;
    _data = newObj._data;
}


Field_Z::~Field_Z() {
    _base = 0;
    _data = 0;
}



Field_Z& Field_Z::operator=(const Field_Z& newNum){
    if(this != &newNum){
        _base = newNum._base;
        _data = newNum._data;
    }
    return *this;
}

Field_Z& Field_Z::operator=(const long long num){
    Field_Z tmp;
    if(_base != 0){
        _data = num % (long long)_base;
    }
    else{
        Field_Z tmp(num > 0? num * 1: num *(-1) + 1, num);
        return tmp;
    }
    return *this;
}

Field_Z& Field_Z::operator[](const size_t base) {
    _base = base;
    _data = 0;
    return *this;
}

Field_Z Field_Z::operator+(const Field_Z& a) const {
    if(!(equBase(*this, a))){
        Field_Z error_obj(0, 0);
        return error_obj;
    }
    else{
        Field_Z tmp(_base, (a._data + _data) % (long long)_base);
        return tmp;
    }
}


Field_Z Field_Z::operator+(const long long a) const {
    Field_Z result(_base, (a % (long long)_base +
                           _data % (long long)_base) % (long long)_base);
    return result;
}

Field_Z Field_Z::operator*(const Field_Z & a) const {
    if(!(equBase(*this, a))){
        Field_Z error_obj(0, 0);

        return error_obj;
    }
    long tmp_data = (a._data * _data) % (long long)_base;
    Field_Z tmp(_base, tmp_data);
    return tmp;
}

Field_Z Field_Z::operator*(const long long a) const {
    Field_Z tmp(_base, (_data * (a %(long long) _base)) % (long long)_base);
    return tmp;
}

Field_Z::operator long long() const {
    return _data + _base;
}

Field_Z::operator int() const {
    return (long long)this;
}

Field_Z Field_Z::operator-(const Field_Z &a) const {
    if(a._base != _base){
        Field_Z error_obj(0, 0);
        return error_obj;
    }
    else{
        Field_Z tmp(_base, _data - a._data);
        return tmp;
    }
}

Field_Z Field_Z::operator-(const long long a) const {
    Field_Z result(_base, _data - a % (long long)_base );
    return result;
}

Field_Z Field_Z::operator/(const long long a) const {
    return *this / Field_Z(_base, a);
}

Field_Z Field_Z::operator/(const Field_Z & div) const {
    if(*this == div) return Field_Z(_base, 1);
    if(!equBase(*this, div)) return Field_Z(0, 0);
    long long oppose, param;
    Field_Z copy_div(div._base, div._data);
    if(copy_div < 0)copy_div.normalize();
    long long gcd_loc = gcd(copy_div._data, _base, oppose, param);
    //gcd_loc != 1 ? std::cout << "Bad" : std::cout << "Good";
    Field_Z op_el(_base, oppose);
    if(op_el < 0) op_el.normalize();
    return op_el * (*this);

}

bool Field_Z::equBase(const Field_Z& first, const Field_Z& second) const {
    return first._base == second._base;
}

bool Field_Z::equData(const Field_Z &first, const Field_Z &second) const {
    return first._data == second._data;
}

bool Field_Z::operator==(const Field_Z& second) const {
    if(equBase(*this, second) && equData(*this, second)){
        return true;
    }
    return false;
}

bool Field_Z::operator>(const Field_Z &second) const {
    if(equBase(*this, second))
        return _data > second._data;
    return false;
}

bool Field_Z::operator<(const long long a) const {
    Field_Z tmp(_base, a);
    return  *this < tmp;
}

bool Field_Z::operator<(const Field_Z &second) const {
    if(equBase(*this, second))
        return _data < second._data;
    return false;
}

bool Field_Z::operator>(const long long a) const {
    Field_Z tmp(_base, a);
    return  *this > tmp;
}

void Field_Z::normalize(){
    while(_data < 0)
        _data += _base;
}

void Field_Z::operator+=(const Field_Z &first) {
    if(equBase(*this, first)) {
        this->_data = (this->_data + first._data) %
                      (long long)_base;

    }
}

void Field_Z::operator-=(const Field_Z &first) {
    if(equBase(*this, first)) {
        this->_data = (this->_data - first._data) %
                      (long long) _base;
        this->normalize();
    }
}

void Field_Z::operator*=(const Field_Z &first) {
    if(equBase(*this, first)) {
        Field_Z tmp_obj;
        tmp_obj = *this * first;
        _data = tmp_obj._data;
    }
}

void Field_Z::operator/=(const Field_Z &first) {
    if(equBase(*this, first)) {
        Field_Z tmp_obj;
        tmp_obj = *this / first;
        _data = tmp_obj._data;
    }
}

void Field_Z::operator+=(const long long a) {
    Field_Z tmp_obj(_base, a);
    tmp_obj = *this + tmp_obj;
    _data = tmp_obj._data;
}

void Field_Z::operator-=(const long long a) {
    Field_Z tmp_obj(_base, a);
    tmp_obj = *this - tmp_obj;
    _data = tmp_obj._data;
    this->normalize();
}

void Field_Z::operator*=(const long long a) {
    Field_Z tmp_obj(_base, a);
    tmp_obj = *this * tmp_obj;
    _data = tmp_obj._data;
}

void Field_Z::operator/=(const long long a) {
    Field_Z tmp_obj(_base, a);
    tmp_obj = *this / tmp_obj;
    _data = tmp_obj._data;
}

long long gcd(long long a, long long b, long long &x, long long &y){
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    long long x1, y1;
    long long d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}