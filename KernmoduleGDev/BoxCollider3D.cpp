#include "BoxCollider3D.h"
#include "CommonIncludes.h"
#include "SceneManager.h"

void BoxCollider3D::Update()
{
	Scene* s = SceneManager::GetInstance().GetCurrentScene();
	List<GameObject*>* objects = s->GetObjects();
	for (int i = 0; i < objects->count(); i++) {
		GameObject* obj = objects->get(i);
		BoxCollider3D* collider = obj->GetComponentFromObject<BoxCollider3D>();
		if (collider != this) { //No self collisions
			bool isColliding = true;
			//AABBCC collision (or something like that lmao)
			if (!((obj->transform->position.x - collider->width / 2) <= transform->position.x + width && (obj->transform->position.x + collider->width / 2) >= transform->position.x - width)) isColliding = false;
			if (!((obj->transform->position.y - collider->height / 2) <= transform->position.y + height && (obj->transform->position.y + collider->height / 2) >= transform->position.y - height)) isColliding = false;
			if (!((obj->transform->position.z - collider->depth / 2) <= transform->position.z + depth && (obj->transform->position.z + collider->depth / 2) >= transform->position.z - depth)) isColliding = false;
			if (isColliding) {
				List<Component*>* allcomps = ((GameObject*)gameObject)->GetAllComponents();
				for (int i = 0; i < allcomps->count(); i++) {
					allcomps->get(i)->OnCollision();
				}
			}
		}
	}
}