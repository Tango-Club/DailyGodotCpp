#pragma once

#include <Godot.hpp>
#include <Node.hpp>

#define GODOT_CLASS_WITH_INIT(Name, Base) \
    GODOT_CLASS(Name, Base)               \
public:                                   \
    void _init() {                        \
        util::call_if_has_init(this);     \
    }

namespace godot::util {

template <typename T>
concept has_init = requires(T object) {
    object.init();
};

template <has_init T>
void call_if_has_init(T* object) {
    object->init();
}

template <typename T>
void call_if_has_init(T* /*unused*/) {}

void remove_all_child(Node* node) {
    if (node == nullptr) {
        return;
    }

    Array children = node->get_children();
    for (int i = 0; i < children.size(); i++) {
        Node* child = children[i];
        child->queue_free();
    }
}

} // namespace godot::util
