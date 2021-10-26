class Clothes
{
    int head = 0, body = 0;
};


class Inventory
{
    int currentLeft;  // текущий предмет
    int currentRight; //

    int leftArm[5];   // все предметы которые можно взять
    int rightArm[5];  // 

    Clothes clothes; // броня
};


class Player
{
private:
    int hp = 100;
    int exp = 0;
    int level = 1;
    int damage = 10;
    int possibility_of_hit = 50;
    int possibility_of_protection = 50;
    int possibility_to_fend_off = 15;
    int count_of_batle;

    Inventory playeriInventory;
public:
    int getHp() {return this->hp;}
    int getExp() {return this->exp;}
    int getLevel() {return this->level;}
    int getDamage() {return this->damage;}
    int getPossibility_of_hit() {return this->possibility_of_hit;}
    int getPossibility_of_protection() {return this->possibility_of_protection;}
    int getPossibility_to_fend_off() {return this->possibility_to_fend_off;}
    int getCount_of_batle() {return this->count_of_batle;}

    char getAction();
    int genarateProbability(char action);

    void setHp(int r) {this->hp += r;}
    void n_setHp(int r ) {this->hp = r;}
    void setExp(int exp) {this->exp = exp;}
    void setLevel(int level) {this->level = level;}
    void setDamage(int dng) {this->damage = dng;}
    void setPossibility_of_hit(int psh) {this->possibility_of_hit = psh;}
    void setPossibility_of_protection(int value) {this->possibility_of_protection = value;}
    void setPossibility_to_fend_off(int value) {this->possibility_to_fend_off = value;}
    void setCount_of_batle(int value) {this->count_of_batle = value;}
};




