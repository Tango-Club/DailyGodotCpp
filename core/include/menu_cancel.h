#pragma once

#include <Godot.hpp>
#include <Input.hpp>
#include <Node2D.hpp>
#include <NodePath.hpp>
#include <PackedScene.hpp>
#include <ResourceLoader.hpp>
#include <SceneTree.hpp>
#include <Viewport.hpp>

#include "util.h"

namespace godot {
class MenuCancel : public Node2D {
    GODOT_CLASS_WITH_INIT(MenuCancel, Node2D);

public:
    static void _register_methods() { register_method("_process", &MenuCancel::_process); }
    void _process() {
        Input* input = Input::get_singleton();
        if (input->is_action_just_pressed("ui_cancel")) {
            _cancel_pressed();
        }
    }

private:
    void _cancel_pressed() {
        if (!has_node(_menu_path)) {
            Ref<PackedScene> current_scene =
                    ResourceLoader::get_singleton()->load("res://scene/menu/menu_cancel.tscn");
            get_tree()->get_root()->add_child(current_scene->instance());
        } else {
            Node* node = get_node(_menu_path);
            node->queue_free();
        }
    }

    NodePath _menu_path = "/root/Control";
};
} // namespace godot