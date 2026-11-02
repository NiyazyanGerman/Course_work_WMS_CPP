#ifndef OBJECT_PRODUCT_H
#define OBJECT_PRODUCT_H
#include <cstdint>
#include <memory>
#include<QImage>

class cell_place;

class object_product
{
  //  std::unique_ptr<cell_place> current_product_location; // very big 32 bytes
    std::unique_ptr<char[]> name_product; // 8 bytes
    std::unique_ptr<char[]> sku;
    std::unique_ptr<char[]> barcode_product;



public:
    object_product();
};

#endif // OBJECT_PRODUCT_H
