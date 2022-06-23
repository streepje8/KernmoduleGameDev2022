#pragma once
#include "Component.h"
#include "StreepEngine.h"
#include "ScoreDisplay.h"

class CoinController :
    public Component
{
private:
    Rigidbody2D* rb;
    ScoreDisplay* sdp;
public:
    float fallSpeed;
    float timer = 0;
    int direction = 0;
    CoinController(ScoreDisplay* sdp) {
        rb = nullptr;
        fallSpeed = 30;
        this->sdp = sdp;
    }
    void Start() override;
    void Update() override;
    void OnCollision() override;
};

