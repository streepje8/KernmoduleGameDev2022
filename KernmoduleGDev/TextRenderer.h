#pragma once
#include "Renderer.h"
class TextRenderer :
    public Renderer
{
    private:
        sf::Font* font;
        sf::Text* text;
    public:
        int fontSize;
        bool isBold;
        bool isUnderlined;
        bool isItalic;
        TextRenderer(std::string fontPath);
        void SetText(std::string text);
        void SetColor(sf::Color color);
        void Render(sf::RenderWindow* win) override;
};

