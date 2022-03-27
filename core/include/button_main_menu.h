#pragma once

#include <Button.hpp>
#include <Godot.hpp>

#include "SceneTree.hpp"
#include "Viewport.hpp"
#include "util.h"

namespace godot {
class ButtonMainMenu : public Button {
    GODOT_CLASS_WITH_INIT(ButtonMainMenu, Button);

public:
    void init() { connect("pressed", this, "_button_pressed"); }
    static void _register_methods() {
        register_method("_button_pressed", &ButtonMainMenu::_button_pressed);
    }

private:
    void _button_pressed() {
        util::remove_all_child(get_tree()->get_root());
        get_tree()->change_scene("res://scene/menu/menu_main.tscn");
    }

    NodePath _menu_path = "/root/Control";
};
} // namespace godot