/////////////////////////////////////////////////////////////////////
/// Students 1239448 & 1101946
/// \date    14/9/17
/// \brief   Enemy ship types
///
/// \copyright (c) 2017 Tyson Cross and Chris Maree, Wits University
/////////////////////////////////////////////////////////////////////

#ifndef PROJECT_ENEMYSHIP_HPP
#define PROJECT_ENEMYSHIP_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
#include <cmath>
#include "common.hpp"
#include "Entity.hpp"
#include "ResourceHolder.hpp"
#include "SoundController.hpp"

enum MovementState
{
    SpiralOut=0,
    SpiralIn,
    CircleOffsetLeft,
    CircleOffsetRight,
    FigureOfEight
};

enum MovementDirection
{
    Clockwise=0,
    CounterClockwise
};

class Enemy : public Entity
{
public:
    Enemy(const sf::Vector2i &resolution,
          float distanceFromCentre,
          float angle,
          float scale,
          const entity::ID type,
          const TextureHolder &textureHolder,
          const textures::ID id,
          MovementState movementState,
          MovementDirection movementDirection);

    void setMove(float angle, float distance) override;
    void setMove(float angle, float distance, float xOffset, float yOffset);
    void setMovementState(MovementState movementState);

    void move() override;
    void reset() override;
    void update() override;
    const float getRadius() const override;
    const float getDistanceFromCentre() const override;
    const float getAngleWithOffset();
    const sf::Vector2f getPosition() const override;
    const sf::Sprite &getSprite() const override;
    const sf::Vector2f getScale() const override;
    const int getLives() const override;
    const void die() override;
    const entity::ID getType();

    const MovementState getMovementState();
    const int getMovementDirectionSign();
    const float getDistanceFromCentreWithOffset() const;
    const float getOffsetX();
    const float getOffsetY();
    void setShoot();
    bool isShooting();
    float getAngle();
    float getDirectionAngle();
    void resetShootTimer();
    const float getShootTimerElapsedTime() const;


private:
    void shoot();

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
//    sf::Sound _soundShoot;
    float _angleOrientation;
    bool _isShooting;
    sf::Vector2<float> _prevPosition,
                        _newPosition,
                        _pointingPosition;
    float _xOffset;
    float _yOffset;
    sf::Clock _timerShoot;

    MovementState _movementState;
    MovementDirection _movementDirection;
};

#endif //PROJECT_ENEMYSHIP_HPP