#include "maths/Matrix.h"

namespace id {
namespace maths{

Matrix4x4 const Matrix4x4::identity = 
{
    1.f, 0.f, 0.f, 0.f,
    0.f, 1.f, 0.f, 0.f,
    0.f, 0.f, 1.f ,0.f,
    0.f, 0.f, 0.f, 1.f
};

Matrix4x4 const Matrix4x4::voidMatrix = 
{
    0.f, 0.f, 0.f, 0.f,
    0.f, 0.f, 0.f, 0.f,
    0.f, 0.f, 0.f ,0.f,
    0.f, 0.f, 0.f, 0.f
};

Matrix4x4 Matrix4x4::translate(float x, float y, float z)
{
    return{
        1.f, 0.f, 0.f, x,
        0.f, 1.f, 0.f, y,
        0.f, 0.f, 1.f, z,
        0.f, 0.f, 0.f, 1.f
    };
}

Matrix4x4 Matrix4x4::scale(float x, float y, float z)
{
    return{
        x, 0.f, 0.f, 0.f,
        0.f, y, 0.f, 0.f,
        0.f, 0.f, z, 0.f,
        0.f, 0.f, 0.f, 1.f
    };
}

Matrix4x4 Matrix4x4::scale(float s)
{
    return{
        s, 0.f, 0.f, 0.f,
        0.f, s, 0.f, 0.f,
        0.f, 0.f, s, 0.f,
        0.f, 0.f, 0.f, 1.f
    };
}

Matrix4x4 Matrix4x4::rotateX(float angle)
{
    angle = degreesToRadian(angle);
    return{
        1.f, 0.f, 0.f, 0.f,
        0.f, cosf(angle), -sinf(angle), 0.f,
        0.f, sinf(angle), cosf(angle), 0.f,
        0.f, 0.f, 0.f, 1.f
    };
}

Matrix4x4 Matrix4x4::rotateY(float angle)
{
    angle = degreesToRadian(angle);
    return{
        cosf(angle), 0.f, sinf(angle), 0.f,
        0.f, 1.f, 0.f, 0.f,
        -sinf(angle), 0.f, cosf(angle), 0.f,
        0.f, 0.f, 0.f, 1.f
    };
}

Matrix4x4 Matrix4x4::rotateZ(float angle)
{
    angle = degreesToRadian(angle);
    return{
        cosf(angle), -sinf(angle), 0.f, 0.f,
        sinf(angle), cosf(angle), 0.f, 0.f,
        0.f, 0.f, 1.f, 0.f,
        0.f, 0.f, 0.f, 1.f
    };
}

Matrix4x4 Matrix4x4::operator* (Matrix4x4 const& mat)
{
    Matrix4x4 res = Matrix4x4::voidMatrix;

    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            for (int k = 0; k < 4; ++k)
                res.val[i*4+j] += this->val[i*4+k] * mat.val[j+4*k];

    return res;
}

Matrix4x4 Matrix4x4::operator*= (Matrix4x4 const& mat)
{
    return *this = *this * mat;
}

Matrix4x4 Matrix4x4::inverse()
{
    std::swap(val[1], val[4]);
    std::swap(val[6], val[9]);
    std::swap(val[2], val[8]);

    val[3] *= -1.f;
    val[7] *= -1.f;
    val[11] *= -1.f;

    return *this;
}

Matrix4x4 Matrix4x4::perspective(float fovy, float aspect, float near, float far)
{
    float f = 1 / tan(fovy / 2);
    return{
        f / aspect, 0.f, 0.f, 0.f,
        0.f, f, 0.f, 0.f,
        0.f, 0.f, (far + near) / (near - far), (2 * far * near) / (near - far),
        0.f, 0.f, -1.f, 0.f
    }; 
}

void Matrix4x4::showMatrix()
{
    std::cout << this->val[0] << " , " << this->val[1] << " , " << this->val[2] << " , " << this->val[3] << std::endl;
    std::cout << this->val[4] << " , " << this->val[5] << " , " << this->val[6] << " , " << this->val[7] << std::endl;
    std::cout << this->val[8] << " , " << this->val[9] << " , " << this->val[10] << " , " << this->val[11] << std::endl;
    std::cout << this->val[12] << " , " << this->val[13] << " , " << this->val[14] << " , " << this->val[15] << std::endl;
}


}
}
