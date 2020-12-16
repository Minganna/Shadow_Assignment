#pragma once

#include <GL\glew.h>

#include "stb_image.h"

///this class is responsable to apply textures to 3d objects
class Texture
{
public:
	Texture();
	///class constructor 
	/// \param fileLoc the path to the texture to apply
	Texture(const char* fileLoc);

	///This fuction is used to load texture that do not have alpha channel
	bool LoadTexture();
	///This fuction is used to load texture that have alpha channel
	bool LoadTextureA();

	///This fuction to apply the loaded texture to an object
	void UseTexture();
	///This fuction is used to clear the stored texture
	void ClearTexture();

	///class deconstructor 
	~Texture();

private:
	GLuint textureID;
	int width, height, bitDepth;

	const char* fileLocation;
};

