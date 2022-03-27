#pragma once

#include <Button.hpp>
#include <Godot.hpp>

#include "SceneTree.hpp"
#include "util.h"

namespace godot {
class ButtonQuit : public Button {
    GODOT_CLASS_WITH_INIT(ButtonQuit, Button);

public:
    void init() { connect("pressed", this, "_button_pressed"); }
    static void _register_methods() {
        register_method("_button_pressed", &ButtonQuit::_button_pressed);
    }

private:
    void _button_pressed() { get_tree()->quit(); }
};
} // namespace godot