#pragma once

#include "mainHeader.h"


class Game
{
public:

	Game();

	void calcAverageNormals(unsigned int* indices, unsigned int indiceCount, GLfloat* vertices, unsigned int verticeCount,
		unsigned int vLength, unsigned int normalOffset);

	void CreateObjects();
	void CreateShaders();
	void RenderScene();
	void DirectionalShadowMapPass(DirectionalLight* light);
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

