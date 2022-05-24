#include "ParachutePanic.h"
#include "Debug.h"
#include "EngineHook.h"
#include "Engine.h"
#include "Stacktracer.h"
#include "MemoryManager.h"
#include <typeinfo>
#include "TestClass.h"
#include <iostream>
#include "Macros.h"

void ParachutePanic::Awake() {
	FUNCBEGIN(Awake);
	throw std::exception("error");
}