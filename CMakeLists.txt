cmake_minimum_required(VERSION 3.14)
project(AICourseCPP)
set(CMAKE_CXX_STANDARD 14)
set(QT_ROOT_DIR /Users/sam/QT/5.13.0/5.13.0/clang_64)
set(OPENSSL_ROOT_DIR /usr/local/opt/openssl)
find_package(Qt5Widgets)
find_package(Qt5Core)
find_package(Qt5Network)
find_package(Qt5NetworkAuth)
find_package(curl)
find_package(openssl)


set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

INCLUDE_DIRECTORIES(form
        src
        third/aip-cpp-sdk-0.8.4
        /usr/local/opt/jsoncpp/include
        /usr/local/opt/openssl/include
        )

qt5_wrap_ui(UI_FILES form/form.ui)

set(UI_SRC form/InputWidget.cpp form/InputWidget.h)
aux_source_directory(src SRC)

link_directories(/usr/local/opt/jsoncpp/lib
        /usr/local/opt/openssl/lib
        )

add_executable(AICourseCPP
        ${UI_FILES}
        ${UI_SRC}
        ${SRC}
        main.cpp)

qt5_use_modules(AICourseCPP Core Widgets Network NetworkAuth)

target_link_libraries(AICourseCPP
        Qt5::Widgets
        Qt5::Network
        Qt5::NetworkAuth
        curl
        crypto
        jsoncpp
        )