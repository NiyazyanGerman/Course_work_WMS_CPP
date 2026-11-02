#ifndef CELL_PLACE_H
#define CELL_PLACE_H
#include<memory>

class object_product;

class cell_place
{
    using text_ptr = std::unique_ptr<char[]>;


   // std::unique_ptr<object_product> current_product_in_cell; // bytes 8
    text_ptr unique_indeficator_cell = nullptr; // 4 bytes
    text_ptr zone; // 8 bytes
    text_ptr row; // 8 bytes
    text_ptr section; // 8 bytes
    text_ptr level; // 8 bytes

    short id_Shelving_in_warehouse; // 2 bytes

public:
    cell_place() = default;

};


#endif // CELL_PLACE_H
