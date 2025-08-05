qt_add_executable(appCounterCustomType
    ./src/main.cpp
)

qt_add_qml_module(appCounterCustomType
    URI CounterCustomType
    VERSION 1.0
    QML_FILES
        ./qml/Main.qml
    SOURCES
        ./inc/counter.hpp
        ./src/counter.cpp
)

target_include_directories(appCounterCustomType PUBLIC ./inc/)

