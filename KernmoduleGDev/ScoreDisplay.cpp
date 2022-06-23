#include "ScoreDisplay.h"

void ScoreDisplay::Start()
{
	textrend = GetComponent<TextRenderer>();
	coinsCollected = 0;
	lives = 5;
}

void ScoreDisplay::Update()
{
	std::string newText = "Coins: ";
	newText.append(std::to_string(coinsCollected));
	newText.append("/20 Lives: ");
	newText.append(std::to_string(lives));
	textrend->SetText(newText);
}
