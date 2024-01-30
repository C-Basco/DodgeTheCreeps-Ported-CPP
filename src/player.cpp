#include "player.h"
#include <godot_cpp\godot.hpp>
#include <godot_cpp\variant\vector2.hpp>
#include <godot_cpp\variant\utility_functions.hpp>
#include <godot_cpp\classes\input.hpp>
#include <godot_cpp\classes\engine.hpp>
#include <godot_cpp\classes\animated_sprite2d.hpp>
#include <godot_cpp\classes\collision_shape2d.hpp>
#include <godot_cpp\variant\rect2.hpp>

using namespace godot;

void Player::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_speed", "p_speed"), &Player::set_speed);
    ClassDB::bind_method(D_METHOD("get_speed"), &Player::get_speed);
    ClassDB::add_property("Player", PropertyInfo(Variant::FLOAT, "speed"), "set_speed", "get_speed");
    ClassDB::bind_method(D_METHOD("start", "pos"), &Player::start);

    ADD_SIGNAL(MethodInfo("hit"));

}

Player::Player(){
    if(Engine::get_singleton()->is_editor_hint()){
        set_process_mode(Node::ProcessMode::PROCESS_MODE_DISABLED);
    }
    speed = 400;

}

Player::~Player(){
    // Add your cleanup here.
}

void Player::_process(double delta) {
    velocity = Vector2(0.0f, 0.0f);
    if (Input::get_singleton()->is_action_pressed("move_right")){
        velocity.x += 1.0f;
    }
    if (Input::get_singleton()->is_action_pressed("move_left")){
        velocity.x -= 1.0f;
    }
    if (Input::get_singleton()->is_action_pressed("move_down")){
        velocity.y += 1.0f;
    }
    if (Input::get_singleton()->is_action_pressed("move_up")){
        velocity.y -= 1.0f;
    }

    animeSprite2D =  get_node<AnimatedSprite2D>("AnimatedSprite2D");

    if (velocity.length() > 0){
        velocity = velocity.normalized() * speed;
        animeSprite2D->play();
    } else{
        animeSprite2D->stop();
    }

    //restrict player movement to given range.
    position = get_position() + velocity * delta;
    set_position(position.clamp(Vector2(0.0f, 0.0f), screen_size));
    

    //Change animation based on its direction
    if (velocity.x != 0){
        animeSprite2D->set_animation("walk");
        animeSprite2D->set_flip_v(false);
    }
    else if (velocity.y != 0){
        animeSprite2D->set_animation("up");
        animeSprite2D->set_flip_v(velocity.y > 0);
    }
}

void Player::start(Vector2 pos){
    Vector2 position = pos;
    show();
    collision_shape2d = get_node<CollisionShape2D>("CollisionShape2D");
    if (collision_shape2d){
        collision_shape2d->set_disabled(false);
    }
}

void Player::set_speed(const double p_speed) {
    speed = p_speed;
}

double Player::get_speed() const {
    return speed;
}

void Player::_ready(){
    Vector2 view_size = get_viewport_rect().get_size();
    hide();
    screen_size = view_size;
    
}
