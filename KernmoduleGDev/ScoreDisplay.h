#pragma once
#include "Component.h"
#include "StreepEngine.h"
class ScoreDisplay :
    public Component
{
    public:
        TextRenderer* textrend;
        int lives;
        int coinsCollected;
        void Start() override;
        void Update() override;
};

