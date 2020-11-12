#pragma once

class CommonValue
{
public:
	const int getMAX_POINT_LIGHTS() { return MAX_POINT_LIGHTS; };
	const int getMAX_SPOT_LIGHTS() { return MAX_SPOT_LIGHTS; };

protected:
	const int MAX_POINT_LIGHTS = 3, MAX_SPOT_LIGHTS = 3;
};
