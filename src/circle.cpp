// Copyright 2022 UNN-CS
#include "circle.h"

#include <stdexcept>
#include <cmath>

Circle::Circle(double radius) : radius_(0.0), ference_(0.0), area_(0.0) {
  setRadius(radius);
}

void Circle::setRadius(double radius) {
  validateValue(radius);
  radius_ = radius;
  ference_ = 2.0 * kPi * radius_;
  area_ = kPi * radius_ * radius_;
}

void Circle::setFerence(double ference) {
  validateValue(ference);
  ference_ = ference;
  radius_ = ference_ / (2.0 * kPi);
  area_ = kPi * radius_ * radius_;
}

void Circle::setArea(double area) {
  validateValue(area);
  area_ = area;
  radius_ = std::sqrt(area_ / kPi);
  ference_ = 2.0 * kPi * radius_;
}

double Circle::getRadius() const {
  return radius_;
}

double Circle::getFerence() const {
  return ference_;
}

double Circle::getArea() const {
  return area_;
}

void Circle::validateValue(double value) const {
  if (value < 0.0) {
    throw std::invalid_argument("Circle values must be non-negative");
  }
}
