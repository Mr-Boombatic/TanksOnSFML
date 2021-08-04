#include"Header.h"

extern string level[20];
extern int score;

    void PLAYER::Collision(int dir)
    {
        for (int i = rect.top / 32; i < (rect.top + rect.height) / 32; i++)
            for (int j = rect.left / 32; j < (rect.left + rect.width) / 32; j++)
            {
                if (level[i][j] == 'B')
                {
                    if ((dx > 0) && (dir == 0)) rect.left = j * 32 - rect.width;
                    if ((dx < 0) && (dir == 0)) rect.left = j * 32 + 32;
                    if ((dy > 0) && (dir == 1)) rect.top = i * 32 - rect.height;
                    if ((dy < 0) && (dir == 1)) rect.top = i * 32 + 32;
                }

            }

    }

    void PLAYER::update(Bullet& bullet)
    {
        if ((((bullet.rect.left < rect.left + 32 && bullet.rect.left > rect.left - 15) || (bullet.rect.left > rect.left + 17 && bullet.rect.left < rect.left + 32 + 15)) &&
            ((bullet.rect.top <= rect.top + 15 && bullet.rect.top >= rect.top - 15) || (bullet.rect.top <= rect.top - 15 && bullet.rect.top >= rect.top + 15))) && bullet.his != player)
        {
            life = false;
            bullet.life = false;
        }
    }

    void PLAYER::update(float time)
    {
        rect.left += dx * time;
        Collision(0);
        rect.top += dy * time;
        Collision(1);


        sprite.setPosition(rect.left, rect.top);

        if (direction == 0)
        {
            sprite.setTextureRect(IntRect(0, 0, 32, 32));
        }

        if (direction == 1)
        {
            sprite.setTextureRect(IntRect(31, 0, -32, 32));
        }

        if (direction == 2)
        {
            sprite.setTextureRect(IntRect(10, 73, 32, -32));
        }

        if (direction == 3)
        {
            sprite.setTextureRect(IntRect(10, 42, 32, 32));
        }



        dx = dy = 0;

    }
