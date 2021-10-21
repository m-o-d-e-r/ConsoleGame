class Player
{
private:
    int hp = 100;
    int exp = 0;
    int level = 20;
    int damage = 10;
    int possibility_of_hit = 50;
    int possibility_of_protection = 50;
    int possibility_to_fend_off = 15;
    int count_of_batle;
public:
    int getHp() {return this->hp;}
    int getExp() {return this->exp;}
    void setHp(int r) {this->hp += r;}
    int getLevel() {return this->level;}
    int getDamage() {return this->damage;}
    int getPossibility_of_hit() {return this->possibility_of_hit;}
    int getPossibility_of_protection() {return this->possibility_of_protection;}
    int getPossibility_to_fend_off() {return this->possibility_to_fend_off;}
    int getCount_of_batle() {return this->count_of_batle;}

    char getAction();
    int genarateProbability(char action);
};