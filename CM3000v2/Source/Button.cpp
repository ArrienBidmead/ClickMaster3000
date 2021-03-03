#include "Button.h"
#include <SFML/Graphics.hpp>

Button::Button()
{
	
}

void Button::Poll(sf::RenderWindow &window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	if (mousePos.x >= getPosition().x && mousePos.y >= getPosition().y 
		&& mousePos.x < getPosition().x + baseSprite.getTexture()->getSize().x * getScale().x && mousePos.y < getPosition().y + baseSprite.getTexture()->getSize().y * getScale().y)
	{
		bool bMouseLeftDown = sf::Mouse::isButtonPressed(sf::Mouse::Left);

		if (!bHovered)
		{
			bHovered = true;
			UpdateColors();

			OnHoverBinding();

			if (bMouseLeftDown)
				bRejectPress = true;
		}

		if (bRejectPress)
		{
			if (!bMouseLeftDown)
			{
				bRejectPress = false;
			}
		}
		else
		if (!bPressed)
		{
			if (bMouseLeftDown)
			{
				bPressed = true;
				UpdateColors();

				OnPressBinding();
			}
		}
		else
		{
			if (!bMouseLeftDown)
			{
				bPressed = false;
				UpdateColors();

				OnReleaseBinding();
			}
		}
	}
	else
	{
		if (bHovered)
		{
			bHovered = false;
			bPressed = false;
			bRejectPress = false;
			UpdateColors();

			OnUnHoverBinding();
		}
	}
}

void Button::Draw(sf::RenderWindow* window)
{
	bShouldReDraw = false;

	if (getTransform() != baseSprite.getTransform())
	{
		baseSprite.setPosition(getPosition());
		baseSprite.setRotation(getRotation());
		baseSprite.setScale(getScale());
		hoverSprite.setPosition(getPosition());
		hoverSprite.setRotation(getRotation());
		hoverSprite.setScale(getScale());
	}

	window->draw(baseSprite);

	if(bHovered && !bStaticAppearance)
		window->draw(hoverSprite);
}

void Button::SetTextures(sf::Texture* baseTexture, sf::Texture* hoverTexture)
{
	baseSprite.setTexture(*baseTexture, true);
	hoverSprite.setTexture(*hoverTexture, true);
	bShouldReDraw = true;
}

void Button::FinalizeInit()
{
	UpdateColors();
}

void Button::UpdateColors()
{
	if (bHovered && !bStaticAppearance)
	{
		if (bPressed)
		{
			baseSprite.setColor(pressColor);
			bShouldReDraw = true;
		}
		else
		{
			baseSprite.setColor(hoverColor);
			bShouldReDraw = true;
		}
	}
	else
	{
		baseSprite.setColor(baseColor);
		bShouldReDraw = true;
	}
}
