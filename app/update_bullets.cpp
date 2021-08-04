#include "Header.h"

extern string level[20];
extern int score;

using namespace std;

void update_bullets(list<Bullet>& bullet)
{
    bool beg = false;
    list <Bullet> :: iterator bit = bullet.begin();
    list <Bullet> :: iterator bit_ = bullet.begin();

    for (int j = 0; j != static_cast<int>(bullet.size()); j++)
    {
        bit_ = bullet.begin();

        for(int i = 0;  i != static_cast<int>(bullet.size()-1); i++)
        {
            bit_++;
            if(bit_ == bit) bit_++;

            if ((((bit_->rect.left - bit->rect.left) <= 16 && (bit_->rect.left - bit->rect.left)>=0) && (((bit_->rect.top - bit->rect.top) >= -16 && (bit_->rect.top - bit->rect.top) <= 0) || ((bit_->rect.top - bit->rect.top) <= 16 && (bit_->rect.top - bit->rect.top) >= 0))) ||
                (((bit_->rect.left - bit->rect.left) >= -16 && (bit_->rect.left - bit->rect.left) <= 0) && (((bit_->rect.top - bit->rect.top) >= -16 && (bit_->rect.left - bit->rect.top) <= 0) || ((bit_->rect.top - bit->rect.top) <= 16 && (bit_->rect.top - bit->rect.top) >= 0))))
            {
                bullet.erase(bit);
                bullet.erase(bit_);
                bit = bullet.begin();
                beg = true;
                if (bullet.size() == 0) return;
                break;
            }
        }
        if(beg != true) bit++;
        beg=false;
    }
}
