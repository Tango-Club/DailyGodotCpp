#pragma once

#include <Button.hpp>
#include <Godot.hpp>

#include "SceneTree.hpp"
#include "Viewport.hpp"
#include "button_pressed.h"
#include "util.h"

namespace godot {
class ButtonContinue : public ButtonPressed<ButtonContinue> {
    GODOT_CLASS_WITH_INIT(ButtonContinue, Button);

    void button_pressed() {
        if (has_node(_menu_path)) {
            Node* node = get_node(_menu_path);
            node->queue_free();
        }
    }

    NodePath _menu_path = "/root/Control";
};
} // namespace godot