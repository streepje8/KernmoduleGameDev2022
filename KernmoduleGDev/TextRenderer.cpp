#include "TextRenderer.h"

TextRenderer::TextRenderer(std::string fontPath)
{
	font = VAR(sf::Font, new sf::Font());
	if (!font->loadFromFile(fontPath))
	{
		Debug::LogError("Could not load font from file: " + fontPath);
		return;
	}
	text = VAR(sf::Text, new sf::Text());
	text->setFont(*font);
	fontSize = 20;
	isBold = false;
	isUnderlined = false;
	isItalic = false;
}

void TextRenderer::SetText(std::string text)
{
	this->text->setString(text);
}

void TextRenderer::Render(sf::RenderWindow* win)
{
	text->setCharacterSize(fontSize);
	text->setOrigin(fontSize * 0.5 * text->getString().getSize() * 0.5, fontSize * 0.25);
	text->setRotation(Math::MOD((Quaternion::ToEulerRad(transform->rotation) * Math::RAD_TO_DEG).z, 360));
	text->setPosition((((transform->position + Vector3(400, -200, 0)) * Vector3(1, -1, 1))).to_SFVector2f_dropZ());
	text->setScale(transform->scale.to_SFVector2f_dropZ());
	text->setStyle((sf::Text::Bold & (isBold * 0xF)) | (sf::Text::Underlined & (isUnderlined * 0xF)) | (sf::Text::Italic & (isItalic * 0xF)));
	win->draw(*text);
}
