#pragma once

#include <Godot.hpp>
#include <Input.hpp>
#include <KinematicBody2D.hpp>

#include "util.h"

namespace godot {
class Controller : public KinematicBody2D {
    GODOT_CLASS_WITH_INIT(Controller, KinematicBody2D);

public:
    static void _register_methods() { register_method("_process", &Controller::_process); }
    void _process() {
        _update_motion_from_input();
        move_and_slide(_motion);
    }

private:
    int _speed = init_speed;
    Vector2 _motion;

    void _update_motion_from_input() {
        _motion = Vector2(0, 0);
        Input* input = Input::get_singleton();

        if (input->is_action_pressed("ui_up")) {
            _motion.y -= static_cast<float>(_speed);
        }
        if (input->is_action_pressed("ui_down")) {
            _motion.y += static_cast<float>(_speed);
        }
        if (input->is_action_pressed("ui_left")) {
            _motion.x -= static_cast<float>(_speed);
        }
        if (input->is_action_pressed("ui_right")) {
            _motion.x += static_cast<float>(_speed);
        }
    }

    static const int init_speed = 500;
};
} // namespace godot