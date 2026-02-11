#include "jinput_action_window.h"

void JInputActionWindow::_bind_methods() 
{
    ClassDB::bind_method(D_METHOD("on_close_requested"), &JInputActionWindow::on_close_requested);
}

JInputActionWindow::JInputActionWindow() {
    set_title("My Resource Editor");
    set_size(Vector2i(400, 300));
    set_flag(FLAG_RESIZE_DISABLED, false);

    connect("close_requested", Callable(this, "on_close_requested"));

    setup_ui();
}

void JInputActionWindow::setup_ui() {
    container = memnew(VBoxContainer);
    add_child(container);

    label = memnew(Label);
    label->set_text("Custom Resource Editor Window");
    container->add_child(label);

    auto* close_button = memnew(Button);
    close_button->set_text("Close");
    close_button->connect("pressed", Callable(this, "hide"));
    container->add_child(close_button);
}

void JInputActionWindow::on_close_requested()
{
    hide();
}
