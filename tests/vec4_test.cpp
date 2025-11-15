#include <gtest/gtest.h>
#include "starlet-math/vec4.hpp"	

namespace SMath = Starlet::Math;

TEST(Vec4Test, DefaultConstructor) {
	SMath::Vec4<int> vi;
	SMath::Vec4<float> vf;
	SMath::Vec4<double> vd;

	ASSERT_EQ(vi.x, 0); ASSERT_EQ(vi.y, 0); ASSERT_EQ(vi.z, 0); ASSERT_EQ(vi.w, 0);
	ASSERT_FLOAT_EQ(vf.x, 0.0f); ASSERT_FLOAT_EQ(vf.y, 0.0f); ASSERT_FLOAT_EQ(vf.z, 0.0f); ASSERT_FLOAT_EQ(vf.w, 0.0f);
	ASSERT_DOUBLE_EQ(vd.x, 0.0); ASSERT_DOUBLE_EQ(vd.y, 0.0); ASSERT_DOUBLE_EQ(vd.z, 0.0); ASSERT_DOUBLE_EQ(vd.w, 0.0);
}
TEST(Vec4Test, SingleParamConstructor) {
	SMath::Vec4<int> vi(1);
	SMath::Vec4<float> vf(1.1f);
	SMath::Vec4<double> vd(1.1);

	ASSERT_EQ(vi.x, 1); ASSERT_EQ(vi.y, 1); ASSERT_EQ(vi.z, 1); ASSERT_EQ(vi.w, 1);
	ASSERT_FLOAT_EQ(vf.x, 1.1f); ASSERT_FLOAT_EQ(vf.y, 1.1f); ASSERT_FLOAT_EQ(vf.z, 1.1f); ASSERT_FLOAT_EQ(vf.w, 1.1f);
	ASSERT_DOUBLE_EQ(vd.x, 1.1); ASSERT_DOUBLE_EQ(vd.y, 1.1); ASSERT_DOUBLE_EQ(vd.z, 1.1); ASSERT_DOUBLE_EQ(vd.w, 1.1);
}
TEST(Vec4Test, ParameterConstructor) {
	SMath::Vec4<int> vi(1, 1, -1, -1);
	SMath::Vec4<float> vf(1.1f, 1.1f, -1.1f, -1.1f);
	SMath::Vec4<double> vd(1.1, 1.1, -1.1, -1.1);

	ASSERT_EQ(vi.x, 1); ASSERT_EQ(vi.y, 1); ASSERT_EQ(vi.z, -1); ASSERT_EQ(vi.w, -1);
	ASSERT_FLOAT_EQ(vf.x, 1.1f); ASSERT_FLOAT_EQ(vf.y, 1.1f); ASSERT_FLOAT_EQ(vf.z, -1.1f); ASSERT_FLOAT_EQ(vf.w, -1.1f);
	ASSERT_DOUBLE_EQ(vd.x, 1.1); ASSERT_DOUBLE_EQ(vd.y, 1.1); ASSERT_DOUBLE_EQ(vd.z, -1.1); ASSERT_DOUBLE_EQ(vd.w, -1.1);
}
TEST(Vec4Test, CopyConstructor) {
	SMath::Vec4<int> vi1(1, 1, -1, -1);
	SMath::Vec4<float> vf1(1.1f, 1.1f, -1.1f, -1.1f);
	SMath::Vec4<double> vd1(1.1, 1.1, -1.1, -1.1);

	SMath::Vec4<int> vi2(vi1);
	SMath::Vec4<float> vf2(vf1);
	SMath::Vec4<double> vd2(vd1);

	ASSERT_EQ(vi2.x, 1); ASSERT_EQ(vi2.y, 1); ASSERT_EQ(vi2.z, -1); ASSERT_EQ(vi2.w, -1);
	ASSERT_FLOAT_EQ(vf2.x, 1.1f); ASSERT_FLOAT_EQ(vf2.y, 1.1f); ASSERT_FLOAT_EQ(vf2.z, -1.1f); ASSERT_FLOAT_EQ(vf2.w, -1.1f);
	ASSERT_DOUBLE_EQ(vd2.x, 1.1); ASSERT_DOUBLE_EQ(vd2.y, 1.1); ASSERT_DOUBLE_EQ(vd2.z, -1.1); ASSERT_DOUBLE_EQ(vd2.w, -1.1);
}

TEST(Vec4Test, Negative) {
	SMath::Vec4<int> vi(-1, -2, -3, -4), vi2(-5, -6, -7, -8);
	SMath::Vec4<float> vf(-1.5f, -2.5f, -3.5f, -4.5f), vf2(5.5f, 6.5f, 7.5f, 8.5f);
	SMath::Vec4<double> vd(-1.5, -2.5, -3.5, -4.5), vd2(-5.5, -6.5, -7.5, -8.5);

	SMath::Vec4<int> vi3 = vi * vi2;
	SMath::Vec4<float> vf3 = vf - vf2;
	SMath::Vec4<double> vd3 = vd + vd2;

	ASSERT_EQ(vi3.x, 5); ASSERT_EQ(vi3.y, 12); ASSERT_EQ(vi3.z, 21); ASSERT_EQ(vi3.w, 32);
	ASSERT_FLOAT_EQ(vf3.x, -7.0f); ASSERT_FLOAT_EQ(vf3.y, -9.0f); ASSERT_FLOAT_EQ(vf3.z, -11.0f); ASSERT_FLOAT_EQ(vf3.w, -13.0f);
	ASSERT_DOUBLE_EQ(vd3.x, -7.0); ASSERT_DOUBLE_EQ(vd3.y, -9.0); ASSERT_DOUBLE_EQ(vd3.z, -11.0); ASSERT_DOUBLE_EQ(vd3.w, -13.0);
}

TEST(Vec4Test, Assignment) {
	SMath::Vec4<int> vi1(1, 1, 1, 1), vi2;
	SMath::Vec4<float> vf1(1.1f, 1.1f, 1.1f, 1.1f), vf2;
	SMath::Vec4<double> vd1(1.1, 1.1, 1.1, 1.1), vd2;

	vi2 = vi1;
	vf2 = vf1;
	vd2 = vd1;

	ASSERT_EQ(vi2.x, 1); ASSERT_EQ(vi2.y, 1); ASSERT_EQ(vi2.z, 1); ASSERT_EQ(vi2.w, 1);
	ASSERT_FLOAT_EQ(vf2.x, 1.1f); ASSERT_FLOAT_EQ(vf2.y, 1.1f); ASSERT_FLOAT_EQ(vf2.z, 1.1f); ASSERT_FLOAT_EQ(vf2.w, 1.1f);
	ASSERT_DOUBLE_EQ(vd2.x, 1.1); ASSERT_DOUBLE_EQ(vd2.y, 1.1); ASSERT_DOUBLE_EQ(vd2.z, 1.1); ASSERT_DOUBLE_EQ(vd2.w, 1.1);
}
TEST(Vec4Test, SelfAssignment) {
	SMath::Vec4<int> vi(1, 1, 1, 1);
	SMath::Vec4<float> vf(1.1f, 1.1f, 1.1f, 1.1f);
	SMath::Vec4<double> vd(1.1, 1.1, 1.1, 1.1);

	vi = vi;
	vf = vf;
	vd = vd;

	ASSERT_EQ(vi.x, 1); ASSERT_EQ(vi.y, 1); ASSERT_EQ(vi.z, 1); ASSERT_EQ(vi.w, 1);
	ASSERT_FLOAT_EQ(vf.x, 1.1f); ASSERT_FLOAT_EQ(vf.y, 1.1f); ASSERT_FLOAT_EQ(vf.z, 1.1f); ASSERT_FLOAT_EQ(vf.w, 1.1f);
	ASSERT_DOUBLE_EQ(vd.x, 1.1); ASSERT_DOUBLE_EQ(vd.y, 1.1); ASSERT_DOUBLE_EQ(vd.z, 1.1); ASSERT_DOUBLE_EQ(vd.w, 1.1);
}

TEST(Vec4Test, AdditionAndSubtraction) {
	SMath::Vec4<int> vi1(1, 2, 3, 4), vi2(5, 6, 7, 8);
	SMath::Vec4<float> vf1(1.0f, 2.0f, 3.0f, 4.0f), vf2(5.0f, 6.0f, 7.0f, 8.0f);
	SMath::Vec4<double> vd1(1.0, 2.0, 3.0, 4.0), vd2(5.0, 6.0, 7.0, 8.0);

	SMath::Vec4<int> viAdd = vi1 + vi2;
	SMath::Vec4<int> viSub = vi1 - vi2;
	SMath::Vec4<float> vfAdd = vf1 + vf2;
	SMath::Vec4<float> vfSub = vf1 - vf2;
	SMath::Vec4<double> vdAdd = vd1 + vd2;
	SMath::Vec4<double> vdSub = vd1 - vd2;

	ASSERT_EQ(viAdd.x, 6); ASSERT_EQ(viAdd.y, 8); ASSERT_EQ(viAdd.z, 10); ASSERT_EQ(viAdd.w, 12);
	ASSERT_EQ(viSub.x, -4); ASSERT_EQ(viSub.y, -4); ASSERT_EQ(viSub.z, -4); ASSERT_EQ(viSub.w, -4);
	ASSERT_FLOAT_EQ(vfAdd.x, 6.0f); ASSERT_FLOAT_EQ(vfAdd.y, 8.0f); ASSERT_FLOAT_EQ(vfAdd.z, 10.0f); ASSERT_FLOAT_EQ(vfAdd.w, 12.0f);
	ASSERT_FLOAT_EQ(vfSub.x, -4.0f); ASSERT_FLOAT_EQ(vfSub.y, -4.0f); ASSERT_FLOAT_EQ(vfSub.z, -4.0f); ASSERT_FLOAT_EQ(vfSub.w, -4.0f);
	ASSERT_DOUBLE_EQ(vdAdd.x, 6.0); ASSERT_DOUBLE_EQ(vdAdd.y, 8.0); ASSERT_DOUBLE_EQ(vdAdd.z, 10.0); ASSERT_DOUBLE_EQ(vdAdd.w, 12.0);
	ASSERT_DOUBLE_EQ(vdSub.x, -4.0); ASSERT_DOUBLE_EQ(vdSub.y, -4.0); ASSERT_DOUBLE_EQ(vdSub.z, -4.0); ASSERT_DOUBLE_EQ(vdSub.w, -4.0);
}
TEST(Vec4Test, MultiplicationAndDivision) {
	SMath::Vec4<int> vi(1, 2, 3, 4);
	SMath::Vec4<float> vf(1.0f, 2.0f, 3.0f, 4.0f);
	SMath::Vec4<double> vd(1.0, 2.0, 3.0, 4.0);

	SMath::Vec4<int> viMul = vi * 3;
	SMath::Vec4<int> viDiv = vi / 2;
	SMath::Vec4<float> vfMul = vf * 2.0f;
	SMath::Vec4<float> vfDiv = vf / 0.5f;
	SMath::Vec4<double> vdMul = vd * 2.0;
	SMath::Vec4<double> vdDiv = vd / 2.0;

	ASSERT_EQ(viMul.x, 3);  ASSERT_EQ(viMul.y, 6);  ASSERT_EQ(viMul.z, 9);  ASSERT_EQ(viMul.w, 12);
	ASSERT_EQ(viDiv.x, 0);  ASSERT_EQ(viDiv.y, 1);  ASSERT_EQ(viDiv.z, 1);  ASSERT_EQ(viDiv.w, 2);
	ASSERT_FLOAT_EQ(vfMul.x, 2.0f);  ASSERT_FLOAT_EQ(vfMul.y, 4.0f);  ASSERT_FLOAT_EQ(vfMul.z, 6.0f);  ASSERT_FLOAT_EQ(vfMul.w, 8.0f);
	ASSERT_FLOAT_EQ(vfDiv.x, 2.0f);  ASSERT_FLOAT_EQ(vfDiv.y, 4.0f);  ASSERT_FLOAT_EQ(vfDiv.z, 6.0f);  ASSERT_FLOAT_EQ(vfDiv.w, 8.0f);
	ASSERT_DOUBLE_EQ(vdMul.x, 2.0);  ASSERT_DOUBLE_EQ(vdMul.y, 4.0);  ASSERT_DOUBLE_EQ(vdMul.z, 6.0);  ASSERT_DOUBLE_EQ(vdMul.w, 8.0);
	ASSERT_DOUBLE_EQ(vdDiv.x, 0.5);  ASSERT_DOUBLE_EQ(vdDiv.y, 1.0);  ASSERT_DOUBLE_EQ(vdDiv.z, 1.5);  ASSERT_DOUBLE_EQ(vdDiv.w, 2.0);
}
TEST(Vec4Test, ComponentWiseMultiplicationAndDivision) {
	SMath::Vec4<int> vi1(2, 3, 4, 5), vi2(6, 7, 8, 9);
	SMath::Vec4<float> vf1(1.5f, 2.5f, 3.5f, 4.5f), vf2(2.0f, 3.0f, 4.0f, 5.0f);
	SMath::Vec4<double> vd1(1.0, 2.0, 3.0, 4.0), vd2(2.0, 3.0, 4.0, 5.0);

	SMath::Vec4<int> viMul = vi1 * vi2;
	SMath::Vec4<int> viDiv = vi2 / vi1;
	SMath::Vec4<float> vfMul = vf1 * vf2;
	SMath::Vec4<float> vfDiv = vf1 / vf2;
	SMath::Vec4<double> vdMul = vd1 * vd2;
	SMath::Vec4<double> vdDiv = vd1 / vd2;

	ASSERT_EQ(viMul.x, 12); ASSERT_EQ(viMul.y, 21); ASSERT_EQ(viMul.z, 32); ASSERT_EQ(viMul.w, 45);
	ASSERT_EQ(viDiv.x, 3);  ASSERT_EQ(viDiv.y, 2);  ASSERT_EQ(viDiv.z, 2); ASSERT_EQ(viDiv.w, 1);
	ASSERT_FLOAT_EQ(vfMul.x, 3.0f); ASSERT_FLOAT_EQ(vfMul.y, 7.5f);  ASSERT_FLOAT_EQ(vfMul.z, 14.0f); ASSERT_FLOAT_EQ(vfMul.w, 22.5f);
	ASSERT_FLOAT_EQ(vfDiv.x, 0.75f); ASSERT_FLOAT_EQ(vfDiv.y, 2.5f / 3.0f); ASSERT_FLOAT_EQ(vfDiv.z, 3.5f / 4.0f); ASSERT_FLOAT_EQ(vfDiv.w, 4.5f / 5.0f);
	ASSERT_DOUBLE_EQ(vdMul.x, 2.0); ASSERT_DOUBLE_EQ(vdMul.y, 6.0); ASSERT_DOUBLE_EQ(vdMul.z, 12.0); ASSERT_DOUBLE_EQ(vdMul.w, 20.0);
	ASSERT_DOUBLE_EQ(vdDiv.x, 0.5); ASSERT_DOUBLE_EQ(vdDiv.y, 2.0 / 3.0); ASSERT_DOUBLE_EQ(vdDiv.z, 0.75); ASSERT_DOUBLE_EQ(vdDiv.w, 0.8);
}

TEST(Vec4Test, Compound) {
	SMath::Vec4<int> vi(1, 2, 3, 4);
	SMath::Vec4<float> vf(1.0f, 2.0f, 3.0f, 4.0f);
	SMath::Vec4<double> vd(1.0, 2.0, 3.0, 4.0);

	vi += SMath::Vec4<int>(3, 4, 5, 6);
	vf += SMath::Vec4<float>(3.0f, 4.0f, 5.0f, 6.0f);
	vd += SMath::Vec4<double>(3.0, 4.0, 5.0, 6.0);

	ASSERT_EQ(vi.x, 4); ASSERT_EQ(vi.y, 6); ASSERT_EQ(vi.z, 8); ASSERT_EQ(vi.w, 10);
	ASSERT_FLOAT_EQ(vf.x, 4.0f); ASSERT_FLOAT_EQ(vf.y, 6.0f); ASSERT_FLOAT_EQ(vf.z, 8.0f); ASSERT_FLOAT_EQ(vf.w, 10.0f);
	ASSERT_DOUBLE_EQ(vd.x, 4.0); ASSERT_DOUBLE_EQ(vd.y, 6.0); ASSERT_DOUBLE_EQ(vd.z, 8.0); ASSERT_DOUBLE_EQ(vd.w, 10.0);

	vi -= SMath::Vec4<int>(3, 4, 5, 6);
	vf -= SMath::Vec4<float>(3.0f, 4.0f, 5.0f, 6.0f);
	vd -= SMath::Vec4<double>(3.0, 4.0, 5.0, 6.0);
	ASSERT_EQ(vi.x, 1); ASSERT_EQ(vi.y, 2); ASSERT_EQ(vi.z, 3); ASSERT_EQ(vi.w, 4);
	ASSERT_FLOAT_EQ(vf.x, 1.0f); ASSERT_FLOAT_EQ(vf.y, 2.0f); ASSERT_FLOAT_EQ(vf.z, 3.0f); ASSERT_FLOAT_EQ(vf.w, 4.0f);
	ASSERT_DOUBLE_EQ(vd.x, 1.0); ASSERT_DOUBLE_EQ(vd.y, 2.0); ASSERT_DOUBLE_EQ(vd.z, 3.0); ASSERT_DOUBLE_EQ(vd.w, 4.0);

	vi *= 3;
	vf *= 3.0f;
	vd *= 3.0;

	ASSERT_EQ(vi.x, 3); ASSERT_EQ(vi.y, 6); ASSERT_EQ(vi.z, 9); ASSERT_EQ(vi.w, 12);
	ASSERT_FLOAT_EQ(vf.x, 3.0f); ASSERT_FLOAT_EQ(vf.y, 6.0f); ASSERT_FLOAT_EQ(vf.z, 9.0f); ASSERT_FLOAT_EQ(vf.w, 12.0f);
	ASSERT_DOUBLE_EQ(vd.x, 3.0); ASSERT_DOUBLE_EQ(vd.y, 6.0); ASSERT_DOUBLE_EQ(vd.z, 9.0); ASSERT_DOUBLE_EQ(vd.w, 12.0);

	vi /= 3;
	vf /= 3.0f;
	vd /= 3.0;

	ASSERT_EQ(vi.x, 1); ASSERT_EQ(vi.y, 2); ASSERT_EQ(vi.z, 3); ASSERT_EQ(vi.w, 4);
	ASSERT_FLOAT_EQ(vf.x, 1.0f); ASSERT_FLOAT_EQ(vf.y, 2.0f); ASSERT_FLOAT_EQ(vf.z, 3.0f); ASSERT_FLOAT_EQ(vf.w, 4.0f);
	ASSERT_DOUBLE_EQ(vd.x, 1.0); ASSERT_DOUBLE_EQ(vd.y, 2.0); ASSERT_DOUBLE_EQ(vd.z, 3.0); ASSERT_DOUBLE_EQ(vd.w, 4.0);
}

TEST(Vec4Test, Comparison) {
	SMath::Vec4<int> vi1(1, 2, 3, 4), vi2(1, 2, 3, 4), vi3(3, 4, 5, 6);
	SMath::Vec4<float> vf1(1.0f, 2.0f, 3.0f, 4.0f), vf2(1.0f, 2.0f, 3.0f, 4.0f), vf3(3.0f, 4.0f, 5.0f, 6.0f);
	SMath::Vec4<double> vd1(1.0, 2.0, 3.0, 4.0), vd2(1.0, 2.0, 3.0, 4.0), vd3(3.0, 4.0, 5.0, 6.0);

	ASSERT_TRUE(vi1 == vi2); ASSERT_FALSE(vi1 == vi3);
	ASSERT_TRUE(vf1 == vf2); ASSERT_FALSE(vf1 == vf3);
	ASSERT_TRUE(vd1 == vd2); ASSERT_FALSE(vd1 == vd3);

	ASSERT_FALSE(vi1 != vi2); ASSERT_TRUE(vi1 != vi3);
	ASSERT_FALSE(vf1 != vf2); ASSERT_TRUE(vf1 != vf3);
	ASSERT_FALSE(vd1 != vd2); ASSERT_TRUE(vd1 != vd3);
}

TEST(Vec4Test, Length) {
	SMath::Vec4<int> vi(3, 4, 5, 6);
	SMath::Vec4<float> vf(3.0f, 4.0f, 5.0f, 6.0f);
	SMath::Vec4<double> vd(3.0, 4.0, 5.0, 6.0);

	ASSERT_FLOAT_EQ(vi.length(), std::sqrt(86.0f));
	ASSERT_FLOAT_EQ(vf.length(), std::sqrt(86.0f));
	ASSERT_DOUBLE_EQ(vd.length(), std::sqrt(86.0));
}
TEST(Vec4Test, LengthSquared) {
	SMath::Vec4<int> vi(3, 4, 5, 6);
	SMath::Vec4<float> vf(3.0f, 4.0f, 5.0f, 6.0f);
	SMath::Vec4<double> vd(3.0, 4.0, 5.0, 6.0);

	ASSERT_EQ(vi.lengthSquared(), 86);
	ASSERT_FLOAT_EQ(vf.lengthSquared(), 86.0f);
	ASSERT_DOUBLE_EQ(vd.lengthSquared(), 86.0);
}

TEST(Vec4Test, Normalize) {
	SMath::Vec4<int> vi(1, 1, 1, 1);
	SMath::Vec4<float> vf(1.0f, 1.0f, 1.0f, 1.0f);
	SMath::Vec4<double> vd(1.0, 1.0, 1.0, 1.0);

	SMath::Vec4<double> viNorm = vi.normalized();
	SMath::Vec4<float> vfNorm = vf.normalized();
	SMath::Vec4<double> vdNorm = vd.normalized();

	ASSERT_DOUBLE_EQ(viNorm.x, 0.5); ASSERT_DOUBLE_EQ(viNorm.y, 0.5); ASSERT_DOUBLE_EQ(viNorm.z, 0.5); ASSERT_DOUBLE_EQ(viNorm.w, 0.5);
	ASSERT_FLOAT_EQ(vfNorm.x, 0.5f); ASSERT_FLOAT_EQ(vfNorm.y, 0.5f); ASSERT_FLOAT_EQ(vfNorm.z, 0.5f); ASSERT_FLOAT_EQ(vfNorm.w, 0.5f);
	ASSERT_DOUBLE_EQ(vdNorm.x, 0.5); ASSERT_DOUBLE_EQ(vdNorm.y, 0.5); ASSERT_DOUBLE_EQ(vdNorm.z, 0.5); ASSERT_DOUBLE_EQ(vdNorm.w, 0.5);
}
TEST(Vec4Test, NormalizeZero) {
	SMath::Vec4<int> vi(0, 0, 0, 0);
	SMath::Vec4<float> vf(0.0f, 0.0f, 0.0f, 0.0f);
	SMath::Vec4<double> vd(0.0, 0.0, 0.0, 0.0);

	SMath::Vec4<double> viNorm = vi.normalized();
	SMath::Vec4<float> vfNorm = vf.normalized();
	SMath::Vec4<double> vdNorm = vd.normalized();

	ASSERT_DOUBLE_EQ(viNorm.x, 0.0); ASSERT_DOUBLE_EQ(viNorm.y, 0.0); ASSERT_DOUBLE_EQ(viNorm.z, 0.0); ASSERT_DOUBLE_EQ(viNorm.w, 0.0);
	ASSERT_FLOAT_EQ(vfNorm.x, 0.0f); ASSERT_FLOAT_EQ(vfNorm.y, 0.0f); ASSERT_FLOAT_EQ(vfNorm.z, 0.0f); ASSERT_FLOAT_EQ(vfNorm.w, 0.0f);
	ASSERT_DOUBLE_EQ(vdNorm.x, 0.0); ASSERT_DOUBLE_EQ(vdNorm.y, 0.0); ASSERT_DOUBLE_EQ(vdNorm.z, 0.0); ASSERT_DOUBLE_EQ(vdNorm.w, 0.0);
}
TEST(Vec4Test, NormalizeTiny) {
	SMath::Vec4<float> vf(1e-8f, -1e-8f, 0.0f, 0.0f);
	SMath::Vec4<double> vd(1e-16, -1e-16, 0.0, 0.0);

	SMath::Vec4<float> vfNorm = vf.normalized();
	SMath::Vec4<double> vdNorm = vd.normalized();

	ASSERT_FLOAT_EQ(vfNorm.x, 0.0f); ASSERT_FLOAT_EQ(vfNorm.y, 0.0f); ASSERT_FLOAT_EQ(vfNorm.z, 0.0f); ASSERT_FLOAT_EQ(vfNorm.w, 0.0f);
	ASSERT_DOUBLE_EQ(vdNorm.x, 0.0); ASSERT_DOUBLE_EQ(vdNorm.y, 0.0); ASSERT_DOUBLE_EQ(vdNorm.z, 0.0); ASSERT_DOUBLE_EQ(vdNorm.w, 0.0);
}

TEST(Vec4Test, DotProduct) {
	SMath::Vec4<int> vi1(1, 2, 3, 4);
	SMath::Vec4<int> vi2(3, 4, 5, 6);
	SMath::Vec4<float> vf1(1.0f, 2.0f, 3.0f, 4.0f);
	SMath::Vec4<float> vf2(3.0f, 4.0f, 5.0f, 6.0f);
	SMath::Vec4<double> vd1(1.0, 2.0, 3.0, 4.0);
	SMath::Vec4<double> vd2(3.0, 4.0, 5.0, 6.0);

	ASSERT_EQ(vi1.dot(vi2), 50);
	ASSERT_FLOAT_EQ(vf1.dot(vf2), 50.0f);
	ASSERT_DOUBLE_EQ(vd1.dot(vd2), 50.0);
}

TEST(Vec4Test, UnaryMinus) {
	SMath::Vec4<int> vi(1, 1, -1, -1);
	SMath::Vec4<float> vf(1.1f, 1.1f, -1.1f, -1.1f);
	SMath::Vec4<double> vd(1.1, 1.1, -1.1, -1.1);

	SMath::Vec4<int> viNeg = -vi;
	SMath::Vec4<float> vfNeg = -vf;
	SMath::Vec4<double> vdNeg = -vd;

	ASSERT_EQ(viNeg.x, -1); ASSERT_EQ(viNeg.y, -1); ASSERT_EQ(viNeg.z, 1); ASSERT_EQ(viNeg.w, 1);
	ASSERT_FLOAT_EQ(vfNeg.x, -1.1f); ASSERT_FLOAT_EQ(vfNeg.y, -1.1f); ASSERT_FLOAT_EQ(vfNeg.z, 1.1f); ASSERT_FLOAT_EQ(vfNeg.w, 1.1f);
	ASSERT_DOUBLE_EQ(vdNeg.x, -1.1); ASSERT_DOUBLE_EQ(vdNeg.y, -1.1); ASSERT_DOUBLE_EQ(vdNeg.z, 1.1); ASSERT_DOUBLE_EQ(vdNeg.w, 1.1);
}
