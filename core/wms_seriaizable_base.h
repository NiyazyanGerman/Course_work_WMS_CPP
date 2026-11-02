#ifndef WMS_SERIAIZABLE_BASE_H
#define WMS_SERIAIZABLE_BASE_H

#include"../format_mwms/file_formater.h"
#include<memory>

template<std::size_t N>
struct FixedString
{

    constexpr FixedString(const char (&str)[N])
    {
        std::ranges::copy_n(str,N,name_format);
    }

    constexpr bool operator==(const FixedString& other)
    {
        return std::equal(name_format,name_format + N,other.name_format);
    }

char name_format[N];

};


template<FixedString format_name, typename Type>
struct Binding
{
    using type = Type;
};

template<FixedString TargetName, typename... Bindings>
struct TypeRegistry;



template<FixedString TargetName, typename FirstType, typename... Rest>
struct TypeRegistry<TargetName, Binding<TargetName, FirstType>, Rest...> {
    using type = FirstType;
};

template<FixedString TargetName, typename NotMatchBinding, typename... Rest>
struct TypeRegistry<TargetName, NotMatchBinding, Rest...> {
    using type = typename TypeRegistry<TargetName, Rest...>::type;
};


template<FixedString TargetName, typename... Bindings>
using GetTypeByBoundName = typename TypeRegistry<TargetName, Bindings...>::type;


class wms_seriaizable_base
{
public:
    wms_seriaizable_base();
protected:
    template<typename... AllBindings>
    struct schema
    {
        template<FixedString name>
        using TypeOf = GetTypeByBoundName<name,AllBindings...>;
    };

public:
    file_formater formater();
};





#endif // WMS_SERIAIZABLE_BASE_H
