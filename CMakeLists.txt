cmake_minimum_required(VERSION 3.20)
project(RXFG_RXSR)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick Qml)

qt_standard_project_setup()

qt_add_executable(RXFG_RXSR
    src/app/main.cpp
)

qt_add_qml_module(RXFG_RXSR
    URI RXFG
    VERSION 1.0
    QML_FILES
        qml/Main.qml
        qml/Dashboard.qml
        qml/Navigation.qml
        qml/components/FrostedGlassCard.qml
)

target_include_directories(RXFG_RXSR PRIVATE include)

target_link_libraries(RXFG_RXSR PRIVATE
    Qt6::Quick
    Qt6::Qml
)
