#pragma once
#include<math.h>
class Vector3
{
public:

	Vector3();

	Vector3(float x,float y = 0 , float z = 0);

	inline float X() { return Value[0]; }

	inline float Y() { return Value[1]; }

	inline float Z() { return Value[2]; }

	inline float R() { return Value[0]; }

	inline float G() { return Value[1]; }

	inline float B() { return Value[2]; }

	static float DotProduct(Vector3 v1, Vector3 v2)
	{
		return v1.Dot(v2);
	}

	inline float Dot(Vector3 vector)
	{
		return X() * vector.X() + Y() * vector.Y() + Z() * vector.Z();
	}

	inline Vector3 Normalize()
	{
		float Lengh = this->Lengh();
		Value[0] = X() / Lengh;
		Value[1] = Y() / Lengh;
		Value[2] = Z() / Lengh;
		return Vector3(Value[0], Value[1], Value[2]);
	}

	inline float Lengh()const
	{
		return sqrt(Value[0] * Value[0] + Value[1] * Value[1] + Value[2] * Value[2]);
	}
	inline float Squared_Lengh()const
	{
		return Value[0] * Value[0] + Value[1] * Value[1] + Value[2] * Value[2];
	}
	inline Vector3 Abs()
	{
		if (Value[0] < 0)
		{
			Value[0] *= -1;
		}
		if (Value[1] < 0)
		{
			Value[1] *= -1;
		}	
		if (Value[2] < 0)
		{
			Value[2] *= -1;
		}
		return *this;
	}
	inline Vector3& operator=(Vector3  vector)
	{
		this->Value[0] = vector.X();
		this->Value[1] = vector.Y();
		this->Value[2] = vector.Z();
		return *this;
	}
	inline bool operator==(Vector3  vector)
	{
		if (this->Value[0] != vector.X())
		{
			return false;
		}
		if (this->Value[1] != vector.Y())
		{
			return false;
		}		
		if (this->Value[2] != vector.Z())
		{
			return false;
		}
		return true;
	}
	inline bool operator!=(Vector3  vector)
	{
		return !(*this == vector);
	
	}
	inline Vector3 operator+(Vector3  vector)
	{
		Vector3 vec(this->Value[0] + vector.X(), this->Value[1] + vector.Y(), this->Value[2] + vector.Z());
		return vec;
	}

	inline Vector3& operator+=(Vector3  vector)
	{
		this->Value[0] += vector.X();
		this->Value[1] += vector.Y();
		this->Value[2] += vector.Z();
		return *this;
	}
	inline Vector3 operator-(Vector3  vector)
	{
		Vector3 vec(this->Value[0] - vector.X(), this->Value[1] - vector.Y(), this->Value[2] - vector.Z());
		return vec;
	}
	inline Vector3& operator-=(Vector3 vector)
	{
		this->Value[0] -= vector.X();
		this->Value[1] -= vector.Y();
		this->Value[2] -= vector.Z();
		return *this;
	}
	inline Vector3 operator*(float Value)
	{
		Vector3 vec(this->Value[0] * Value,this->Value[1] * Value, this->Value[2] * Value);
		return vec;
	}
	inline Vector3 operator*(Vector3 vec)
	{
		return Vector3(this->Value[0] * vec.X(), this->Value[1] * vec.Y(), this->Value[2] * vec.Z());
	}
	inline Vector3& operator*=(float Value)
	{
		this->Value[0] *= Value;
		this->Value[1] *= Value;
		this->Value[2] *= Value;
		return *this;
	}
	inline Vector3 operator/(float Value)
	{
		Vector3 vec(this->X()/Value, this->Y() / Value, this->Z() / Value);
		return vec;
	}
	inline Vector3& operator/=(float Value)
	{
		this->Value[0] /= Value;
		this->Value[1] /= Value;
		this->Value[2] /= Value;
		return *this;
	}
	friend inline Vector3 operator*(float value, Vector3 vec)
	{
		return Vector3(vec.X() * value, vec.Y() * value, vec.Z() *value);
	}
	friend inline Vector3 operator-(float value, Vector3 vec)
	{
		return Vector3(value,value,value) - vec;
	}
private:

	float Value[3];

};
