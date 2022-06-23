#pragma once
#include "Component.h"
#include "Vector3.h"
#include "BoxCollider2D.h"
class Rigidbody2D :
    public Component
{
    public:
        float mass;
        Vector3* velocity;
        bool useGravity;
        Vector3 gravity;
        Vector3 friction;
        Vector3 maxVelocity;
        BoxCollider2D* collider;
        float pixelsPerMetre;
        Rigidbody2D() {
            collider = nullptr; //We will get this in the start method to allow the user to add this component before the collider
            mass = 1;
            useGravity = true;
            gravity = Vector3(0, -9.81f, 0);
            pixelsPerMetre = 100;
            velocity = nullptr;
            friction = Vector3(1, 1, 1);
            maxVelocity = Vector3(9, 9, 9);
        }
        void Start() override;
        void Update() override;
        Vector3 GetFrictionForce();
        float CalculateFacingArea();
        float CalculateDragCoefficient();
        void AddForce(Vector3 force);

};

