#pragma once

#include <Button.hpp>
#include <Godot.hpp>

#include "SceneTree.hpp"
#include "Viewport.hpp"
#include "util.h"

namespace godot {
class ButtonContinue : public Button {
    GODOT_CLASS_WITH_INIT(ButtonContinue, Button);

public:
    void init() { connect("pressed", this, "_button_pressed"); }
    static void _register_methods() {
        register_method("_button_pressed", &ButtonContinue::_button_pressed);
    }

private:
    void _button_pressed() {
        if (has_node(_menu_path)) {
            Node* node = get_node(_menu_path);
            node->queue_free();
        }
    }

    NodePath _menu_path = "/root/Control";
};
} // namespace godot