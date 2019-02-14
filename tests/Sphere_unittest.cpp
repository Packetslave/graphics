//
// Created by Brian Landers on 2019-01-10.
//

#include "gtest/gtest.h"
#include "../src/Point.h"
#include "../src/Ray.h"
#include "../src/Sphere.h"
#include "../src/Matrix.h"

namespace {

TEST(Sphere, Intersects) {
  Point p(0, 0, -5);
  Vector3 v(0, 0, 1);
  Ray r(p, v);
  Sphere s;

  auto i = s.intersects(r);
  ASSERT_EQ(2, i.size());
  ASSERT_EQ(4.0, i[0].t());
  ASSERT_EQ(6.0, i[1].t());
}

TEST(Sphere, Tangent) {
  Point p(0, 1, -5);
  Vector3 v(0, 0, 1);
  Ray r(p, v);
  Sphere s;

  auto i = s.intersects(r);
  ASSERT_EQ(2, i.size());
  ASSERT_EQ(5.0, i[0].t());
  ASSERT_EQ(5.0, i[1].t());
}

TEST(Sphere, Misses) {
  Point p(0, 2, -5);
  Vector3 v(0, 0, 1);
  Ray r(p, v);
  Sphere s;

  auto i = s.intersects(r);
  ASSERT_EQ(0, i.size());
}

TEST(Sphere, Inside) {
  Point p(0, 0, 0);
  Vector3 v(0, 0, 1);
  Ray r(p, v);
  Sphere s;

  auto i = s.intersects(r);
  ASSERT_EQ(2, i.size());
  ASSERT_EQ(-1.0, i[0].t());
  ASSERT_EQ(1.0, i[1].t());
}

TEST(Sphere, Behind) {
  Point p(0, 0, 5);
  Vector3 v(0, 0, 1);
  Ray r(p, v);
  Sphere s;

  auto i = s.intersects(r);
  ASSERT_EQ(2, i.size());
  ASSERT_EQ(-6.0, i[0].t());
  ASSERT_EQ(-4.0, i[1].t());
}

TEST(Sphere, Encapsulates) {
  Point p(0, 0, -5);
  Vector3 v(0, 0, 1);
  Ray r(p, v);
  Sphere s;

  auto i = s.intersects(r);
  ASSERT_EQ(2, i.size());
  ASSERT_EQ(&s, i[0].object());
  ASSERT_EQ(&s, i[1].object());
}

TEST(Sphere, HitPositive) {
  Sphere s;
  Intersection i1(1, &s);
  Intersection i2(2, &s);
  auto i = Hit({i2, i1});
  ASSERT_EQ(i1, i);
}

TEST(Sphere, HitSomeNegative) {
  Sphere s;
  Intersection i1(-1, &s);
  Intersection i2(1, &s);
  auto i = Hit({i2, i1});
  ASSERT_EQ(i2, i);
}

TEST(Sphere, HitAllNegative) {
  Sphere s;
  Intersection i1(-2, &s);
  Intersection i2(-1, &s);
  auto i = Hit({i2, i1});
  ASSERT_FALSE(i);
}

TEST(Sphere, HitMany) {
  Sphere s;
  Intersection i1(5, &s);
  Intersection i2(7, &s);
  Intersection i3(-3, &s);
  Intersection i4(2, &s);
  auto i = Hit({i1, i2, i3, i4});
  ASSERT_EQ(i4, i);
}

TEST(Sphere, NormalX) {
  Sphere s;
  auto n = s.normal_at(Point(1, 0, 0));
  ASSERT_EQ(Vector3(1, 0, 0), n);
}

TEST(Sphere, NormalY) {
  Sphere s;
  auto n = s.normal_at(Point(0, 1, 0));
  ASSERT_EQ(Vector3(0, 1, 0), n);
}

TEST(Sphere, NormalZ) {
  Sphere s;
  auto n = s.normal_at(Point(0, 0, 1));
  ASSERT_EQ(Vector3(0, 0, 1), n);
}

TEST(Sphere, NormalNonAxis) {
  Sphere s;
  auto n = s.normal_at(Point(sqrt(3.0) / 3.0, sqrt(3.0) / 3.0, sqrt(3.0) / 3.0));

  // TODO: implement ASSERT_NEAR for objects
  // ASSERT_EQ(Vector3(sqrt(3.0) / 3.0, sqrt(3.0) / 3.0, sqrt(3.0) / 3.0), n);
}

TEST(Sphere, NormalIsNormalized) {
  Sphere s;
  auto n = s.normal_at(Point(sqrt(3.0) / 3.0, sqrt(3.0) / 3.0, sqrt(3.0) / 3.0));

  // TODO: implement ASSERT_NEAR for objects
  // ASSERT_EQ(n.normalize(), n);
}

TEST(Sphere, TranslatedNormal1) {
  Sphere s;
  // TODO: go back and implement transform stuff

  auto n = s.normal_at(Point(0, 1.70711, -0.70711));
  ASSERT_EQ(Vector3(0, 0.70711, -0.70711), n);
}

TEST(Sphere, TranslatedNormal2) {
  Sphere s;
  auto m = CreateScaling(1, 0.5, 1 * CreateRotationZ(3.14159 / 5));
  // TODO: go back and implement transform stuff

  auto n = s.normal_at(Point(0, sqrt(2.0) / 2, -1 * sqrt(2.0) / 2));
  ASSERT_EQ(Vector3(0, 0.97014, -0.24254), n);
}

}