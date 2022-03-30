#pragma once
#include <Button.hpp>
#include <Godot.hpp>

#include "SceneTree.hpp"
#include "button_pressed.h"
#include "util.h"

namespace godot {
class ButtonTestStart : public ButtonPressed<ButtonTestStart> {
    GODOT_CLASS_WITH_INIT(ButtonTestStart, Button);

    void button_pressed() { get_tree()->change_scene("res://scene/test_start.tscn"); }
};
} // namespace godot