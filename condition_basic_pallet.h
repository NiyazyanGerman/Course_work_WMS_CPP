#ifndef CONDITION_BASIC_PALLET_H
#define CONDITION_BASIC_PALLET_H

#include <cstdint>
#include <memory>
namespace condition_basic_pallet {

enum class status_code_pallete : std::uint8_t{
None,
InPath,
OnControll,
SetInCell,
InZone,
Blocked,
Exit
};

struct passport_basic_pallet
{
    std::unique_ptr<char[]> unique_id;
    status_code_pallete status_code{status_code_pallete::None};

};

class property_basic_pallet
{

};



}

#endif // CONDITION_BASIC_PALLET_H
