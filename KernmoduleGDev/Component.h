#pragma once
class Component
{
	private:
		
	public:
		bool enabled = true;
		bool stackable = true;
		virtual void Awake() {};
		virtual void Start() {};
		virtual void Update() {};
		virtual void OnDestory() {};
		virtual void OnApplicationQuit() {};
		GameObject gameObject;
		Transform transform;
		Component();
};

