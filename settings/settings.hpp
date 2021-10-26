#include <string>
#include <map>

namespace Settings {
    bool RunGame       = true;
    bool GameProccesse = true;
    bool Saved         = true;

    std::string NameOfJsonFile = "main.json";

    std::map<std::string, int> __dict__ = {
        {"hp"                        , 0},
        {"exp"                       , 1},
        {"level"                     , 2},
        {"damage"                    , 3},
        {"possibility_of_hit"        , 4},
        {"possibility_of_protection" , 5},
        {"possibility_to_fend_off"   , 6},
        {"count_of_batle"            , 7}
    };
}


namespace PlayerItems {
    // [0] - индекс вещей
    // [1] - урон(защита)
    std::map<int, int> THINGS_FOR_ARMS_ATTACK    = {
        {0, 2}, {1, 3}, {2, 7}, {3, 15}
    };
    std::map<int, int> THINGS_FOR_ARMS_DEFENCE   = {
        {0, 5}, {1, 10}, {2, 15}
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


enum class Colors {
    BLUE = 1,
    GREEN = 2,
    CYAN = 3,
    RED = 4
};