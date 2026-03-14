// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>

#include <stdexcept>

#include "circle.h"
#include "tasks.h"

namespace {
constexpr double kPi = 3.14159265358979323846;
constexpr double kEps = 1e-7;
}  // namespace

TEST(CircleTest, ConstructorStoresRadius) {
  Circle circle(3.5);

  EXPECT_DOUBLE_EQ(3.5, circle.getRadius());
}

TEST(CircleTest, ConstructorCalculatesFerence) {
  Circle circle(2.0);

  EXPECT_NEAR(4.0 * kPi, circle.getFerence(), kEps);
}

TEST(CircleTest, ConstructorCalculatesArea) {
  Circle circle(2.0);

  EXPECT_NEAR(4.0 * kPi, circle.getArea(), kEps);
}

TEST(CircleTest, SetRadiusChangesRadius) {
  Circle circle(1.0);

  circle.setRadius(5.0);

  EXPECT_DOUBLE_EQ(5.0, circle.getRadius());
}

TEST(CircleTest, SetRadiusRecalculatesFerence) {
  Circle circle(1.0);

  circle.setRadius(5.0);

  EXPECT_NEAR(10.0 * kPi, circle.getFerence(), kEps);
}

TEST(CircleTest, SetRadiusRecalculatesArea) {
  Circle circle(1.0);

  circle.setRadius(5.0);

  EXPECT_NEAR(25.0 * kPi, circle.getArea(), kEps);
}

TEST(CircleTest, SetFerenceChangesFerence) {
  Circle circle(1.0);

  circle.setFerence(12.0);

  EXPECT_DOUBLE_EQ(12.0, circle.getFerence());
}

TEST(CircleTest, SetFerenceRecalculatesRadius) {
  Circle circle(1.0);

  circle.setFerence(4.0 * kPi);

  EXPECT_NEAR(2.0, circle.getRadius(), kEps);
}

TEST(CircleTest, SetFerenceRecalculatesArea) {
  Circle circle(1.0);

  circle.setFerence(4.0 * kPi);

  EXPECT_NEAR(4.0 * kPi, circle.getArea(), kEps);
}

TEST(CircleTest, SetAreaChangesArea) {
  Circle circle(1.0);

  circle.setArea(9.0 * kPi);

  EXPECT_NEAR(9.0 * kPi, circle.getArea(), kEps);
}

TEST(CircleTest, SetAreaRecalculatesRadius) {
  Circle circle(1.0);

  circle.setArea(9.0 * kPi);

  EXPECT_NEAR(3.0, circle.getRadius(), kEps);
}

TEST(CircleTest, SetAreaRecalculatesFerence) {
  Circle circle(1.0);

  circle.setArea(9.0 * kPi);

  EXPECT_NEAR(6.0 * kPi, circle.getFerence(), kEps);
}

TEST(CircleTest, ZeroRadiusCreatesZeroFerenceAndArea) {
  Circle circle(4.0);

  circle.setRadius(0.0);

  EXPECT_DOUBLE_EQ(0.0, circle.getRadius());
  EXPECT_DOUBLE_EQ(0.0, circle.getFerence());
  EXPECT_DOUBLE_EQ(0.0, circle.getArea());
}

TEST(CircleTest, ZeroFerenceCreatesZeroRadiusAndArea) {
  Circle circle(4.0);

  circle.setFerence(0.0);

  EXPECT_DOUBLE_EQ(0.0, circle.getRadius());
  EXPECT_DOUBLE_EQ(0.0, circle.getFerence());
  EXPECT_DOUBLE_EQ(0.0, circle.getArea());
}

TEST(CircleTest, ZeroAreaCreatesZeroRadiusAndFerence) {
  Circle circle(4.0);

  circle.setArea(0.0);

  EXPECT_DOUBLE_EQ(0.0, circle.getRadius());
  EXPECT_DOUBLE_EQ(0.0, circle.getFerence());
  EXPECT_DOUBLE_EQ(0.0, circle.getArea());
}

TEST(CircleTest, ConstructorThrowsOnNegativeRadius) {
  EXPECT_THROW(Circle(-1.0), std::invalid_argument);
}

TEST(CircleTest, SetRadiusThrowsOnNegativeRadius) {
  Circle circle(1.0);

  EXPECT_THROW(circle.setRadius(-1.0), std::invalid_argument);
}

TEST(CircleTest, SetFerenceThrowsOnNegativeFerence) {
  Circle circle(1.0);

  EXPECT_THROW(circle.setFerence(-1.0), std::invalid_argument);
}

TEST(CircleTest, SetAreaThrowsOnNegativeArea) {
  Circle circle(1.0);

  EXPECT_THROW(circle.setArea(-1.0), std::invalid_argument);
}

TEST(CircleTest, CircleRemainsConsistentAfterSequentialChanges) {
  Circle circle(2.0);

  circle.setRadius(5.0);
  circle.setFerence(8.0 * kPi);
  circle.setArea(16.0 * kPi);

  EXPECT_NEAR(4.0, circle.getRadius(), kEps);
  EXPECT_NEAR(8.0 * kPi, circle.getFerence(), kEps);
  EXPECT_NEAR(16.0 * kPi, circle.getArea(), kEps);
}

TEST(TaskTest, EarthRopeGapIsCalculatedCorrectly) {
  EXPECT_NEAR(1.0 / (2.0 * kPi), getEarthRopeGap(), kEps);
}

TEST(TaskTest, PoolConcreteCostIsCalculatedCorrectly) {
  const PoolCosts costs = getPoolCosts();

  EXPECT_NEAR(7000.0 * kPi, costs.concrete_cost, kEps);
}

TEST(TaskTest, PoolFenceCostIsCalculatedCorrectly) {
  const PoolCosts costs = getPoolCosts();

  EXPECT_NEAR(16000.0 * kPi, costs.fence_cost, kEps);
}
