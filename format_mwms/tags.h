#ifndef TAGS_H
#define TAGS_H
#include<string_view>


namespace mwms::tags {


constexpr std::string_view Version = "V";

//Topology physical warehouse
constexpr std::string_view Zone = "Z";
constexpr std::string_view Row = "R";
constexpr std::string_view Section = "S";
constexpr std::string_view Tier = "T";
constexpr std::string_view Cell = "C";

// Topology condition pallete
constexpr std::string_view EUR = "EUR";
constexpr std::string_view FIN = "FIN";
constexpr std::string_view USA = "USA";


}



#endif // TAGS_H
