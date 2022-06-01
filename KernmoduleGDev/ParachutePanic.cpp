#include "ParachutePanic.h"
#include "Debug.h"
#include "Macros.h"
#include "Vector3.h"
#include "Quaternion.h"
#include "Matrix4x4.h"
#include "Math.h"
#include <SFML/Graphics.hpp>

void ParachutePanic::Setup() {
	FUNCBEGIN(Setup);
	this->name = "Parachute Panic";
	this->windowTitle = "Parachute Panic Game";
}

void ParachutePanic::Awake() {
	FUNCBEGIN(Awake);

}