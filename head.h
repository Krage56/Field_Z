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
    //void operator+=(const long long);
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

    explicit operator long long() const;
    explicit operator int() const;
    friend std::ostream& operator<< (std::ostream& stream, Field_Z& ex) {
        stream << "Number: " << ex._data << ", base: " << ex._base;
        return stream;
    }


protected:
    bool equBase(const Field_Z&, const Field_Z&) const;
    bool equData(const Field_Z&, const Field_Z&) const;
    
    void normalize();

private:
    size_t _base;
    long long _data;
};