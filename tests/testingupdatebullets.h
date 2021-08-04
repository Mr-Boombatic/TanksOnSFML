#ifndef TESTINGUPDATEBULLETS_H
#define TESTINGUPDATEBULLETS_H

#include "Header.h"
#include <gtest/gtest.h>
#include <iterator>

int Survivors(list<Bullet>& bullets)
{
    update_bullets(bullets);

    return bullets.size();
}


/*2 пули пересекаются 2 нет*/
TEST(TestUpdateBullets, num1)
{
    list<Bullet> bullets;
    Bullet* bullet;
    bullet = new Bullet;
    bullet->set(18, 0);
    bullets.push_front(*bullet);
    bullet = new Bullet;
    bullet->set(42, 0);
    bullets.push_front(*bullet);
    bullet = new Bullet;
    bullet->set(80, 0);
    bullets.push_front(*bullet);
    bullet = new Bullet;
    bullet->set(50, 0);
    bullets.push_front(*bullet);


    ASSERT_EQ(Survivors(bullets), 2);

}

/*Ниодна пуля не пересекается*/
TEST(TestUpdateBullets, num2)
{
    list<Bullet> bullets;
    Bullet* bullet;
    bullet = new Bullet;
    bullet->set(18,17);
    bullets.push_front(*bullet);
    bullet = new Bullet;
    bullet->set(42, 0);
    bullets.push_front(*bullet);
    bullet = new Bullet;
    bullet->set(80, 34);
    bullets.push_front(*bullet);
    bullet = new Bullet;
    bullet->set(100, 0);
    bullets.push_front(*bullet);



    ASSERT_EQ(Survivors(bullets), 4);
}

TEST(TestUpdateBullets, num3)
{
    list<Bullet> bullets;
    Bullet* bullet;
    bullet = new Bullet;
    bullet->set(18,17);
    bullets.push_front(*bullet);
    bullet = new Bullet;
    bullet->set(19, 5);
    bullets.push_front(*bullet);
    bullet = new Bullet;
    bullet->set(17, 15);
    bullets.push_front(*bullet);
    bullet = new Bullet;
    bullet->set(20, 9);
    bullets.push_front(*bullet);



    ASSERT_EQ(Survivors(bullets), 0);
}

#endif // TESTINGUPDATEBULLETS_H
