#pragma once
#include "RenderPipeline.h"
class BuildInRenderer :
    public RenderPipeline
{
    public:
        void Render(sf::RenderWindow* win) override;
};

