class Bot
{
private:
    int hp = 100;
    int level = 1;
    int damage = 10;
    int possibility_of_hit = 50;
    int possibility_of_protection = 50;
    int possibility_to_fend_off = 15;
public:
    char generateAction();
    int getHp() {return this->hp;}
    void setHp(int r) {this->hp += r;}
    int getLevel() {return this->level;}
    int getDamage() {return this->damage;}
    int getPossibility_of_hit() {return this->possibility_of_hit;}
    int getPossibility_of_protection() {return this->possibility_of_protection;}
    int getPossibility_to_fend_off() {return this->possibility_to_fend_off;}

    int genarateProbability(char action);

    void n_setHp(int r ) {this->hp = r;}
    void setLevel(int level) {this->level = level;}
    void setDamage(int dng) {this->damage = dng;}
    void setPossibility_of_hit(int psh) {this->possibility_of_hit = psh;}
    void setPossibility_of_protection(int value) {this->possibility_of_protection = value;}
    void setPossibility_to_fend_off(int value) {this->possibility_to_fend_off = value;}
};