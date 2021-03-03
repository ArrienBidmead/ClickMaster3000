#pragma once
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <functional>

//Forward definitions
namespace sf
{
	class RenderWindow;
	class Texture;
}

class Button : public sf::Transformable
{
public:
	bool bStaticAppearance = false;	// If the button shouldn't change appearance according to hover/ press
	bool bShouldReDraw = true;

	sf::Sprite baseSprite;
	sf::Sprite hoverSprite;

	sf::Color baseColor = {255,255,255,255};
	sf::Color hoverColor = {155,155,155,255};
	sf::Color pressColor = {55,55,55,255};

	bool bHovered = false;
	bool bPressed = false;
	bool bRejectPress = false;

	Button();
	void Poll(sf::RenderWindow &window);
	void Draw(sf::RenderWindow* window);

	std::function<void()> OnHoverBinding = [&]() {};
	std::function<void()> OnUnHoverBinding = [&]() {};
	std::function<void()> OnPressBinding = [&]() {};
	std::function<void()> OnReleaseBinding = [&]() {};

	void SetTextures(sf::Texture* baseTexture, sf::Texture* hoverTexture);
	void FinalizeInit();
	void UpdateColors();
};

