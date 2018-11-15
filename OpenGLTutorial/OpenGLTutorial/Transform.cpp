#include "Transform.h"
#include <iostream>

Transform::Transform(const vec3& position, const vec3& rotation, const vec3& scale)
{
	std::cout << addressof(position) << std::endl;
	std::cout << addressof(Position) << std::endl;
	Position = position;
	Rotation = rotation;
	Scale = scale;
}

 mat4 Transform::GetModel() const
{
	mat4 posMatrix = translate(Position);
	mat4 rotationXMatrix = rotate(Rotation.x, vec3(1, 0, 0));
	mat4 rotationYMatrix = rotate(Rotation.y, vec3(0, 1, 0));
	mat4 rotationZMatrix = rotate(Rotation.z, vec3(0, 0, 1));
	mat4 scaleMatrix = scale(Scale);

	mat4 rotationMatrix = rotationZMatrix * rotationYMatrix * rotationXMatrix;

	return posMatrix * rotationMatrix * scaleMatrix;
}
