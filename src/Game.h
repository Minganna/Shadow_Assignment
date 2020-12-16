//main class of the shadow demonstration program.
#pragma once

#include "mainHeader.h"
#include <chrono>
#include<ctime>


class Game
{
public:

	Game();

	//this function is used to calculate the normals value on a object created by the function CreateObjects()
	void calcAverageNormals(unsigned int* indices, unsigned int indiceCount, GLfloat* vertices, unsigned int verticeCount,
		unsigned int vLength, unsigned int normalOffset);

	//This class is used to create a primitive object. (triangles,piramids)
	void CreateObjects();
	//This function is used to find the path of the shaders and create shaders from files
	void CreateShaders();
	void RenderScene();
	//function used to generate shadow map from the light sources on one direction (one texture created)
	void DirectionalShadowMapPass(DirectionalLight* light);
	//function used to generate omnidirectional shadow map from the light sources on multiple directions (6 depth map generated and stored in a cube map)
	void OmniShadowMapPass(PointLight* light);



	void Start();

	void RenderPass(glm::mat4 projectionMatrix, glm::mat4 viewMatrix);


	~Game();


private:

	
	MyWindow mainWindow;
	std::vector<Mesh*> meshList;
	std::vector<Shader> shaderList;
	Shader directionalShadowShader;
	Shader omniShadowShader;
	Camera camera;
	Texture brickTexture, dirtTexture;
	GLfloat deltaTime, lastTime, MarioAngle;
	CommonValue *Value;
	unsigned int spotLightCount, pointLightCount;

	//Lights
	DirectionalLight mainLight;
	PointLight* pointLights;
	SpotLight* spotLights;

	//Materials
	Material shinyMaterial, DullMaterial;

	//3D Models
	Model EyeBall, Mario;

	//uniform values

	GLuint uniformProjection, uniformModel, uniformView, uniformEyePosition,
		uniformSpecularIntensity, uniformShininess, uniformOmniLightPos, uniformFarPlane;



};

