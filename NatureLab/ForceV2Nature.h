#pragma once

namespace NatureLab {

    struct ForceV2System
    {
        Math::Vector2 _position;
        Math::Vector2 _velocity;
        Math::Vector2 _acceleration;
        float _mass;

        inline ForceV2System() {
            this->_position = Math::Vector2(450, 350);
            this->_velocity = Math::Vector2(0.01f, 0.01f);
            this->_acceleration = Math::Vector2(0.01f, 0.01f);
            this->_mass = 10.0f;
        }

        inline ForceV2System(float mass, Math::Vector2 position = Math::Vector2(50, 600)) {
            this->_position = position;
            this->_velocity = Math::Vector2(0.01f, 0.01f);
            this->_acceleration = Math::Vector2(0.01f, 0.01f);
            this->_mass = mass;
        }

        inline void update(const int& _width, const int& _height, const float deltaTime) {
            _velocity = _velocity + _acceleration;
            _position = _position + _velocity * deltaTime;
            _acceleration = _acceleration * 0.0f;

            this->checkEdges(_width, _height);
        }

        inline void applyForce(Math::Vector2 force) {
            _acceleration = _acceleration + (force / _mass);
        }

        inline void checkEdges(const int& _width, const int& _height) {

            if (_position.x > _width) {
                _position.x = _width;
                _velocity.x *= -1;
            }
            else if (_position.x < 0) {
                _velocity.x *= -1;
                _position.x = 0;
            }
            if (_position.y > _height) {
                _velocity.y *= -1;
                _position.y = _height;
            }
            else if (_position.y < 0) {
                _velocity.y *= -1;
                _position.y = 0;
            }
        }

    };

    class ForceV2Nature : public INature, ITimeEvent {
    public:

        inline ForceV2Nature() {
            this->start();
        }

        inline void start() override {
            INature::start();
            this->_ballTexture = SceneAssets::getTexture("ball");

            this->_wind = Math::Vector2(0.1f, 0);
            this->_gravity = Math::Vector2(0, -9.81f);

            this->_width = SceneAssets::SCREEN_WIDTH - SceneAssets::LIMIT_WIDTH;
            this->_height = SceneAssets::SCREEN_HEIGHT - SceneAssets::LIMIT_HEIGHT;

            this->_frictionMag = _c * _normal;
            this->_friction = Math::Vector2(0.01f, 0.01f);
            

            for (int i = 0; i < _balls; i++)
                _natureSystem.push_back(new ForceV2System(rand() % 30 + 10/*,
                    Math::Vector(1 + rand() % _width, 1 + rand() % _height)*/)
                );
        }

        inline void update() override {
            ITimeEvent::update();
            INature::update();

            for (const auto& it : _natureSystem) {

                this->_friction = it->_velocity;
                this->_friction = this->_friction * -1.0f;
                this->_friction.normalized();
                this->_friction = this->_friction * _frictionMag;
                this->_friction.y *= -1;


                it->applyForce(_friction);
                it->applyForce(_wind);
                //_gravity.y = -it->_mass * 0.1f; // sea el peso de cualquier objeto caer�n a la misma velocidad
                it->applyForce(_gravity);
                it->update(this->_width, this->_height, deltaTime);
            }
        }

        inline void show() override {
            INature::show();
            this->update();
            for (const auto& it : _natureSystem) {
                sprite->draw(_ballTexture, Math::Vector2(it->_position.x, it->_position.y), Math::Vector2(it->_mass * 5.0f, it->_mass * 5.0f), -(float)glfwGetTime() * 50);
            }
        }

    private:

        std::vector<ForceV2System*> _natureSystem;
        Texture2D _ballTexture;

        Math::Vector2 _wind;
        Math::Vector2 _gravity;

        int _width, _height;
        int _balls = 10;

        float _c = 0.01f;
        float _normal = 1.0f;

        float _frictionMag;
        Math::Vector2 _friction;
    };
}