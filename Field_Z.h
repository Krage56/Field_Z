#pragma once
#include <iostream>


long long gcd(long long, long long, long long &, long long &);//solution of diophantine equation



class Field_Z{
public:
    Field_Z();
    Field_Z(const Field_Z&);

    Field_Z(const size_t, const long long);
    ~Field_Z();

    Field_Z& operator[](const size_t);
    Field_Z& operator=(const Field_Z&);
    Field_Z& operator=(const long long);
    Field_Z operator+(const Field_Z&)const;
    Field_Z operator+(const long long)const;
    Field_Z operator-(const Field_Z&)const;
    Field_Z operator-(const long long)const;
    Field_Z operator*(const Field_Z&)const;
    Field_Z operator*(const long long )const;
    Field_Z operator/(const Field_Z&) const;
    Field_Z operator/(const long long )const;
    bool operator==(const Field_Z&)const;
    bool operator>(const Field_Z&) const;
    bool operator>(const long long )const;
    bool operator<(const Field_Z&) const;
    bool operator<(const long long )const;
    void operator+=(const Field_Z&);
    void operator-=(const Field_Z&);
    void operator*=(const Field_Z&);
    void operator/=(const Field_Z&);
    void operator+=(const long long);
    void operator-=(const long long);
    void operator*=(const long long);
    void operator/=(const long long);

    explicit operator long long() const;
    explicit operator int() const;

    friend std::ostream& operator<< (std::ostream& stream, Field_Z& ex) {
        stream << "Number: " << ex._data << ", base: " << ex._base;
        return stream;
    }
    friend const Field_Z operator+(long long a, const Field_Z & obj){
        return obj + a;
    }
    friend const Field_Z operator*(long long a, const Field_Z & obj){
        return obj * a;
    }
    friend const Field_Z operator-(long long a, const Field_Z & obj){
        return Field_Z(obj._base, obj._data * (-1) + a);
    }
    friend const Field_Z operator/(long long a, const Field_Z & obj){
        return Field_Z(obj._base, a) / obj;
    }
    friend const Field_Z binpow(Field_Z & obj, long deg) {
        if (deg == 0)
            return Field_Z(obj._base,1);
        if (deg % 2 == 1)
            return binpow (obj, deg - 1) * obj;
        else {
            Field_Z b = binpow (obj, deg / 2);
            return b * b;
        }
    }

protected:
    bool equBase(const Field_Z&, const Field_Z&) const;
    bool equData(const Field_Z&, const Field_Z&) const;
    
    void normalize();

private:
    size_t _base;
    long long _data;
};
