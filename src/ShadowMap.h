///this class is responsible for the directional shadow map
#pragma once

#include <stdio.h>

#include <GL\glew.h>

class ShadowMap
{
public:
	///class constructor
	ShadowMap();

	/// this function is used to initialise the shadow map 
	virtual bool Init(GLuint width, GLuint height);

	virtual void Write();

	virtual void Read(GLenum textureUnit);

	///getter for the shadow width
	GLuint GetShadowWidth() { return shadowWidth; }
	///getter for the shadow height
	GLuint GetShadowHeight() { return shadowHeight; }
	///class deconstructor 
	~ShadowMap();

protected:
	GLuint FBO, shadowMap;
	GLuint shadowWidth, shadowHeight;
};
