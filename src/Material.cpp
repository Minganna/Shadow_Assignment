// This project was created with the help of the following tutorial: Computer Graphics with Modern OpenGl and C++ 
// Link to the Course: https://www.udemy.com/course/graphics-with-modern-opengl/
// The tutorial provided the theory of the topics and then help on implementation of the discussed topic

#include "Material.h"

Material::Material()
{
	specularIntensity = 0.0f;
	shininess = 0.0f;
}

Material::Material(GLfloat sIntensity, GLfloat shine)
{
	specularIntensity = sIntensity;
	shininess = shine;
}

void Material::UseMaterial(GLuint specularIntensityLocation, GLuint shininessLocation)
{
	glUniform1f(specularIntensityLocation, specularIntensity);
	glUniform1f(shininessLocation, shininess);
}

Material::~Material()
{
}
