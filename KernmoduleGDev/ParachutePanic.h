#pragma once
#include "StreepEngine.h"
#include "ScoreDisplay.h"
class ParachutePanic :
    public Game
{
    public:
        ScoreDisplay* scoreDisplay;
        bool inGame;
        void Setup() override;
        void Awake() override;
        void Update() override;
        void Stop() override;
        void CreateAndOpenLossScene();
        void CreateAndOpenWinScene();
        void CreateAndOpenGameScene();
};

