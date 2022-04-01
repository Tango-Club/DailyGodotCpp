#pragma once

#include <Button.hpp>
#include <Godot.hpp>
#include <SceneTree.hpp>
#include <Viewport.hpp>

#include "button_pressed.h"
#include "util.h"

namespace godot {
class ButtonMainMenu : public ButtonPressed<ButtonMainMenu> {
    GODOT_CLASS_WITH_INIT(ButtonMainMenu, Button);

    void button_pressed() {
        util::remove_all_child(get_tree()->get_root());
        get_tree()->change_scene("res://scene/menu/menu_main.tscn");
    }

    NodePath _menu_path = "/root/Control";
};
} // namespace godot