cmake_minimum_required(VERSION 3.16)

project(cpp_zs2024_xkorcak VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appcpp_zs2024_xkorcak
    main.cpp
)

qt_add_qml_module(appcpp_zs2024_xkorcak
    URI cpp_zs2024_xkorcak
    VERSION 1.0
    QML_FILES
        Main.qml
        SOURCES Position.h
        SOURCES Unit.h Unit.cpp
        SOURCES GroundType.h
        SOURCES AttackUnit.h AttackUnit.cpp
        SOURCES BuildUnit.h BuildUnit.cpp
        SOURCES HealUnit.h HealUnit.cpp
        SOURCES MapObject.h MapObject.cpp
        SOURCES Map.h Map.cpp
        SOURCES Player.h Player.cpp
        SOURCES Game.h Game.cpp
        SOURCES GameContext.h GameContext.cpp
        SOURCES
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appcpp_zs2024_xkorcak PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appcpp_zs2024_xkorcak
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appcpp_zs2024_xkorcak
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appcpp_zs2024_xkorcak
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
