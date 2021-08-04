#include "Header.h"

int score;

std::string level[20]=
{
    "BBBBBBBBBBBBBBBBBBBB",
    "B    B        B    B",
    "B                  B",
    "B                  B",
    "B    B        B    B",
    "B    BBB    BBB    B",
    "B                  B",
    "B                  B",
    "B                  B",
    "BBBBBBB      BBBBBBB",
    "B                  B",
    "B                  B",
    "B     BBBBBBBB     B",
    "B        BB        B",
    "B        BB        B",
    "B        BB        B",
    "B        BB        B",
    "BBBBB          BBBBB",
    "B                  B",
    "BBBBBBBBBBBBBBBBBBBB",
};

Bullet::Bullet()
{
    life = false;
}

Bullet::Bullet(float X, float Y, Texture& b, int DIR)
{
    sprite.setTexture(b);
    sprite.setTextureRect(IntRect(0, 0, 16, 16));
    rect = FloatRect(X + 8, Y + 8, 16, 16);
    sprite.setPosition(rect.left, rect.top);
    speed = 0.2;
    dir = DIR;
    life = true;
}

void Bullet::set(float X, float Y, Texture& b, int DIR)
{
    sprite.setTexture(b);
    sprite.setTextureRect(IntRect(0, 0, 16, 16));
    rect = FloatRect(X + 8, Y + 8, 16, 16);
    sprite.setPosition(rect.left, rect.top);
    speed = 0.2;
    dir = DIR;
    life = true;
}

void Bullet::set(float X, float Y)
{
    rect = FloatRect(X+8, Y+8, 16, 16);
    sprite.setPosition(rect.left, rect.top);
    life = true;
}

void Bullet::update(float time)
{
    switch (dir)
    {
    case 0: dx = -speed; dy = 0;   break;
    case 1: dx = speed; dy = 0;   break;
    case 2: dx = 0; dy = speed;   break;
    case 3: dx = 0; dy = -speed;   break;
    }

    rect.left += dx * time;

    for (int i = rect.top / 32; i < (rect.top + rect.height) / 32; i++)
        for (int j = rect.left / 32; j < (rect.left + rect.width) / 32; j++)
            if (level[i][j] == 'B')
            {
                life = false;
            }

    rect.top += dy * time;

    for (int i = rect.top / 32; i < (rect.top + rect.height) / 32; i++)
        for (int j = rect.left / 32; j < (rect.left + rect.width) / 32; j++)
            if (level[i][j] == 'B') {
                life = false;
            }
    sprite.setPosition(rect.left, rect.top);
}
