cmake_minimum_required(VERSION 3.19)
project(WMS LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build static libraries" FORCE)

set(ZXING_WRITERS ON CACHE BOOL "Enable barcode generation" FORCE)
set(ZXING_READERS OFF CACHE BOOL "Disable barcode reading" FORCE)
set(ZXING_DEPENDENCIES OFF CACHE BOOL "Disable external deps" FORCE)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_BLACKBOX_TESTS OFF CACHE BOOL "" FORCE)
set(BUILD_UNIT_TESTS OFF CACHE BOOL "" FORCE)
set(ZXING_USE_QT OFF CACHE BOOL "Disable Qt integration in ZXing" FORCE)

set(OLD_AUTOMOC ${CMAKE_AUTOMOC})
set(CMAKE_AUTOMOC OFF)

add_subdirectory(barcode_lib/zxing-cpp/core)

set(CMAKE_AUTOMOC ${OLD_AUTOMOC})

include_directories(barcode_lib/zxing-cpp/core/src)

qt_add_executable(WMS
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui

    cell_place.h
    condition_objects_products.h
    object_product.h
    cell_place.cpp
    condition_objects_products.cpp
    object_product.cpp
    basic_pallet.h basic_pallet.cpp
    condition_basic_pallet.h condition_basic_pallet.cpp

    add_new_product_form.h add_new_product_form.cpp add_new_product_form.ui
    barcode_this_product.h barcode_this_product.cpp
    format_mwms/tags.h
    format_mwms/file_formater.h format_mwms/file_formater.cpp
    format_mwms/serializer.h format_mwms/serializer.cpp
    core/wms_seriaizable_base.cpp core/wms_seriaizable_base.h
)

target_link_libraries(WMS
    PRIVATE
        Qt::Core
        Qt::Widgets
        ZXing
)

install(TARGETS WMS
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET WMS
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
