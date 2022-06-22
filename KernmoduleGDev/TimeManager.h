#pragma once
class TimeManager
{
public:
	static TimeManager& GetInstance();
	float deltaTime;
	float time;
	float FPS;
};

