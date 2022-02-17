// Hao Wu, Perm: 9883406 
// This is the only file to submit.

#include "car.hpp"
#include <cstddef>
#include <cstring>
#include <iostream>
using namespace std;

Car::Car(): manufacturer(NULL), model(NULL), 
zeroToSixtyNs(0), headonDragCoeff(0), horsepower(0), 
backseatDoors(None), seatCount(0) {
}

Car::Car(char const* const manufacturerName, 
char const* const modelName, PerformanceStats perf, 
uint8_t numSeats, DoorKind backseatDoorDesign): 
manufacturer(strdup(manufacturerName)), model(strdup(modelName)), 
zeroToSixtyNs(perf.zeroToSixtyNs), headonDragCoeff(perf.headonDragCoeff), 
horsepower(perf.horsepower), backseatDoors(backseatDoorDesign), 
seatCount(numSeats) {
}

Car::Car(Car const& o) {
  manufacturer = strdup(o.manufacturer);
  model = strdup(o.model);
  zeroToSixtyNs = o.zeroToSixtyNs;
  headonDragCoeff = o.headonDragCoeff;
  horsepower = o.horsepower;
  backseatDoors = o.backseatDoors;
  seatCount = o.seatCount;
}

Car::~Car() {
  if(manufacturer != NULL){
    free(manufacturer);
  }
  if(model != NULL){
    free(model);
  }
}

char const* Car::getManufacturer() const {
  return manufacturer;
}

char const* Car::getModel() const {
  return model;
}

PerformanceStats Car::getStats() const {
  PerformanceStats perf = PerformanceStats(horsepower, zeroToSixtyNs, headonDragCoeff);
  return perf;
}

uint8_t Car::getSeatCount() const {
  return seatCount;
}

DoorKind Car::getBackseatDoors() const {
  return backseatDoors;
}

void Car::manufacturerChange(char const* const newManufacturer) {
  manufacturer = strdup(newManufacturer);
}

void Car::modelNameChange(char const* const newModelName) {
  model = strdup(newModelName);
}

void Car::reevaluateStats(PerformanceStats newStats) {
  zeroToSixtyNs = newStats.zeroToSixtyNs;
  headonDragCoeff = newStats.headonDragCoeff;
  horsepower = newStats.horsepower;
}

void Car::recountSeats(uint8_t newSeatCount) {
  seatCount = newSeatCount;
}

void Car::reexamineDoors(DoorKind newDoorKind) {
  backseatDoors = newDoorKind;
}

Car& Car::operator=(Car const& o) {
  cout << "Called overladed =";
  manufacturer = strdup(o.manufacturer);
  model = strdup(o.model);
  zeroToSixtyNs = o.zeroToSixtyNs;
  headonDragCoeff = o.headonDragCoeff;
  horsepower = o.horsepower;
  backseatDoors = o.backseatDoors;
  seatCount = o.seatCount;
  return *this;
}

