#ifndef PLAYER_H
#define PLAYER_H

#include <godot_cpp\core\class_db.hpp>
#include <godot_cpp\classes\area2d.hpp>
#include <godot_cpp\classes\node2d.hpp>
#include <godot_cpp\variant\vector2.hpp>
#include <godot_cpp\classes\animated_sprite2d.hpp>
#include <godot_cpp\classes\collision_shape2d.hpp>

namespace godot {
    class Player : public Area2D
    {
        GDCLASS(Player, Area2D)

        private:
            int speed;
            Vector2 velocity;
        
        protected:
            static void _bind_methods();


        public:
            Player();
            ~Player();

            Vector2 screen_size;
            Vector2 position;
            CollisionShape2D* collision_shape2d;
            AnimatedSprite2D* animeSprite2D;

            void _process(double delta) override;
            void set_speed(const double p_speed);
            double get_speed() const;
            void start(Vector2 pos);
            void _ready() override;


    };
}

#endif
