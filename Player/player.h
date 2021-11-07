#include <map>
#include <string>

namespace PlayerItems {
    // [0] - индекс вещей
    // [1] - урон(защита)

    struct ItemData {
        std::map <int, int> THINGS_FOR_ARMS_ATTACK    = {
            {0, 2}, {1, 3}, {2, 7}, {3, 15}
        };
        std::map <int, int> THINGS_FOR_ARMS_DEFENCE   = {
            {0, 5}, {1, 10}, {2, 15}
        };

        std::map <int, std::string> NAME_OF_THINGS_FOR_ATTACK = {
            {0, "Sword"},
            {1, "Geralt's sword"},
            {2, "Predator's sword"},
            {3, "Keeper's staff"},
            {10, "..."}
        };
    };
    
    enum class THINGS_FOR_ARMS_ATTACK_CLASS {
        SWORD,            // 2
        GERALT_S_SWORD,   // 3
        PREDATOR_S_SWORD, // 7
        KEEPER_S_STAFF,   // 15
    };

    enum class THINGS_FOR_ARMS_DEFENCE_CLASS {
        SHIELD,          // 5
        ARTHUR_S_SHIELD, // 10
        SHIELD_OF_GOLEM  // 15
    };


    namespace Clothes // будет среднее значение
    {
        enum class Head {
            HELMET,
            HELMET_OF_ARTUR,
            ELF_S_HELMET
        };

        enum class Body {
            ARMOR_1,
            ARMOR_2,
            ARMOR_3
        };
    }
}



class Clothes
{
public:
    int head = 0, body = 0;
};


class Inventory
{
public:
    int currentLeft;  // текущий предмет
    int currentRight; //

    int leftArm[5]  = {10, 10, 10, 10, 10};   // все предметы которые можно взять
    int rightArm[5] = {10, 10, 10, 10, 10};  // 

    Clothes clothes;  // броня
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

    int newThing = 90;

    Inventory playeriInventory;
public:
    int *leftArm_link  = &playeriInventory.leftArm[0];
    int *rightArm_link = &playeriInventory.leftArm[0];

    int getHp() {return this->hp;}
    int getExp() {return this->exp;}
    int getLevel() {return this->level;}
    int getDamage() {return this->damage;}
    int getPossibility_of_hit() {return this->possibility_of_hit;}
    int getPossibility_of_protection() {return this->possibility_of_protection;}
    int getPossibility_to_fend_off() {return this->possibility_to_fend_off;}
    int getCount_of_batle() {return this->count_of_batle;}

    int getNewThing() {return this-> newThing;}

    Inventory getPlayeriInventory() {return this->playeriInventory;}

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

    void setNewThing(int nt) {this-> newThing = nt;}
};




