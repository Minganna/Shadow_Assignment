#pragma once
#include "ShadowMap.h"

///this class inherets from the ShadowMap class,this class is responsable for the omnidirectional shadow map 
class OmniShadowMap :
	public ShadowMap
{
public:
	///class constructor
	OmniShadowMap();

	bool Init(unsigned int width, unsigned int height);

	void Write();

	void Read(GLenum TextureUnit);
	///class deconstructor 
	~OmniShadowMap();
};

