#pragma once

class CM3000v2
{
    sf::RenderWindow window;

    sf::Texture overlapTex;
    sf::Texture whiteTex;

    Button backgroundButton;
    sf::Texture backTex;
    sf::Vector2i dragMousePos = { 0,0 };
    bool bDraggingWindow = false;

    Button buttonsRect;

    Button armButton;
    sf::Texture armTex;
    bool bArmed = false;
    bool bActive = false;

    Button cpsButton;
    sf::Texture cpsTex;
    sf::Texture cpsTex1;
    sf::Texture cpsTex2;
    unsigned char cpsState = 1;
    unsigned char cpsDowntime = 16;

    Button exitButton;
    sf::Texture exitTex;

    Button* buttons[5];

    void Init();
    void Update();
    void Draw();
public:
    int Run();
};