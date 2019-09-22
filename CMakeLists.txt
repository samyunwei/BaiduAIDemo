cmake_minimum_required(VERSION 3.14)
project(AICourseCPP)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_PREFIX_PATH /Users/sam/QT/5.13.0/5.13.0/clang_64) #这里需要填入自己安装的路径

find_package(Qt5Widgets)
find_package(Qt5Core)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

INCLUDE_DIRECTORIES(form
        src
        )

qt5_wrap_ui(UI_FILES form/form.ui)

set(UI_SRC form/InputWidget.cpp form/InputWidget.h)
aux_source_directory(src SRC)

add_executable(AICourseCPP
        ${UI_FILES}
        ${UI_SRC}
        ${SRC}
        main.cpp)

qt5_use_modules(AICourseCPP Core Widgets Gui)

target_link_libraries(AICourseCPP Qt5::Widgets)