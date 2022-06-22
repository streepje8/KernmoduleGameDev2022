#include "BoxCollider2D.h"
#include "CommonIncludes.h"
#include "SceneManager.h"

void BoxCollider2D::Update()
{
	Scene* s = SceneManager::GetInstance().GetCurrentScene();
	List<GameObject*>* objects = s->GetObjects();
	for (int i = 0; i < objects->count(); i++) {
		GameObject* obj = objects->get(i);
		BoxCollider2D* collider = obj->GetComponentFromObject<BoxCollider2D>();
		if (collider != this) { //No self collisions
			bool isColliding = true;
			//AABB collision
			if (!((obj->transform->position.x - (collider->width * transform->scale.x) / 2) <= transform->position.x + (width * transform->scale.x) && (obj->transform->position.x + (collider->width * transform->scale.x) / 2) >= transform->position.x - (width * transform->scale.x))) isColliding = false;
			if (!((obj->transform->position.y - (collider->height * transform->scale.y) / 2) <= transform->position.y + (height * transform->scale.y) && (obj->transform->position.y + (collider->height * transform->scale.y) / 2) >= transform->position.y - (height * transform->scale.y))) isColliding = false;
			if (isColliding) {
				List<Component*>* allcomps = ((GameObject*)gameObject)->GetAllComponents();
				for (int i = 0; i < allcomps->count(); i++) {
					allcomps->get(i)->OnCollision();
				}
			}
		}
	}
}