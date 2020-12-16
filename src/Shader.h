#pragma once

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

#include <GL\glew.h>

#include <glm\glm.hpp>
#include <glm\gtc\type_ptr.hpp>

#include "CommonValues.h"

#include "DirectionalLight.h"
#include "PointLight.h"
#include "SpotLight.h"

///class responsible for the shaders
class Shader 
{
public:
	///class constructor
	Shader();

	/// this function is used to create a shader from string data (no external file)
	void CreateFromString(const char* vertexCode, const char* fragmentCode);
	/// this function is used to create a shader from an external file source (vertex and fragment shaders)
	/// \param vertexLocation the path to the vertex shader location
	/// \param fragmentCode the path to the fragment shader location
	void CreateFromFiles(const char* vertexLocation, const char* fragmentLocation);
	/// this function is used to create a shader from an external file source (vertex and fragment shaders)
	/// \param vertexLocation the path to the vertex shader location
	/// \param geometryLocation the path to the geometry shader location
	/// \param fragmentCode the path to the fragment shader location
	void CreateFromFiles(const char* vertexLocation, const char* geometryLocation, const char* fragmentLocation);

	void Validate();

	std::string ReadFile(const char* fileLocation);
	///getter 
	GLuint GetProjectionLocation();
	///getter 
	GLuint GetModelLocation();
	///getter 
	GLuint GetViewLocation();
	///getter 
	GLuint GetAmbientIntensityLocation();
	///getter 
	GLuint GetAmbientColourLocation();
	///getter 
	GLuint GetDiffuseIntensityLocation();
	///getter 
	GLuint GetDirectionLocation();
	///getter 
	GLuint GetSpecularIntensityLocation();
	///getter 
	GLuint GetShininessLocation();
	///getter 
	GLuint GetEyePositionLocation();
	///getter 
	GLuint GetOmniLightPosLocation();
	///getter 
	GLuint GetFarPlaneLocation();

	///setter ( use Directional light)
	void SetDirectionalLight(DirectionalLight* dLight);
	///setter ( use all the point light)
	void SetPointLights(PointLight* pLight, unsigned int lightCount, unsigned int textureUnit, unsigned int offset);
	///setter ( use all the spot light)
	void SetSpotLights(SpotLight* sLight, unsigned int lightCount, unsigned int textureUnit, unsigned int offset);
	///setter ( use texture)
	void SetTexture(GLuint textureUnit);
	void SetDirectionalShadowMap(GLuint textureUnit);
	void SetDirectionalLightTransform(glm::mat4* lTransform);

	void SetOmniLightMatrices(std::vector<glm::mat4> lightMatrices);

	void UseShader();
	void ClearShader();
	///class deconstructor 
	~Shader();

private:
	int pointLightCount;
	int spotLightCount;

	static const int MAX_POINT_LIGHTS=3;
	static const int MAX_SPOT_LIGHTS = 3;

	GLuint shaderID, uniformProjection, uniformModel, uniformView, uniformEyePosition,
		uniformSpecularIntensity, uniformShininess,
		uniformTexture,
		uniformDirectionalLightTransform, uniformDirectionalShadowMap,
		uniformOmniLightPos, uniformFarPlane;

	GLuint uniformLightMatrices[6];

	struct {
		GLuint uniformColour;
		GLuint uniformAmbientIntensity;
		GLuint uniformDiffuseIntensity;

		GLuint uniformDirection;
	} uniformDirectionalLight;

	GLuint uniformPointLightCount;

	struct {
		GLuint uniformColour;
		GLuint uniformAmbientIntensity;
		GLuint uniformDiffuseIntensity;

		GLuint uniformPosition;
		GLuint uniformConstant;
		GLuint uniformLinear;
		GLuint uniformExponent;
	} uniformPointLight[MAX_POINT_LIGHTS];

	GLuint uniformSpotLightCount;

	struct {
		GLuint uniformColour;
		GLuint uniformAmbientIntensity;
		GLuint uniformDiffuseIntensity;

		GLuint uniformPosition;
		GLuint uniformConstant;
		GLuint uniformLinear;
		GLuint uniformExponent;

		GLuint uniformDirection;
		GLuint uniformEdge;
	} uniformSpotLight[MAX_SPOT_LIGHTS];

	struct {
		GLuint uniformShadowMap;
		GLuint uniformFarPlane;
	} uniformOmniShadowMap[MAX_POINT_LIGHTS + MAX_SPOT_LIGHTS];

	void CompileShader(const char* vertexCode, const char* fragmentCode);
	void CompileShader(const char* vertexCode, const char* geometryCode, const char* fragmentCode);
	void AddShader(GLuint theProgram, const char* shaderCode, GLenum shaderType);

	void CompileProgram();
};
