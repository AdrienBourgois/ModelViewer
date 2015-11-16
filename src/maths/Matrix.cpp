#include "maths/Matrix.h"
#include "maths/tools.h"
#include <cmath>
#include <utility>
#include <iostream>

namespace id 
{
	namespace maths
	{

		float cotan ( float a)
		{
			return (1.f/ std::tan(a));
		}

		Matrix4x4 const Matrix4x4::identity = 
		{
			    1.f, 0.f, 0.f, 0.f,
			    0.f, 1.f, 0.f, 0.f,
			    0.f, 0.f, 1.f ,0.f,
			    0.f, 0.f, 0.f, 1.f
		};

		Matrix4x4 Matrix4x4::perspective(float fovy, float aspect, float near, float far)
		{
			float f = cotan(fovy / 2.f );
			float d = (far+near)/(near-far);
			float g = (2.f*far*near)/(near-far);
			return{
				(f/aspect),0.f,0.f,0.f,
				0.f, f, 0.f, 0.f,
				0.f, 0.f, d, g,
				0.f, 0.f, -1.f, 0.f	
			      };
		}

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
			angle = rad(angle);
				return{
				        1.f, 0.f, 0.f, 0.f,
				        0.f, std::cos(angle), -std::sin(angle), 0.f,
				        0.f, std::sin(angle), std::cos(angle), 0.f,
				        0.f, 0.f, 0.f, 1.f
			    	      };
		}

		Matrix4x4 Matrix4x4::rotateY(float angle)
		{
			angle = rad(angle);
    				return{
        				std::cos(angle), 0.f,std::sin(angle) , 0.f,
					0.f, 1.f, 0.f, 0.f,	
					-std::sin(angle), 0.f, std::cos(angle), 0.f,
					0.f, 0.f, 0.f, 1.f
				      };
		}

		Matrix4x4 Matrix4x4::rotateZ(float angle)
		{
			angle = rad(angle);
    				return{
				        std::cos(angle), -std::sin(angle), 0.f, 0.f,
				        std::sin(angle), std::cos(angle), 0.f, 0.f,
				        0.f, 0.f, 1.f, 0.f,
				        0.f, 0.f, 0.f, 1.f
				      };
		}

		auto  Matrix4x4::inverse() -> Matrix4x4
		{
			Matrix4x4 inv = *this;

			for ( int i = 3 ; i < 12 ; i += 4)
				inv.val[i] *= -1;
	
			std::swap(inv.val[1], inv.val[4]);
			std::swap(inv.val[2], inv.val[8]);
			std::swap(inv.val[6], inv.val[9]);
			return inv;
		}

		Matrix4x4 Matrix4x4::operator* (Matrix4x4 const& mat) const
		{
			    Matrix4x4 res = 
				{ 0.f, 0.f, 0.f, 0.f,
				  0.f, 0.f, 0.f, 0.f,
				  0.f, 0.f, 0.f, 0.f,
			          0.f, 0.f, 0.f, 0.f};

    				for (int i = 0; i < 4; ++i)
    				        for (int j = 0; j < 4; ++j)
            					for (int k = 0; k < 4; ++k)
                					res.val[4*i+j] += this->val[4*i+k] * mat.val[4*k+j];
	    
				return res;
		}

		Matrix4x4 Matrix4x4::operator*= (Matrix4x4 const& mat)
		{
		    *this = *this * mat;
			return *this;
		}
	}
}
