#pragma once

#include <Godot.hpp>
#include <Input.hpp>
#include <Node2D.hpp>

#include "PackedScene.hpp"
#include "ResourceLoader.hpp"
#include "SceneTree.hpp"
#include "Viewport.hpp"
#include "util.h"

namespace godot {
class MenuCancel : public Node2D {
    GODOT_CLASS_WITH_INIT(MenuCancel, Node2D);

public:
    static void _register_methods() { register_method("_process", &MenuCancel::_process); }
    void _process() {
        Input* input = Input::get_singleton();
        if (input->is_action_just_pressed("ui_cancel")) {
            if (_current_instance == nullptr) {
                Ref<PackedScene> current_scene =
                        ResourceLoader::get_singleton()->load("res://scene/menu/menu_cancel.tscn");
                _current_instance = current_scene->instance();
                get_tree()->get_root()->add_child(_current_instance);
            } else {
                get_tree()->get_root()->remove_child(_current_instance);
                _current_instance->free();
                _current_instance = nullptr;
            }
        }
    }

private:
    Node* _current_instance;
};
} // namespace godot