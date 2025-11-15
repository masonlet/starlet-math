#include <gtest/gtest.h>
#include "starlet-math/vec3.hpp"

namespace SMath = Starlet::Math;

TEST(Vec3Test, DefaultConstructor) {
	SMath::Vec3<int> vi;
	SMath::Vec3<float> vf;
	SMath::Vec3<double> vd;

	ASSERT_EQ(vi.x, 0); ASSERT_EQ(vi.y, 0); ASSERT_EQ(vi.z, 0);
	ASSERT_FLOAT_EQ(vf.x, 0.0f); ASSERT_FLOAT_EQ(vf.y, 0.0f); ASSERT_FLOAT_EQ(vf.z, 0.0f);
	ASSERT_DOUBLE_EQ(vd.x, 0.0); ASSERT_DOUBLE_EQ(vd.y, 0.0); ASSERT_DOUBLE_EQ(vd.z, 0.0);
}
TEST(Vec3Test, SingleParamConstructor) {
	SMath::Vec3<int> vi(1);
	SMath::Vec3<float> vf(1.1f);
	SMath::Vec3<double> vd(1.1);

	ASSERT_EQ(vi.x, 1); ASSERT_EQ(vi.y, 1); ASSERT_EQ(vi.z, 1);
	ASSERT_FLOAT_EQ(vf.x, 1.1f); ASSERT_FLOAT_EQ(vf.y, 1.1f); ASSERT_FLOAT_EQ(vf.z, 1.1f);
	ASSERT_DOUBLE_EQ(vd.x, 1.1); ASSERT_DOUBLE_EQ(vd.y, 1.1); ASSERT_DOUBLE_EQ(vd.z, 1.1);
}
TEST(Vec3Test, ParameterConstructor) {
	SMath::Vec3<int> vi(1, -1, 0);
	SMath::Vec3<float> vf(1.1f, -1.1f, 0.0f);
	SMath::Vec3<double> vd(1.1, -1.1, 0.0);

	ASSERT_EQ(vi.x, 1); ASSERT_EQ(vi.y, -1); ASSERT_EQ(vi.z, 0);
	ASSERT_FLOAT_EQ(vf.x, 1.1f); ASSERT_FLOAT_EQ(vf.y, -1.1f); ASSERT_FLOAT_EQ(vf.z, 0.0f);
	ASSERT_DOUBLE_EQ(vd.x, 1.1); ASSERT_DOUBLE_EQ(vd.y, -1.1); ASSERT_DOUBLE_EQ(vd.z, 0.0);
}
TEST(Vec3Test, CopyConstructor) {
	SMath::Vec3<int> vi1(1, -1, 0);
	SMath::Vec3<float> vf1(1.1f, -1.1f, 0.0f);
	SMath::Vec3<double> vd1(1.1, -1.1, 0.0);

	SMath::Vec3<int> vi2(vi1);
	SMath::Vec3<float> vf2(vf1);
	SMath::Vec3<double> vd2(vd1);

	ASSERT_EQ(vi2.x, 1); ASSERT_EQ(vi2.y, -1); ASSERT_EQ(vi2.z, 0);
	ASSERT_FLOAT_EQ(vf2.x, 1.1f); ASSERT_FLOAT_EQ(vf2.y, -1.1f); ASSERT_FLOAT_EQ(vf2.z, 0.0f);
	ASSERT_DOUBLE_EQ(vd2.x, 1.1); ASSERT_DOUBLE_EQ(vd2.y, -1.1); ASSERT_DOUBLE_EQ(vd2.z, 0.0);
}
TEST(Vec3Test, Negative) {
	SMath::Vec3<int> vi(-1, -2, -3), vi2(-3, -4, -5);
	SMath::Vec3<int> vi3 = vi * vi2;
	ASSERT_EQ(vi3.x, 3);
	ASSERT_EQ(vi3.y, 8);
	ASSERT_EQ(vi3.z, 15);

	SMath::Vec3<float> vf(-1.5f, -2.5f, -3.5f), vf2(-3.5f, -4.5f, -5.5f);
	SMath::Vec3<float> vf3 = vf - vf2;
	ASSERT_FLOAT_EQ(vf3.x, 2.0f);
	ASSERT_FLOAT_EQ(vf3.y, 2.0f);
	ASSERT_FLOAT_EQ(vf3.z, 2.0f);

	SMath::Vec3<double> vd(-1.5, -2.5, -3.5), vd2(-3.5, -4.5, -5.5);
	SMath::Vec3<double> vd3 = vd + vd2;
	ASSERT_DOUBLE_EQ(vd3.x, -5.0);
	ASSERT_DOUBLE_EQ(vd3.y, -7.0);
	ASSERT_DOUBLE_EQ(vd3.z, -9.0);
}

TEST(Vec3Test, Assignment) {
	SMath::Vec3<int> vi1(1, 1, 1), vi2;
	SMath::Vec3<float> vf1(1.1f, 1.1f, 1.1f), vf2;
	SMath::Vec3<double> vd1(1.1, 1.1, 1.1), vd2;

	vi2 = vi1;
	vf2 = vf1;
	vd2 = vd1;

	ASSERT_EQ(vi2.x, 1); ASSERT_EQ(vi2.y, 1); ASSERT_EQ(vi2.z, 1);
	ASSERT_FLOAT_EQ(vf2.x, 1.1f); ASSERT_FLOAT_EQ(vf2.y, 1.1f); ASSERT_FLOAT_EQ(vf2.z, 1.1f);
	ASSERT_DOUBLE_EQ(vd2.x, 1.1); ASSERT_DOUBLE_EQ(vd2.y, 1.1); ASSERT_DOUBLE_EQ(vd2.z, 1.1);
}
TEST(Vec3Test, SelfAssignment) {
	SMath::Vec3<int> vi(1, 1, 1);
	SMath::Vec3<float> vf(1.1f, 1.1f, 1.1f);
	SMath::Vec3<double> vd(1.1, 1.1, 1.1);

	vi = vi;
	vf = vf;
	vd = vd;

	ASSERT_EQ(vi.x, 1); ASSERT_EQ(vi.y, 1); ASSERT_EQ(vi.z, 1);
	ASSERT_FLOAT_EQ(vf.x, 1.1f); ASSERT_FLOAT_EQ(vf.y, 1.1f); ASSERT_FLOAT_EQ(vf.z, 1.1f);
	ASSERT_DOUBLE_EQ(vd.x, 1.1); ASSERT_DOUBLE_EQ(vd.y, 1.1); ASSERT_DOUBLE_EQ(vd.z, 1.1);
}

TEST(Vec3Test, AdditionAndSubtraction) {
	SMath::Vec3<int> vi1(1, 2, 3), vi2(3, 4, 5);
	SMath::Vec3<float> vf1(1.0f, 2.0f, 3.0f), vf2(3.0f, 4.0f, 5.0f);
	SMath::Vec3<double> vd1(1.0, 2.0, 3.0), vd2(3.0, 4.0, 5.0);

	SMath::Vec3<int> viAdd = vi1 + vi2;
	SMath::Vec3<int> viSub = vi1 - vi2;
	SMath::Vec3<float> vfAdd = vf1 + vf2;
	SMath::Vec3<float> vfSub = vf1 - vf2;
	SMath::Vec3<double> vdAdd = vd1 + vd2;
	SMath::Vec3<double> vdSub = vd1 - vd2;

	ASSERT_EQ(viAdd.x, 4); ASSERT_EQ(viAdd.y, 6); ASSERT_EQ(viAdd.z, 8);
	ASSERT_EQ(viSub.x, -2); ASSERT_EQ(viSub.y, -2); ASSERT_EQ(viSub.z, -2);
	ASSERT_FLOAT_EQ(vfAdd.x, 4.0f); ASSERT_FLOAT_EQ(vfAdd.y, 6.0f); ASSERT_FLOAT_EQ(vfAdd.z, 8.0f);
	ASSERT_FLOAT_EQ(vfSub.x, -2.0f); ASSERT_FLOAT_EQ(vfSub.y, -2.0f); ASSERT_FLOAT_EQ(vfSub.z, -2.0f);
	ASSERT_DOUBLE_EQ(vdAdd.x, 4.0); ASSERT_DOUBLE_EQ(vdAdd.y, 6.0); ASSERT_DOUBLE_EQ(vdAdd.z, 8.0);
	ASSERT_DOUBLE_EQ(vdSub.x, -2.0); ASSERT_DOUBLE_EQ(vdSub.y, -2.0); ASSERT_DOUBLE_EQ(vdSub.z, -2.0);
}

TEST(Vec3Test, MultiplicationAndDivision) {
	SMath::Vec3<int> vi(1, 2, 3);
	SMath::Vec3<float> vf(1.0f, 2.0f, 3.0f);
	SMath::Vec3<double> vd(1.0, 2.0, 3.0);

	SMath::Vec3<int> viMul = vi * 3;
	SMath::Vec3<int> viDiv = vi / 2;
	SMath::Vec3<float> vfMul = vf * 2.0f;
	SMath::Vec3<float> vfDiv = vf / 0.5f;
	SMath::Vec3<double> vdMul = vd * 2.0;
	SMath::Vec3<double> vdDiv = vd / 2.0;

	ASSERT_EQ(viMul.x, 3); ASSERT_EQ(viMul.y, 6); ASSERT_EQ(viMul.z, 9);
	ASSERT_EQ(viDiv.x, 0); ASSERT_EQ(viDiv.y, 1); ASSERT_EQ(viDiv.z, 1);
	ASSERT_FLOAT_EQ(vfMul.x, 2.0f); ASSERT_FLOAT_EQ(vfMul.y, 4.0f); ASSERT_FLOAT_EQ(vfMul.z, 6.0f);
	ASSERT_FLOAT_EQ(vfDiv.x, 2.0f); ASSERT_FLOAT_EQ(vfDiv.y, 4.0f); ASSERT_FLOAT_EQ(vfDiv.z, 6.0f);
	ASSERT_DOUBLE_EQ(vdMul.x, 2.0); ASSERT_DOUBLE_EQ(vdMul.y, 4.0); ASSERT_DOUBLE_EQ(vdMul.z, 6.0);
	ASSERT_DOUBLE_EQ(vdDiv.x, 0.5); ASSERT_DOUBLE_EQ(vdDiv.y, 1.0); ASSERT_DOUBLE_EQ(vdDiv.z, 1.5);
}
TEST(Vec3Test, ComponentWiseMultiplicationAndDivision) {
	SMath::Vec3<int> vi1(2, 3, 4), vi2(4, 5, 6);
	SMath::Vec3<float> vf1(1.5f, 2.5f, 3.5f), vf2(2.0f, 3.0f, 4.0f);
	SMath::Vec3<double> vd1(1.0, 2.0, 3.0), vd2(2.0, 3.0, 4.0);

	SMath::Vec3<int> viMul = vi1 * vi2;
	SMath::Vec3<int> viDiv = vi2 / vi1;
	SMath::Vec3<float> vfMul = vf1 * vf2;
	SMath::Vec3<float> vfDiv = vf1 / vf2;
	SMath::Vec3<double> vdMul = vd1 * vd2;
	SMath::Vec3<double> vdDiv = vd1 / vd2;

	ASSERT_EQ(viMul.x, 8); ASSERT_EQ(viMul.y, 15); ASSERT_EQ(viMul.z, 24);
	ASSERT_EQ(viDiv.x, 2); ASSERT_EQ(viDiv.y, 1); ASSERT_EQ(viDiv.z, 1);
	ASSERT_FLOAT_EQ(vfMul.x, 3.0f); ASSERT_FLOAT_EQ(vfMul.y, 7.5f); ASSERT_FLOAT_EQ(vfMul.z, 14.0f);
	ASSERT_FLOAT_EQ(vfDiv.x, 0.75f); ASSERT_FLOAT_EQ(vfDiv.y, 2.5f / 3.0f); ASSERT_FLOAT_EQ(vfDiv.z, 0.875f);
	ASSERT_DOUBLE_EQ(vdMul.x, 2.0); ASSERT_DOUBLE_EQ(vdMul.y, 6.0); ASSERT_DOUBLE_EQ(vdMul.z, 12.0);
	ASSERT_DOUBLE_EQ(vdDiv.x, 0.5); ASSERT_DOUBLE_EQ(vdDiv.y, 2.0 / 3.0); ASSERT_DOUBLE_EQ(vdDiv.z, 0.75);
}

TEST(Vec3Test, Compound) {
	SMath::Vec3<int> vi(1, 2, 3);
	SMath::Vec3<float> vf(1.0f, 2.0f, 3.0f);
	SMath::Vec3<double> vd(1.0, 2.0, 3.0);

	vi += SMath::Vec3<int>(3, 4, 5);
	vf += SMath::Vec3<float>(3.0f, 4.0f, 5.0f);
	vd += SMath::Vec3<double>(3.0, 4.0, 5.0);

	ASSERT_EQ(vi.x, 4);	ASSERT_EQ(vi.y, 6); ASSERT_EQ(vi.z, 8);
	ASSERT_FLOAT_EQ(vf.x, 4.0f); ASSERT_FLOAT_EQ(vf.y, 6.0f); ASSERT_FLOAT_EQ(vf.z, 8.0f);
	ASSERT_DOUBLE_EQ(vd.x, 4.0); ASSERT_DOUBLE_EQ(vd.y, 6.0); ASSERT_DOUBLE_EQ(vd.z, 8.0);

	vi -= SMath::Vec3<int>(3, 4, 5);
	vf -= SMath::Vec3<float>(3.0f, 4.0f, 5.0f);
	vd -= SMath::Vec3<double>(3.0, 4.0, 5.0);

	ASSERT_EQ(vi.x, 1); ASSERT_EQ(vi.y, 2); ASSERT_EQ(vi.z, 3);
	ASSERT_FLOAT_EQ(vf.x, 1.0f); ASSERT_FLOAT_EQ(vf.y, 2.0f); ASSERT_FLOAT_EQ(vf.z, 3.0f);
	ASSERT_DOUBLE_EQ(vd.x, 1.0); ASSERT_DOUBLE_EQ(vd.y, 2.0); ASSERT_DOUBLE_EQ(vd.z, 3.0);

	vi *= 3;
	vf *= 3.0f;
	vd *= 3.0;

	ASSERT_EQ(vi.x, 3);	ASSERT_EQ(vi.y, 6); ASSERT_EQ(vi.z, 9);
	ASSERT_FLOAT_EQ(vf.x, 3.0f); ASSERT_FLOAT_EQ(vf.y, 6.0f); ASSERT_FLOAT_EQ(vf.z, 9.0f);
	ASSERT_DOUBLE_EQ(vd.x, 3.0); ASSERT_DOUBLE_EQ(vd.y, 6.0); ASSERT_DOUBLE_EQ(vd.z, 9.0);

	vi /= 3;
	vf /= 3.0f;
	vd /= 3.0;

	ASSERT_EQ(vi.x, 1); ASSERT_EQ(vi.y, 2); ASSERT_EQ(vi.z, 3);
	ASSERT_FLOAT_EQ(vf.x, 1.0f); ASSERT_FLOAT_EQ(vf.y, 2.0f); ASSERT_FLOAT_EQ(vf.z, 3.0f);
	ASSERT_DOUBLE_EQ(vd.x, 1.0); ASSERT_DOUBLE_EQ(vd.y, 2.0); ASSERT_DOUBLE_EQ(vd.z, 3.0);
}

TEST(Vec3Test, Comparison) {
	SMath::Vec3<int> vi1(1, 2, 3), vi2(1, 2, 3), vi3(3, 4, 5);
	SMath::Vec3<float> vf1(1.0f, 2.0f, 3.0f), vf2(1.0f, 2.0f, 3.0f), vf3(3.0f, 4.0f, 5.0f);
	SMath::Vec3<double> vd1(1.0, 2.0, 3.0), vd2(1.0, 2.0, 3.0), vd3(3.0, 4.0, 5.0);

	ASSERT_TRUE(vi1 == vi2); ASSERT_FALSE(vi1 == vi3); 
	ASSERT_TRUE(vf1 == vf2); ASSERT_FALSE(vf1 == vf3);
	ASSERT_TRUE(vd1 == vd2); ASSERT_FALSE(vd1 == vd3);

	ASSERT_FALSE(vi1 != vi2); ASSERT_TRUE(vi1 != vi3);
	ASSERT_FALSE(vf1 != vf2); ASSERT_TRUE(vf1 != vf3);
	ASSERT_FALSE(vd1 != vd2); ASSERT_TRUE(vd1 != vd3);
}

TEST(Vec3Test, Length) {
	SMath::Vec3<int> vi(3, 4, 5);
	SMath::Vec3<float> vf(3.0f, 4.0f, 5.0f);
	SMath::Vec3<double> vd(3.0, 4.0, 5.0);

	ASSERT_FLOAT_EQ(vi.length(), std::sqrt(50.0f));
	ASSERT_FLOAT_EQ(vf.length(), std::sqrt(50.0f));
	ASSERT_DOUBLE_EQ(vd.length(), std::sqrt(50.0));
}
TEST(Vec3Test, LengthSquared) {
	SMath::Vec3<int> vi(3, 4, 5);
	SMath::Vec3<float> vf(3.0f, 4.0f, 5.0f);
	SMath::Vec3<double> vd(3.0, 4.0, 5.0);

	ASSERT_EQ(vi.lengthSquared(), 50);
	ASSERT_FLOAT_EQ(vf.lengthSquared(), 50.0f);
	ASSERT_DOUBLE_EQ(vd.lengthSquared(), 50.0);
}

TEST(Vec3Test, Normalize) {
	SMath::Vec3<int> vi(4, 4, 2);
	SMath::Vec3<float> vf(4.0f, 4.0f, 2.0f);
	SMath::Vec3<double> vd(4.0, 4.0, 2.0);

	SMath::Vec3<double> viNorm = vi.normalized();
	SMath::Vec3<float> vfNorm = vf.normalized();
	SMath::Vec3<double> vdNorm = vd.normalized();

	ASSERT_DOUBLE_EQ(viNorm.x, 2.0/3.0); ASSERT_DOUBLE_EQ(viNorm.y, 2.0 / 3.0); ASSERT_DOUBLE_EQ(viNorm.z, 1.0 / 3.0);
	ASSERT_FLOAT_EQ(vfNorm.x, 2.0f/3.0f); ASSERT_FLOAT_EQ(vfNorm.y, 2.0f / 3.0f); ASSERT_FLOAT_EQ(vfNorm.z, 1.0 / 3.0f);
	ASSERT_DOUBLE_EQ(vdNorm.x, 2.0/3.0); ASSERT_DOUBLE_EQ(vdNorm.y, 2.0 / 3.0); ASSERT_DOUBLE_EQ(vdNorm.z, 1.0 / 3.0);
}
TEST(Vec3Test, NormalizeZero) {
	SMath::Vec3<int> vi(0, 0, 0);
	SMath::Vec3<float> vf(0.0f, 0.0f, 0.0f);
	SMath::Vec3<double> vd(0.0, 0.0, 0.0);

	SMath::Vec3<double> viNorm = vi.normalized();
	SMath::Vec3<float> vfNorm = vf.normalized();
	SMath::Vec3<double> vdNorm = vd.normalized();

	ASSERT_DOUBLE_EQ(viNorm.x, 0.0); ASSERT_DOUBLE_EQ(viNorm.y, 0.0); ASSERT_DOUBLE_EQ(viNorm.z, 0.0);
	ASSERT_FLOAT_EQ(vfNorm.x, 0.0f); ASSERT_FLOAT_EQ(vfNorm.y, 0.0f); ASSERT_FLOAT_EQ(vfNorm.z, 0.0f);
	ASSERT_DOUBLE_EQ(vdNorm.x, 0.0); ASSERT_DOUBLE_EQ(vdNorm.y, 0.0); ASSERT_DOUBLE_EQ(vdNorm.z, 0.0);
}
TEST(Vec3Test, NormalizeTiny) {
	SMath::Vec3<float> vf(1e-8f, -1e-8f, 0);
	SMath::Vec3<double> vd(1e-16, -1e-16, 0);

	SMath::Vec3<float> vfNorm = vf.normalized();
	SMath::Vec3<double> vdNorm = vd.normalized();

	ASSERT_FLOAT_EQ(vfNorm.x, 0.0f); ASSERT_FLOAT_EQ(vfNorm.y, 0.0f);
	ASSERT_DOUBLE_EQ(vdNorm.x, 0.0); ASSERT_DOUBLE_EQ(vdNorm.y, 0.0);
}

TEST(Vec3Test, DotProduct) {
	SMath::Vec3<int> vi1(1, 2, 3);
	SMath::Vec3<int> vi2(3, 4, 5);
	SMath::Vec3<float> vf1(1.0f, 2.0f, 3.0f);
	SMath::Vec3<float> vf2(3.0f, 4.0f, 5.0f);
	SMath::Vec3<double> vd1(1.0, 2.0, 3.0);
	SMath::Vec3<double> vd2(3.0, 4.0, 5.0);

	ASSERT_EQ(vi1.dot(vi2), 26);
	ASSERT_FLOAT_EQ(vf1.dot(vf2), 26.0f);
	ASSERT_DOUBLE_EQ(vd1.dot(vd2), 26.0);
}

TEST(Vec3Test, UnaryMinus) {
	SMath::Vec3<int> vi(1, -1, -1);
	SMath::Vec3<float> vf(1.1f, -1.1f, -1.1f);
	SMath::Vec3<double> vd(1.1, -1.1, -1.1);

	SMath::Vec3<int> viNeg = -vi;
	SMath::Vec3<float> vfNeg = -vf;
	SMath::Vec3<double> vdNeg = -vd;

	ASSERT_EQ(viNeg.x, -1); ASSERT_EQ(viNeg.y, 1); ASSERT_EQ(viNeg.z, 1);
	ASSERT_FLOAT_EQ(vfNeg.x, -1.1f); ASSERT_FLOAT_EQ(vfNeg.y, 1.1f); ASSERT_FLOAT_EQ(vfNeg.z, 1.1f);
	ASSERT_DOUBLE_EQ(vdNeg.x, -1.1); ASSERT_DOUBLE_EQ(vdNeg.y, 1.1); ASSERT_DOUBLE_EQ(vdNeg.z, 1.1);
}
