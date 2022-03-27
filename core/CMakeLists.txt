project(DailyGodotCpp CXX)

add_library(DailyGodotCpp SHARED
            src/GodotLibrary.cpp
            include/controller.h
            include/button_quit.h
            include/button_test_start.h
            include/menu_cancel.h
            )

target_link_libraries(DailyGodotCpp PUBLIC godot-cpp)

target_include_directories(DailyGodotCpp
                           PUBLIC
                           $<INSTALL_INTERFACE:include>
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                           PRIVATE
                           ${CMAKE_CURRENT_SOURCE_DIR}/src
                           )