#pragma once

#include <Button.hpp>
#include <Godot.hpp>
#include <SceneTree.hpp>
#include <Viewport.hpp>
#include <string_view>

#include "button_pressed.h"
#include "path.h"
#include "util.h"

namespace godot {

#define CREATE_BUTTON_PRESSED_NORMAL(NAME, PATH)                    \
    class NAME : public ButtonPressed<NAME> {                       \
        GODOT_CLASS_WITH_INIT(NAME, Button);                        \
        void button_pressed() {                                     \
            util::remove_all_child(Button::get_tree()->get_root()); \
            Button::get_tree()->change_scene(PATH);                 \
        }                                                           \
    };

CREATE_BUTTON_PRESSED_NORMAL(ButtonMainMenu, scene_path::main_menu);
CREATE_BUTTON_PRESSED_NORMAL(ButtonTestStart, scene_path::test_start);

} // namespace godot
