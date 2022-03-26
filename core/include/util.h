#pragma once

#include <Godot.hpp>
namespace godot {

template <typename T>
concept has_init = requires(T object) {
    object.init();
};

template <has_init T>
void call_if_has_init(T* object) {
    object->init();
}

template <typename T>
void call_if_has_init(T*) {}

#define GODOT_CLASS_WITH_INIT(Name, Base) \
    GODOT_CLASS(Name, Base)               \
public:                                   \
    void _init() { call_if_has_init(this); }

} // namespace godot