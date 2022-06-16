#include "BoxCollider2D.h"
#include "CommonIncludes.h"
#include "SceneManager.h"

void BoxCollider2D::Start()
{
}

void BoxCollider2D::Update()
{
	Scene* s = SceneManager::GetInstance().GetCurrentScene();
	List<GameObject*>* objects = s->GetObjects();
	for (int i = 0; i < objects->count(); i++) {
		GameObject* obj = objects->get(i);
		BoxCollider2D* collider = obj->GetComponentFromObject<BoxCollider2D>();
		bool isColliding = true;
		//AABB collision
		if (transform->position.x + width < obj->transform->position.x || transform->position.x > obj->transform->position.x + collider->width) isColliding = false;
		if (transform->position.y + height < obj->transform->position.y || transform->position.y > obj->transform->position.y + collider->height) isColliding = false;
		List<Component*>* allcomps = ((GameObject*)gameObject)->GetAllComponents();
		for (int i = 0; i < allcomps->count(); i++) {
			allcomps->get(i)->OnCollision();
		}
	}
}

void BoxCollider2D::OnCollision()
{
	transform->rotation = Quaternion::Euler(0,0,1 * Time::GetInstance().deltaTime) * transform->rotation;
}
