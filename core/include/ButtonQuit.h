#pragma once

#include <Button.hpp>
#include <Godot.hpp>
#include <Input.hpp>

#include "SceneTree.hpp"

namespace godot {
class ButtonQuit : public Button {
private:
    GODOT_CLASS(ButtonQuit, Button)
public:
    static void _register_methods() {
        register_method((char*)"_process", &ButtonQuit::_process);
        register_method((char*)"_button_pressed", &ButtonQuit::_button_pressed);
    }
    void _init() { connect("pressed", this, "_button_pressed"); }
    void _process() {}

private:
    void _button_pressed() { get_tree()->quit(); }
};
} // namespace godot