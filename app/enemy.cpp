#include "Header.h"

extern string level[20];
extern int score;

void ENEMY::update(Bullet& bul)
{

    if (clock.getElapsedTime().asMicroseconds() >= 1000000)
    {
        direction = rand() % 4;
        clock.restart();
    }

    switch (direction)
    {
    case 0: dx = -0.1; dy = 0;   break;
    case 1: dx = 0.1; dy = 0;   break;
    case 2: dx = 0; dy = 0.1;   break;
    case 3: dx = 0; dy = -0.1;   break;
    case 4: break;
    }


    if ((((bul.rect.left < rect.left + 32 && bul.rect.left > rect.left - 15) || (bul.rect.left > rect.left + 17 && bul.rect.left < rect.left + 32 + 15)) &&
        ((bul.rect.top <= rect.top + 15 && bul.rect.top >= rect.top - 15) || (bul.rect.top <= rect.top - 15 && bul.rect.top >= rect.top + 15))) && bul.his != enemy)
    {
        life = false;
        bul.life = false;
        score++;
    }

    dx = dy = 0;

}

ENEMY::ENEMY(Texture& d, float X, float Y) :PLAYER(d,X,Y)
{
    resp[0] = X;
    resp[1] = Y;
    life = true;
}

void ENEMY::update(float time)
{
    if (clock.getElapsedTime().asMicroseconds() >= 1000000)
    {
        direction = rand() % 4;
        clock.restart();
    }

    switch (direction)
    {
    case 0: dx = -0.1; dy = 0;   break;
    case 1: dx = 0.1; dy = 0;   break;
    case 2: dx = 0; dy = 0.1;   break;
    case 3: dx = 0; dy = -0.1;   break;
    case 4: break;
    }

    rect.left += dx * time;
    Collision(0);
    rect.top += dy * time;
    Collision(1);

    sprite.setPosition(rect.left, rect.top);

    if (direction == 0) sprite.setTextureRect(IntRect(0, 0, 32, 32));

    if (direction == 1)	sprite.setTextureRect(IntRect(31, 0, -32, 32));

    if (direction == 2) sprite.setTextureRect(IntRect(10, 73, 32, -32));

    if (direction == 3) sprite.setTextureRect(IntRect(10, 42, 32, 32));

    dx = dy = 0;
}

Bullet ENEMY::killPlayer(float X, float Y, Texture& bullet)
{
    if (clock2.getElapsedTime().asMicroseconds() >= 2000000)
    {
        Bullet bull;
        int iy = Y / 32;
        int ix = X / 32;
        int j;

        if (X > rect.left && static_cast<int>(Y / 32) == static_cast<int>(rect.top / 32))for (j = rect.left/32; j < X/32; j++) if (level[iy][j] == 'B') return bull;
        if (X < rect.left && static_cast<int>(Y / 32) == static_cast<int>(rect.top / 32))for (j = rect.left/32; j > X/32; j--) if (level[iy][j] == 'B') return bull;
        if (Y > rect.top && static_cast<int>(X / 32) == static_cast<int>(rect.left / 32))for (j = rect.top/32; j < Y/32; j++) if (level[j][ix] == 'B') return bull;
        if (Y < rect.top && static_cast<int>(X / 32) == static_cast<int>(rect.left / 32))for (j = rect.top/32; j > Y/32; j--) if (level[j][ix] == 'B') return bull;

        if (true)
        {
            if (static_cast<int>(X / 32) == static_cast<int>(rect.left / 32))
            {
                cout << static_cast<int>(X / 32) << "       " << static_cast<int>(rect.left / 32) << endl;
                if (rect.top > Y)
                {
                    bull.set(rect.left, rect.top, bullet, up);
                    direction = up;
                    sprite.setTextureRect(IntRect(10, 42, 32, 32));
                }
                if (rect.top < Y)
                {
                    bull.set(rect.left, rect.top, bullet, down);
                    direction = down;
                    sprite.setTextureRect(IntRect(10, 73, 32, -32));
                }
            }
            if(static_cast<int>(Y / 32) == static_cast<int>(rect.top / 32))
            {
                cout << static_cast<int>(X / 32) << "       " << static_cast<int>(rect.left / 32) << endl;
                if (rect.left < X)
                {
                    bull.set(rect.left, rect.top, bullet, 1);
                    direction = 1;
                    sprite.setTextureRect(IntRect(31, 0, -32, 32));
                }
                if (rect.left > X)
                {
                    bull.set(rect.left, rect.top, bullet, 0);
                    direction = 0;
                    sprite.setTextureRect(IntRect(0, 0, 32, 32));
                }
            }
            bull.his = enemy;
            clock2.restart();
            return bull;
        }
    }
        Bullet bull;
        return bull;

}
