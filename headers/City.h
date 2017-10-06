#ifndef CITY_H
#define CITY_H

#include <iostream>
#include <iomanip>

using std::ostream;
using std::endl;
using std::setfill;
using std::setw;

class City{

    friend ostream& operator<<(ostream&,const City&);

public:
    City();
    City(const double,const double);
    double getX() const;
    double getY() const;
    void setX(const double);
    void setY(const double);

    //overload do operador de comparação
    bool operator==(const City &) const;
    const City& operator=(const City &);
private:
    double x;
    double y;
};

#endif