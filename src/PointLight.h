#pragma once
#include <vector>

#include "Light.h"
#include "OmniShadowMap.h"
///this class inherets from the Light class, this class is responsable for the PointLight 
class PointLight :
	public Light
{
public:
	PointLight();
	///class constructor
	/// \param red the amount of red color in the light
	/// \param green the amount of green color in the light
	/// \param blue the amount of blue color in the light
	/// \param aIntensity the value of ambient intensity
	/// \param dIntensity the value of diffuse intensity
	PointLight(GLfloat shadowWidth, GLfloat shadowHeight,
		GLfloat near, GLfloat far,
		GLfloat red, GLfloat green, GLfloat blue,
		GLfloat aIntensity, GLfloat dIntensity,
		GLfloat xPos, GLfloat yPos, GLfloat zPos,
		GLfloat con, GLfloat lin, GLfloat exp);

	///this function is used to use the light on the scene 
	void UseLight(GLuint ambientIntensityLocation, GLuint ambientColourLocation,
		GLuint diffuseIntensityLocation, GLuint positionLocation,
		GLuint constantLocation, GLuint linearLocation, GLuint exponentLocation);

	std::vector<glm::mat4> CalculateLightTransform();

	glm::vec3 GetPosition();
	GLfloat GetFarPlane();

	///class deconstructor 
	~PointLight();

protected:
	glm::vec3 position;

	GLfloat constant, linear, exponent;
	GLfloat farPlane;
};
