cmake_minimum_required(VERSION 3.16)

project(medieval-tactics VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(app-medieval-tactics
    main.cpp
    assets.qrc
)

qt_add_qml_module(app-medieval-tactics
    URI medieval-tactics
    VERSION 1.0
    QML_FILES
        Main.qml
        SOURCES Position.h
        SOURCES Unit.h Unit.cpp
        SOURCES GroundType.h
        SOURCES UnitType.h
        SOURCES AttackUnit.h AttackUnit.cpp
        SOURCES BuildUnit.h BuildUnit.cpp
        SOURCES HealUnit.h HealUnit.cpp
        SOURCES MapObject.h MapObject.cpp
        SOURCES Map.h Map.cpp
        SOURCES Player.h Player.cpp
        SOURCES Game.h Game.cpp
        SOURCES GameContext.h GameContext.cpp
        QML_FILES UnitControls.qml
        QML_FILES Button.qml
        QML_FILES Menu.qml
        QML_FILES Unit.qml
        QML_FILES MapObject.qml
        SOURCES IQMLSerializable.h
        QML_FILES Map.qml
        RESOURCES assets.qrc
        QML_FILES Game.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(app-medieval-tactics PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appcpp_zs2024_xkorcak
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(app-medieval-tactics
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS app-medieval-tactics
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
