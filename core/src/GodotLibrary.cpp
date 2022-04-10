#include <Godot.hpp>

#include "button_continue.h"
#include "button_pressed_normal.h"
#include "button_quit.h"
#include "controller.h"
#include "menu_cancel.h"

using namespace godot;

extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options* options) {
    Godot::gdnative_init(options);
}

extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options* options) {
    Godot::gdnative_terminate(options);
}

extern "C" void GDN_EXPORT godot_nativescript_init(void* handle) {
    Godot::nativescript_init(handle);

    register_class<Controller>();
    register_class<ButtonQuit>();
    register_class<ButtonTestStart>();
    register_class<MenuCancel>();
    register_class<ButtonContinue>();
    register_class<ButtonMainMenu>();
}