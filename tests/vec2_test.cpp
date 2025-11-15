#include <gtest/gtest.h>
#include "starlet-math/vec2.hpp"

namespace SMath = Starlet::Math;

TEST(Vec2Test, DefaultConstructor) {
	SMath::Vec2<int> vi;
	SMath::Vec2<float> vf;
	SMath::Vec2<double> vd;

	ASSERT_EQ(vi.x, 0); ASSERT_EQ(vi.y, 0);
	ASSERT_FLOAT_EQ(vf.x, 0.0f); ASSERT_FLOAT_EQ(vf.y, 0.0f);
	ASSERT_DOUBLE_EQ(vd.x, 0.0); ASSERT_DOUBLE_EQ(vd.y, 0.0);
}
TEST(Vec2Test, SingleParamConstructor) {
	SMath::Vec2<int> vi(1);
	SMath::Vec2<float> vf(1.1f);
	SMath::Vec2<double> vd(1.1);

	ASSERT_EQ(vi.x, 1); ASSERT_EQ(vi.y, 1);
	ASSERT_FLOAT_EQ(vf.x, 1.1f); ASSERT_FLOAT_EQ(vf.y, 1.1f);
	ASSERT_DOUBLE_EQ(vd.x, 1.1); ASSERT_DOUBLE_EQ(vd.y, 1.1);
}
TEST(Vec2Test, ParameterConstructor) {
	SMath::Vec2<int> vi(1, -1);
	SMath::Vec2<float> vf(1.1f, -1.1f);
	SMath::Vec2<double> vd(1.1, -1.1);

	ASSERT_EQ(vi.x, 1); ASSERT_EQ(vi.y, -1);
	ASSERT_FLOAT_EQ(vf.x, 1.1f); ASSERT_FLOAT_EQ(vf.y, -1.1f);
	ASSERT_DOUBLE_EQ(vd.x, 1.1); ASSERT_DOUBLE_EQ(vd.y, -1.1);
}
TEST(Vec2Test, CopyConstructor) {
	SMath::Vec2<int> vi1(1, -1);
	SMath::Vec2<float> vf1(1.1f, -1.1f);
	SMath::Vec2<double> vd1(1.1, -1.1);

	SMath::Vec2<int> vi2(vi1);
	SMath::Vec2<float> vf2(vf1);
	SMath::Vec2<double> vd2(vd1);

	ASSERT_EQ(vi2.x, 1); ASSERT_EQ(vi2.y, -1);
	ASSERT_FLOAT_EQ(vf2.x, 1.1f); ASSERT_FLOAT_EQ(vf2.y, -1.1f);
	ASSERT_DOUBLE_EQ(vd2.x, 1.1); ASSERT_DOUBLE_EQ(vd2.y, -1.1);
}
TEST(Vec2Test, Negative) {
	SMath::Vec2<int> vi(-1, -2), vi2(-3, -4);
	SMath::Vec2<int> vi3 = vi * vi2;
	ASSERT_EQ(vi3.x, 3);
	ASSERT_EQ(vi3.y, 8);

	SMath::Vec2<float> vf(-1.5f, -2.5f), vf2(-3.5f, -4.5f);
	SMath::Vec2<float> vf3 = vf - vf2;
	ASSERT_FLOAT_EQ(vf3.x, 2.0f);
	ASSERT_FLOAT_EQ(vf3.y, 2.0f);

	SMath::Vec2<double> vd(-1.5, -2.5), vd2(-3.5, -4.5);
	SMath::Vec2<double> vd3 = vd + vd2;
	ASSERT_DOUBLE_EQ(vd3.x, -5.0);
	ASSERT_DOUBLE_EQ(vd3.y, -7.0);
}

TEST(Vec2Test, Assignment) {
	SMath::Vec2<int> vi1(1, 1), vi2;
	SMath::Vec2<float> vf1(1.1f, 1.1f), vf2;
	SMath::Vec2<double> vd1(1.1, 1.1), vd2;

	vi2 = vi1;
	vf2 = vf1;
	vd2 = vd1;

	ASSERT_EQ(vi2.x, 1);  ASSERT_EQ(vi2.y, 1);
	ASSERT_FLOAT_EQ(vf2.x, 1.1f); ASSERT_FLOAT_EQ(vf2.y, 1.1f);
	ASSERT_DOUBLE_EQ(vd2.x, 1.1); ASSERT_DOUBLE_EQ(vd2.y, 1.1);
}
TEST(Vec2Test, SelfAssignment) {
	SMath::Vec2<int> vi(1, 1);
	SMath::Vec2<float> vf(1.1f, 1.1f);
	SMath::Vec2<double> vd(1.1, 1.1);

	vi = vi;
	vf = vf;
	vd = vd;

	ASSERT_EQ(vi.x, 1); ASSERT_EQ(vi.y, 1);
	ASSERT_FLOAT_EQ(vf.x, 1.1f); ASSERT_FLOAT_EQ(vf.y, 1.1f);
	ASSERT_DOUBLE_EQ(vd.x, 1.1); ASSERT_DOUBLE_EQ(vd.y, 1.1);
}

TEST(Vec2Test, AdditionAndSubtraction) {
	SMath::Vec2<int> vi1(1, 2), vi2(3, 4);
	SMath::Vec2<float> vf1(1.0f, 2.0f), vf2(3.0f, 4.0f);
	SMath::Vec2<double> vd1(1.0, 2.0), vd2(3.0, 4.0);

	SMath::Vec2<int> viAdd = vi1 + vi2;
	SMath::Vec2<int> viSub = vi1 - vi2;
	SMath::Vec2<float> vfAdd = vf1 + vf2;
	SMath::Vec2<float> vfSub = vf1 - vf2;
	SMath::Vec2<double> vdAdd = vd1 + vd2;
	SMath::Vec2<double> vdSub = vd1 - vd2;

	ASSERT_EQ(viAdd.x, 4); ASSERT_EQ(viAdd.y, 6);
	ASSERT_EQ(viSub.x, -2); ASSERT_EQ(viSub.y, -2);
	ASSERT_FLOAT_EQ(vfAdd.x, 4.0f); ASSERT_FLOAT_EQ(vfAdd.y, 6.0f);
	ASSERT_FLOAT_EQ(vfSub.x, -2.0f); ASSERT_FLOAT_EQ(vfSub.y, -2.0f);
	ASSERT_DOUBLE_EQ(vdAdd.x, 4.0); ASSERT_DOUBLE_EQ(vdAdd.y, 6.0);
	ASSERT_DOUBLE_EQ(vdSub.x, -2.0); ASSERT_DOUBLE_EQ(vdSub.y, -2.0);
}

TEST(Vec2Test, MultiplicationAndDivision) {
	SMath::Vec2<int> vi(1, 2);
	SMath::Vec2<float> vf(1.0f, 2.0f);
	SMath::Vec2<double> vd(1.0, 2.0);

	SMath::Vec2<int> viMul = vi * 3;
	SMath::Vec2<int> viDiv = vi / 2;
	SMath::Vec2<float> vfMul = vf * 2.0f;
	SMath::Vec2<float> vfDiv = vf / 0.5f;
	SMath::Vec2<double> vdMul = vd * 2.0;
	SMath::Vec2<double> vdDiv = vd / 2.0;

	ASSERT_EQ(viMul.x, 3); ASSERT_EQ(viMul.y, 6);
	ASSERT_EQ(viDiv.x, 0); ASSERT_EQ(viDiv.y, 1);
	ASSERT_FLOAT_EQ(vfMul.x, 2.0f); ASSERT_FLOAT_EQ(vfMul.y, 4.0f);
	ASSERT_FLOAT_EQ(vfDiv.x, 2.0f); ASSERT_FLOAT_EQ(vfDiv.y, 4.0f);
	ASSERT_DOUBLE_EQ(vdMul.x, 2.0); ASSERT_DOUBLE_EQ(vdMul.y, 4.0);
	ASSERT_DOUBLE_EQ(vdDiv.x, 0.5); ASSERT_DOUBLE_EQ(vdDiv.y, 1.0);
}
TEST(Vec2Test, ComponentWiseMultiplicationAndDivision) {
	SMath::Vec2<int> vi1(2, 3), vi2(4, 5);
	SMath::Vec2<float> vf1(1.5f, 2.5f), vf2(2.0f, 0.5f);
	SMath::Vec2<double> vd1(1.0, 2.0), vd2(0.5, 4.0);

	SMath::Vec2<int> viMul = vi1 * vi2;
	SMath::Vec2<int> viDiv = vi2 / vi1;
	SMath::Vec2<float> vfMul = vf1 * vf2;
	SMath::Vec2<float> vfDiv = vf1 / vf2;
	SMath::Vec2<double> vdMul = vd1 * vd2;
	SMath::Vec2<double> vdDiv = vd1 / vd2;

	ASSERT_EQ(viMul.x, 8); ASSERT_EQ(viMul.y, 15);
	ASSERT_EQ(viDiv.x, 2); ASSERT_EQ(viDiv.y, 1);
	ASSERT_FLOAT_EQ(vfMul.x, 3.0f); ASSERT_FLOAT_EQ(vfMul.y, 1.25f);
	ASSERT_FLOAT_EQ(vfDiv.x, 0.75f); ASSERT_FLOAT_EQ(vfDiv.y, 5.0f);
	ASSERT_DOUBLE_EQ(vdMul.x, 0.5); ASSERT_DOUBLE_EQ(vdMul.y, 8.0);
	ASSERT_DOUBLE_EQ(vdDiv.x, 2.0); ASSERT_DOUBLE_EQ(vdDiv.y, 0.5);
}

TEST(Vec2Test, Compound) {
	SMath::Vec2<int> vi(1, 2);
	SMath::Vec2<float> vf(1.0f, 2.0f);
	SMath::Vec2<double> vd(1.0, 2.0);

	vi += SMath::Vec2<int>(3, 4);
	vf += SMath::Vec2<float>(3.0f, 4.0f);
	vd += SMath::Vec2<double>(3.0, 4.0);

	ASSERT_EQ(vi.x, 4);	ASSERT_EQ(vi.y, 6);
	ASSERT_FLOAT_EQ(vf.x, 4.0f); ASSERT_FLOAT_EQ(vf.y, 6.0f);
	ASSERT_DOUBLE_EQ(vd.x, 4.0); ASSERT_DOUBLE_EQ(vd.y, 6.0);

	vi -=SMath::Vec2<int>(3, 4);
	vf -=SMath::Vec2<float>(3.0f, 4.0f);
	vd -=SMath::Vec2<double>(3.0, 4.0);

	ASSERT_EQ(vi.x, 1); ASSERT_EQ(vi.y, 2);
	ASSERT_FLOAT_EQ(vf.x, 1.0f); ASSERT_FLOAT_EQ(vf.y, 2.0f);
	ASSERT_DOUBLE_EQ(vd.x, 1.0); ASSERT_DOUBLE_EQ(vd.y, 2.0);

	vi *= 3;
	vf *= 3.0f;
	vd *= 3.0;

	ASSERT_EQ(vi.x, 3);	ASSERT_EQ(vi.y, 6);
	ASSERT_FLOAT_EQ(vf.x, 3.0f); ASSERT_FLOAT_EQ(vf.y, 6.0f);
	ASSERT_DOUBLE_EQ(vd.x, 3.0); ASSERT_DOUBLE_EQ(vd.y, 6.0);

	vi /= 3;
	vf /= 3.0f;
	vd /= 3.0;

	ASSERT_EQ(vi.x, 1); ASSERT_EQ(vi.y, 2);
	ASSERT_FLOAT_EQ(vf.x, 1.0f); ASSERT_FLOAT_EQ(vf.y, 2.0f);
	ASSERT_DOUBLE_EQ(vd.x, 1.0); ASSERT_DOUBLE_EQ(vd.y, 2.0);
}

TEST(Vec2Test, Comparison) {
	SMath::Vec2<int> vi1(1, 2), vi2(1, 2), vi3(3, 4);
	SMath::Vec2<float> vf1(1.0f, 2.0f), vf2(1.0f, 2.0f), vf3(3.0f, 4.0f);
	SMath::Vec2<double> vd1(1.0, 2.0), vd2(1.0, 2.0), vd3(3.0, 4.0);

	ASSERT_TRUE(vi1 == vi2); ASSERT_FALSE(vi1 == vi3);
	ASSERT_TRUE(vf1 == vf2); ASSERT_FALSE(vf1 == vf3);
	ASSERT_TRUE(vd1 == vd2); ASSERT_FALSE(vd1 == vd3);

	ASSERT_FALSE(vi1 != vi2); ASSERT_TRUE(vi1 != vi3);
	ASSERT_FALSE(vf1 != vf2); ASSERT_TRUE(vf1 != vf3);
	ASSERT_FALSE(vd1 != vd2); ASSERT_TRUE(vd1 != vd3);
}

TEST(Vec2Test, Length) {
	SMath::Vec2<int> vi(3, 4);
	SMath::Vec2<float> vf(3.0f, 4.0f);
	SMath::Vec2<double> vd(3.0, 4.0);

	ASSERT_FLOAT_EQ(vi.length(), 5.0f);
	ASSERT_FLOAT_EQ(vf.length(), 5.0f);
	ASSERT_DOUBLE_EQ(vd.length(), 5.0);
}
TEST(Vec2Test, LengthSquared) {
	SMath::Vec2<int> vi(3, 4);
	SMath::Vec2<float> vf(3.0f, 4.0f);
	SMath::Vec2<double> vd(3.0, 4.0);

	ASSERT_EQ(vi.lengthSquared(), 25);
	ASSERT_FLOAT_EQ(vf.lengthSquared(), 25.0f);
	ASSERT_DOUBLE_EQ(vd.lengthSquared(), 25.0);
}

TEST(Vec2Test, Normalize) {
	SMath::Vec2<int> vi(3, 4);
	SMath::Vec2<float> vf(3.0f, 4.0f);
	SMath::Vec2<double> vd(3.0, 4.0);

	SMath::Vec2<double> viNorm = vi.normalized();
	SMath::Vec2<float> vfNorm = vf.normalized();
	SMath::Vec2<double> vdNorm = vd.normalized();

	ASSERT_DOUBLE_EQ(viNorm.x, 0.6); ASSERT_DOUBLE_EQ(viNorm.y, 0.8);
	ASSERT_FLOAT_EQ(vfNorm.x, 0.6f); ASSERT_FLOAT_EQ(vfNorm.y, 0.8f);
	ASSERT_DOUBLE_EQ(vdNorm.x, 0.6); ASSERT_DOUBLE_EQ(vdNorm.y, 0.8);
}
TEST(Vec2Test, NormalizeZero) {
	SMath::Vec2<int> vi(0, 0);
	SMath::Vec2<float> vf(0.0f, 0.0f);
	SMath::Vec2<double> vd(0.0, 0.0);

	SMath::Vec2<double> viNorm = vi.normalized();
	SMath::Vec2<float> vfNorm = vf.normalized();
	SMath::Vec2<double> vdNorm = vd.normalized();

	ASSERT_DOUBLE_EQ(viNorm.x, 0.0); ASSERT_DOUBLE_EQ(viNorm.y, 0.0);
	ASSERT_FLOAT_EQ(vfNorm.x, 0.0f); ASSERT_FLOAT_EQ(vfNorm.y, 0.0f);
	ASSERT_DOUBLE_EQ(vdNorm.x, 0.0); ASSERT_DOUBLE_EQ(vdNorm.y, 0.0);
}
TEST(Vec2Test, NormalizeTiny) {
	SMath::Vec2<float> vf(1e-8f, -1e-8f);
	SMath::Vec2<double> vd(1e-16, -1e-16);

	SMath::Vec2<float> vfNorm = vf.normalized();
	SMath::Vec2<double> vdNorm = vd.normalized();

	ASSERT_FLOAT_EQ(vfNorm.x, 0.0f); ASSERT_FLOAT_EQ(vfNorm.y, 0.0f);
	ASSERT_DOUBLE_EQ(vdNorm.x, 0.0); ASSERT_DOUBLE_EQ(vdNorm.y, 0.0);
}

TEST(Vec2Test, DotProduct) {
	SMath::Vec2<int> vi1(1, 2);
	SMath::Vec2<int> vi2(3, 4);
	SMath::Vec2<float> vf1(1.0f, 2.0f);
	SMath::Vec2<float> vf2(3.0f, 4.0f);
	SMath::Vec2<double> vd1(1.0, 2.0);
	SMath::Vec2<double> vd2(3.0, 4.0);

	ASSERT_EQ(vi1.dot(vi2), 11);
	ASSERT_FLOAT_EQ(vf1.dot(vf2), 11.0f);
	ASSERT_DOUBLE_EQ(vd1.dot(vd2), 11.0);
}

TEST(Vec2Test, UnaryMinus) {
	SMath::Vec2<int> vi(1, -1);
	SMath::Vec2<float> vf(1.1f, -1.1f);
	SMath::Vec2<double> vd(1.1, -1.1);

	SMath::Vec2<int> viNeg = -vi;
	SMath::Vec2<float> vfNeg = -vf;
	SMath::Vec2<double> vdNeg = -vd;

	ASSERT_EQ(viNeg.x, -1); ASSERT_EQ(viNeg.y, 1);
	ASSERT_FLOAT_EQ(vfNeg.x, -1.1f); ASSERT_FLOAT_EQ(vfNeg.y, 1.1f); 
	ASSERT_DOUBLE_EQ(vdNeg.x, -1.1); ASSERT_DOUBLE_EQ(vdNeg.y, 1.1); 
}
