#pragma once
///Here are stored the common values that need to be used in different classes, such as the MAX number of lights
class CommonValue
{
public:
	const int getMAX_POINT_LIGHTS() { return MAX_POINT_LIGHTS; };
	const int getMAX_SPOT_LIGHTS() { return MAX_SPOT_LIGHTS; };

protected:
	//variable that store the maximum number of lights in the scene
	const int MAX_POINT_LIGHTS = 3, MAX_SPOT_LIGHTS = 3;
};
