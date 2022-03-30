#pragma once

#include <Button.hpp>
#include <Godot.hpp>

#include "SceneTree.hpp"
#include "button_pressed.h"
#include "util.h"

namespace godot {
class ButtonQuit : public ButtonPressed<ButtonQuit> {
    GODOT_CLASS_WITH_INIT(ButtonQuit, Button);

    void button_pressed() { get_tree()->quit(0); }
};
} // namespace godot