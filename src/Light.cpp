// This project was created following the tutorial: Computer Graphics with Modern OpenGl and C++ 
// Link to the Course: https://www.udemy.com/course/graphics-with-modern-opengl/
// The tutorial provided the theory of the topics and then help on implementation of the discussed topic

#include "Light.h"

Light::Light()
{
	colour = glm::vec3(1.0f, 1.0f, 1.0f);
	ambientIntensity = 1.0f;
	diffuseIntensity = 0.0f;
}

Light::Light(GLfloat shadowWidth, GLfloat shadowHeight, GLfloat red, GLfloat green, GLfloat blue, GLfloat aIntensity, GLfloat dIntensity)
{
	shadowMap = new ShadowMap();
	shadowMap->Init(shadowWidth, shadowHeight);

	colour = glm::vec3(red, green, blue);
	ambientIntensity = aIntensity;
	diffuseIntensity = dIntensity;
}

Light::~Light()
{
}
