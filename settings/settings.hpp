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