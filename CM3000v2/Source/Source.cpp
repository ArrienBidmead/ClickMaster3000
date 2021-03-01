#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Textures.h"
#include <iostream>
#include <Windows.h>
#include <Dwmapi.h>

#pragma comment (lib, "Dwmapi.lib")
//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")		// Disable console

int main()
{
    sf::RenderWindow window(sf::VideoMode(208, 80), "ClickMaster 3000", sf::Style::None);

    MARGINS margins;
    margins.cxLeftWidth = -1;
    HWND hwnd = window.getSystemHandle();

    SetWindowLong(hwnd, GWL_STYLE, WS_POPUP | WS_VISIBLE);
    DwmExtendFrameIntoClientArea(hwnd, &margins);

    SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);		//locks app in front of everything else

    //////////////////////////////////////////////////////////////////////////

    Textures textures;

    sf::Texture overlapTex;
    overlapTex.loadFromMemory(textures.ButtonOverlap1png, sizeof(textures.ButtonOverlap1png));

    Button backgroundButton;
    sf::Texture backTex;
    backTex.loadFromMemory(textures.OuterBox1png, sizeof(textures.OuterBox1png));
    backgroundButton.baseSprite.setTexture(backTex, true);
    backgroundButton.hoverSprite.setColor(sf::Color::Transparent);
    backgroundButton.setPosition(0, 0);
    backgroundButton.baseColor = { 128, 128, 128, 255 };
    backgroundButton.hoverColor = { 128, 128, 128, 255 };
    backgroundButton.pressColor = { 128, 128, 128, 255 };
    sf::Vector2i dragMousePos = {0,0};
    bool bDraggingWindow = false;
    backgroundButton.OnPressBinding = [&]()
    {
        dragMousePos = sf::Mouse::getPosition(window);
        bDraggingWindow = true;
    };

    sf::RectangleShape buttonsRect;
    buttonsRect.setFillColor(sf::Color(0, 0, 0, 255));
    buttonsRect.setPosition(8, 8);
    buttonsRect.setSize(sf::Vector2f(overlapTex.getSize().x * 3, overlapTex.getSize().y));

    Button armButton;
    sf::Texture armTex;
    armTex.loadFromMemory(textures.ArmButton1png, sizeof(textures.ArmButton1png));
    armButton.SetTextures(&armTex, &overlapTex);
    armButton.setPosition(8, 8);
    armButton.baseColor = { 180, 180, 180, 255 };
    armButton.hoverColor = { 30, 140, 30, 255 };
    bool bArmed = false;
    armButton.OnReleaseBinding = [&]()
    {
        bArmed = !bArmed;

        if (bArmed)
        {
            armButton.baseColor = { 0, 255, 0, 255 };
            armButton.hoverColor = { 170, 255, 170, 255 };
        }
        else
        {
            armButton.baseColor = { 180, 180, 180, 255 };
            armButton.hoverColor = { 30, 140, 30, 255 };
        }

        armButton.UpdateColors();
    };

    Button cpsButton;
    sf::Texture cpsTex;
    cpsTex.loadFromMemory(textures.CPSButton0png, sizeof(textures.CPSButton0png));
    sf::Texture cpsTex1;
    cpsTex1.loadFromMemory(textures.CPSButton1png, sizeof(textures.CPSButton1png));
    sf::Texture cpsTex2;
    cpsTex2.loadFromMemory(textures.CPSButton2png, sizeof(textures.CPSButton2png));
    cpsButton.SetTextures(&cpsTex1, &overlapTex);
    cpsButton.setPosition(overlapTex.getSize().x + 8, 8);
    cpsButton.baseColor = { 180, 180, 180, 255 };
    cpsButton.hoverColor = { 140, 100, 30, 255 };
    unsigned char cpsState = 1;
    cpsButton.OnReleaseBinding = [&]()
    {
        if (cpsState < 2)
            cpsState++;
        else
            cpsState = 0;

        switch (cpsState)
        {
        case 0:
            cpsButton.baseSprite.setTexture(cpsTex);
            break;
        case 1:
            cpsButton.baseSprite.setTexture(cpsTex1);
            break;
        case 2:
            cpsButton.baseSprite.setTexture(cpsTex2);
            break;
        }
    };

    Button exitButton;
    sf::Texture exitTex;
    exitTex.loadFromMemory(textures.ExitButton1png, sizeof(textures.ExitButton1png));
    exitButton.SetTextures(&exitTex, &overlapTex);
    exitButton.setPosition(overlapTex.getSize().x * 2 + 8, 8);
    exitButton.baseColor = { 180, 180, 180, 255 };
    exitButton.hoverColor = { 140, 30, 30, 255 };
    exitButton.OnReleaseBinding = [&]()
    {
        exit(0);
    };

    Button* buttons[] = {&backgroundButton, &armButton, &cpsButton, &exitButton};

    for (auto& e : buttons)
        e->FinalizeInit();

    //////////////////////////////////////////////////////////////////////////

    sf::Clock clock;
    while (window.isOpen())
    {
        if (!bDraggingWindow)
        {
            sf::sleep(sf::milliseconds(2));

            if (clock.getElapsedTime().asMilliseconds() < 16)
                continue;
            else
                clock.restart();
        }
        else
        {
            clock.restart();
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //////////////////////////////////////////////////////////////////////////

        for(auto& e : buttons)
            e->Poll(window);

        if (bDraggingWindow)
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                window.setPosition(sf::Mouse::getPosition() - dragMousePos);
            }
            else
            {
                bDraggingWindow = false;
            }
        }

        //////////////////////////////////////////////////////////////////////////

        window.clear(sf::Color::Transparent);

        //////////////////////////////////////////////////////////////////////////

        buttons[0]->Draw(&window);
        window.draw(buttonsRect);       //yo, sort this out
        for (int i = 1; i < 4; i++)
            buttons[i]->Draw(&window);

        //////////////////////////////////////////////////////////////////////////

        window.display();
    }

    return 0;
}