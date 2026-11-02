#ifndef CONDITION_OBJECTS_PRODUCTS_H
#define CONDITION_OBJECTS_PRODUCTS_H
#include <cstdint>

namespace conditions_products {

enum class reason_code : std::uint8_t
{
    None,
    Damage,
    Returned,
    Expired
};

}

#endif // CONDITION_OBJECTS_PRODUCTS_H
