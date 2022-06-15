#pragma once
class Time
{
public:
	static Time& GetInstance();
	float deltaTime;
	float time;
	float FPS;
};

