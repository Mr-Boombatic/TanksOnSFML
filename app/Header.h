#ifndef HEADER_H
#define HEADER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <list>
#include <iterator>
#include <vector>
#include <sstream>

using namespace sf;
using namespace std;

extern string level[20];
extern int score;

enum state { left, right, down, up };
enum part { enemy, player };
const int H = 20;
const int W = 20;



class Bullet
{
public:

    FloatRect rect;
    bool life;
    float speed;
    float dx, dy;
    int dir;
    Sprite sprite;
    int his;

    Bullet();

    Bullet(float X, float Y, Texture& b, int DIR);

    void set(float X, float Y, Texture& b, int DIR);

    void set(float X, float Y);

    void update(float time);

};

void update_bullets(list<Bullet>& bullet);

class PLAYER {

public:

    bool life;
    float dx, dy;
    bool shoot;
    FloatRect rect;
    Sprite sprite;
    int direction;

    PLAYER(Texture& image, float X, float Y)
    {
        sprite.setTexture(image);
        sprite.setTextureRect(IntRect(0, 0, 32, 32));
        rect = FloatRect(X, Y, 32, 32);
        sprite.setPosition(rect.left, rect.top);
        shoot = true;
        dx = dy = 0;
    }

    void update(Bullet& bullet);

    void update(float time);

    void Collision(int dir);
};



class ENEMY : public PLAYER {

public:

    Clock clock,clock2;
    float resp[2];
    int rand_ = 4;
    bool life;

    ENEMY(Texture& d,float X, float Y);

    Bullet killPlayer(float X, float Y, Texture& bullet);

    void update(Bullet& bul);

    void update(float time);
};

#endif // HEADER_H
