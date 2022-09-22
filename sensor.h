#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>
#include <vector>
#include "timestamp.h"



using namespace std;


class sensor {
private:
    int sensorNum;
    double mileMarker;
    timestamp time;
    


public:
    //constructors
    sensor();
    sensor(int, double, timestamp);

    //set/get for private data
    void setSensorNum(int);
    void setMileMarker(double);
    void setTime(timestamp);
    
    //Overloaded operators
    bool operator+=(const sensor&);
    sensor& operator=(const sensor&);
    friend bool operator>>(string&, sensor&);
    friend ostream& operator<<( ostream&, sensor&);
    
    //Functions
    bool testMPH(sensor&);
    int getTotalTime(const sensor&);
    
    //Friend classes
    friend class racer;
    friend class timestamp;

};



#endif