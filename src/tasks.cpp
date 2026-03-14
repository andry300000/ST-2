// Copyright 2026 UNN-CS
#include "tasks.h"

#include "circle.h"

double getEarthRopeGap() {
  constexpr double kEarthRadiusMeters = 6378.1 * 1000.0;

  Circle earth(kEarthRadiusMeters);
  earth.setFerence(earth.getFerence() + 1.0);

  return earth.getRadius() - kEarthRadiusMeters;
}

PoolCosts getPoolCosts() {
  constexpr double kPoolRadius = 3.0;
  constexpr double kPathWidth = 1.0;
  constexpr double kConcretePrice = 1000.0;
  constexpr double kFencePrice = 2000.0;

  Circle pool(kPoolRadius);
  Circle outer_border(kPoolRadius + kPathWidth);

  return {
    (outer_border.getArea() - pool.getArea()) * kConcretePrice,
    outer_border.getFerence() * kFencePrice
  };
}
