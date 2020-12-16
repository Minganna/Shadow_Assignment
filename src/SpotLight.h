#pragma once
#include "PointLight.h"

///this class inherets from the Light class, this class is responsable for the SpotLight
class SpotLight :
	public PointLight
{
public:
	SpotLight();
	///class constructor 
	/// \param red the amount of red color in the light
	/// \param green the amount of green color in the light
	/// \param blue the amount of blue color in the light
	/// \param aIntensity the value of ambient intensity
	/// \param dIntensity the value of diffuse intensity
	SpotLight(GLfloat shadowWidth, GLfloat shadowHeight,
		GLfloat near, GLfloat far,
		GLfloat red, GLfloat green, GLfloat blue,
		GLfloat aIntensity, GLfloat dIntensity,
		GLfloat xPos, GLfloat yPos, GLfloat zPos,
		GLfloat xDir, GLfloat yDir, GLfloat zDir,
		GLfloat con, GLfloat lin, GLfloat exp,
		GLfloat edg);

	///this function is used to use the light on the scene 
	void UseLight(GLuint ambientIntensityLocation, GLuint ambientColourLocation,
		GLuint diffuseIntensityLocation, GLuint positionLocation, GLuint directionLocation,
		GLuint constantLocation, GLuint linearLocation, GLuint exponentLocation,
		GLuint edgeLocation);

	///attach a spotlight to the camera to use as a torch
	void SetFlash(glm::vec3 pos, glm::vec3 dir);

	///turn on/off the torch attached to the camera
	void Toggle() { isOn = !isOn; }
	///class deconstructor 
	~SpotLight();

private:
	glm::vec3 direction;

	GLfloat edge, procEdge;

	bool isOn;
};
