#pragma once

#include <Godot.hpp>
#include <Input.hpp>
#include <KinematicBody2D.hpp>

namespace godot {
class Controller : public KinematicBody2D {
private:
    GODOT_CLASS(Controller, KinematicBody2D)
public:
    static void _register_methods() {
        register_method((char*)"_process", &Controller::_process);
        register_property((char*)"_speed", &Controller::_speed, 200);
    }
    void _init() { _motion = Vector2(0, 0); }
    void _process() {
        _updateMotionFromInput();
        move_and_slide(_motion);
    }

private:
    int _speed = 500;
    Vector2 _motion;

    void _updateMotionFromInput() {
        _motion = Vector2(0, 0);
        Input* input = Input::get_singleton();

        if (input->is_action_pressed("ui_up")) {
            _motion.y -= _speed;
        }
        if (input->is_action_pressed("ui_down")) {
            _motion.y += _speed;
        }
        if (input->is_action_pressed("ui_left")) {
            _motion.x -= _speed;
        }
        if (input->is_action_pressed("ui_right")) {
            _motion.x += _speed;
        }
    }
};
} // namespace godot