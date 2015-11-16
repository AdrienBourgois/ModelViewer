#ifndef __MATHS_MATRIX_INCLUDE__
#define __MATHS_MATRIX_INCLUDE__

namespace id {
namespace maths {

struct Matrix3x3
{
};

struct Matrix4x4
{
    float val[16];

    static Matrix4x4 const identity;

    static Matrix4x4 perspective(float fovy, float aspect, float near, float far);
    static Matrix4x4 translate(float x, float y, float z);
    static Matrix4x4 scale(float x, float y, float z);
    static Matrix4x4 scale(float s);
    static Matrix4x4 rotateX(float angle);
    static Matrix4x4 rotateY(float angle);
    static Matrix4x4 rotateZ(float angle);

    auto inverse() -> Matrix4x4;

    Matrix4x4 operator* (Matrix4x4 const& mat) const;
    Matrix4x4 operator*= (Matrix4x4 const& mat);

    //Vector3 getPosition() const;
};

float cotan ( float);

typedef Matrix4x4 Matrix4;
typedef Matrix3x3 Matrix3;

}// namespace maths
}// namespace id

#endif //__MATHS_MATRIX_INCLUDE__
