#pragma once

#include <Button.hpp>
#include <Godot.hpp>

namespace godot {
template <typename Derived>
class ButtonPressed : public Button {
public:
    void init() { connect("pressed", this, "_button_pressed"); }
    static void _register_methods() {
        register_method("_button_pressed", &Derived::button_pressed);
    }
};
} // namespace godot