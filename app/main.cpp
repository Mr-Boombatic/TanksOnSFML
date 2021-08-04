#include"Header.h"


using namespace sf;
using namespace std;

extern const int H;
extern const int W;

extern string level[20];
extern int score;

bool menu_draw(RenderWindow& , Texture& , Texture& ,Texture& );

int main()
{
    RenderWindow window(VideoMode(640, 640), "Tankes offline");

    int flag = 1;
    score = 0;

    Texture t,w,b_,menu, backgraund_menu, sorry;
    t.loadFromFile("texture.png");
    w.loadFromFile("bullet.png");
    b_.loadFromFile("background.png");
    menu.loadFromFile("menu.png");
    backgraund_menu.loadFromFile("background_menu.jpg");
    sorry.loadFromFile("sorry.png");


    Font font;
    font.loadFromFile("CyrilicOld.TTF");
    Text text;
    text.setFont(font);
    text.setCharacterSize(30);
    text.setStyle(sf::Text::Bold);
    text.setPosition(0, 0);

    Sprite b(b_);

    list<Bullet> bullet;
    Bullet bull;

    vector<ENEMY> enemy;
    enemy.push_back(ENEMY(t, 32, 32));
    enemy.push_back(ENEMY(t, 576, 32));
    enemy.push_back(ENEMY(t, 192, 128));
    enemy.push_back(ENEMY(t, 448, 128));
    enemy.push_back(ENEMY(t, 32, 256));
    enemy.push_back(ENEMY(t, 576, 256));

    PLAYER p(t,32,576);
    p.life = true;
    Sprite wall(t);

    Clock clock, clock_bullet;

    int size;

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();

        time = time / 700;

        if (time > 20) time = 20;

        if (p.life == false || flag ==1)
        {
            flag = 0;
            if (menu_draw(window, menu, backgraund_menu, sorry) == true)
            {
                enemy[0].rect.left = 32; enemy[0].rect.top = 32;
                enemy[1].rect.left = 576; enemy[1].rect.top = 32;
                enemy[2].rect.left = 192; enemy[2].rect.top = 128;
                enemy[3].rect.left = 416; enemy[3].rect.top = 128;
                enemy[4].rect.left = 32; enemy[4].rect.top = 256;
                enemy[5].rect.left = 576; enemy[5].rect.top = 256;
                p.rect.left = 32; p.rect.top = 576;
                p.life = true;
            }
        }

        Event event;

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            p.dy = 0.1;
            p.direction = 2;
        }

        else if (Keyboard::isKeyPressed(Keyboard::Up))
        {	p.dy = -0.1;
            p.direction = 3;
        }

        else if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            p.dx = -0.1;
            p.direction = 0;
        }

        else if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            p.dx = 0.1;
            p.direction = 1;
        }


        if (Keyboard::isKeyPressed(Keyboard::Space))
        {
            if (clock_bullet.getElapsedTime().asMicroseconds() >= 400000)
            {
                    clock_bullet.restart();

                    bull = Bullet(p.rect.left, p.rect.top, w, p.direction);
                    bull.his = player;
                    bullet.push_front(bull);
            }
        }

        window.draw(b);

        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
            {
                if (level[i][j] == 'B') wall.setTextureRect(IntRect(65, 2, 32, 32));

                if (level[i][j] == '0')  continue;

                if (level[i][j] == ' ') continue;

                wall.setPosition(j * 32, i * 32);
                window.draw(wall);
            }


        p.update(time);
        for (int i = 0; i < enemy.size(); i++)
        {
            if (bullet.size() == 0)
            {
                if ((bull = enemy[i].killPlayer(p.rect.left, p.rect.top, w)).life == true)
                {
                    bullet.push_front(bull);
                    window.draw(bull.sprite);
                }
                window.draw(enemy[i].sprite);
                enemy[i].update(time);
                continue;
            }
            enemy[i].update(time);
            for (list <Bullet> :: iterator bit=bullet.begin(); bit!=bullet.end(); ++bit)
            {
                enemy[i].update((*bit));  // обработка столкнавения врага с пулей
                p.update((*bit));         // обработка столкнавения игрока с пулей
                window.draw(enemy[i].sprite);

                if (enemy[i].life == false)
                {
                    enemy[i].rect.left = enemy[i].resp[0];
                    enemy[i].rect.top = enemy[i].resp[1];
                    enemy[i].life = true;
                    if ((bull = enemy[i].killPlayer(p.rect.left, p.rect.top, w)).life == true);
                    window.draw(enemy[i].sprite);
                    if (bullet.size() == 0) break;
                    continue;
                }

                if ((*bit).life == false)
                {
                    bullet.erase(bit);
                    if(bullet.size() == 0) break;
                    continue;
                }
            }
        }
        for (list <Bullet> :: iterator bit = bullet.begin(); bit != bullet.end(); ++bit)
        {
            (*bit).update(time);
            window.draw((*bit).sprite);
        }
        update_bullets(bullet);

        ostringstream playerScore;
        playerScore << score;
        text.setString("Score:" + playerScore.str());
        window.draw(text);

        window.draw(p.sprite);
        window.display();
    }

    return 0;
}

bool menu_draw(RenderWindow& window,Texture & menu, Texture& backgraund_menu, Texture& sorry_)
{
    static int maxScore;
    Sprite menu1, menu2, menu3, menuBg, sorry;

    int menuNum = 0;

        sorry.setTexture(sorry_);
        menu1.setTexture(menu);
        menu1.setTextureRect(IntRect(23, 17, 100, 61));
        menu2.setTexture(menu);
        menu2.setTextureRect(IntRect(23, 137, 135, 50));
        menu3.setTexture(menu);
        menu3.setTextureRect(IntRect(23, 258, 78, 49));
        menuBg.setTexture(backgraund_menu);
        menuBg.setPosition(0, 0);
        menu1.setPosition(406, 130);
        menu2.setPosition(406, 200);
        menu3.setPosition(406, 270);

    Event event;

    while (true)
    {

        window.pollEvent(event);
        menuNum = 0;
        if (IntRect(406, 130, 100, 61).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Green); menu2.setColor(Color::White); menu3.setColor(Color::White); menuNum = 1; }
        if (IntRect(406, 200, 135, 50).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Green); menu1.setColor(Color::White); menu3.setColor(Color::White); menuNum = 2; }
        if (IntRect(406, 270, 78, 49).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Green); menu2.setColor(Color::White); menu1.setColor(Color::White); menuNum = 3; }
        if (Mouse::isButtonPressed(Mouse::Left))
        {
            if (menuNum == 1)
            {
                return true;
            }
            if (menuNum == 2)
            {
                Clock clock;
                clock.restart();
                window.draw(sorry);
                window.display();
                while (clock.getElapsedTime().asMicroseconds() <= 3000000) {
                    window.draw(sorry);
                    window.display();
                }
                continue;

            }
            if (menuNum == 3) { window.close(); }
        }
        if (event.type == Event::Closed) window.close();
        window.draw(menuBg);
        window.draw(menu1);
        window.draw(menu2);
        window.draw(menu3);
        if (maxScore < score)
        {
            Font font;
            font.loadFromFile("CyrilicOld.TTF");
            Text text;
            text.setFont(font);
            text.setString("score:");
            text.setCharacterSize(30);
            text.setStyle(sf::Text::Bold);
            text.setPosition(0, 0);

            ostringstream playerScore;
            playerScore << score;
            text.setString("Best score:" + playerScore.str());
            window.draw(text);

            maxScore = score;
            score = 0;
        }
        else
        {
            Font font;
            font.loadFromFile("CyrilicOld.TTF");
            Text text;
            text.setFont(font);
            text.setString("Score:");
            text.setCharacterSize(30);
            text.setStyle(sf::Text::Bold);
            text.setPosition(0, 0);

            ostringstream playerScore;
            playerScore << maxScore;
            text.setString("Best score:" + playerScore.str());
            window.draw(text);

            score = 0;
        }
        window.display();
    }

}
