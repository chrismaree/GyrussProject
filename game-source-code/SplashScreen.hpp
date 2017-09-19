/////////////////////////////////////////////////////////////////////
/// Students 1239448 & 1101946
/// \date    2017/09/10
/// \brief   Simple Splash Screen
///
/// Implementation of showing a splash screen
///
/// \copyright (c) 2017 Tyson Cross and Chris Maree, Wits University
/////////////////////////////////////////////////////////////////////

#ifndef PROJECT_SPLASHSCREEN_H
#define PROJECT_SPLASHSCREEN_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "SFML/Graphics.hpp"
#include "ResourceHolder.hpp"

////////////////////////////////////////////////////////////
/// \brief A Splashscreen, with information on how to play
/// the game, titles, controls and version information
///
////////////////////////////////////////////////////////////
class SplashScreen
{
public:

////////////////////////////////////////////////////////////
/// \brief Shows the Splash screen
///
/// \param window The sf:Window object to draw and render to
/// \param resourceMapper The resourceMapper containing assets for the splashscreen
///
/// \see sf::Window
/// \see ResourceMapper
///
////////////////////////////////////////////////////////////
    int show(sf::RenderWindow &window,
             const TextureHolder &textureHolder,
             const SoundHolder &soundHolder,
             const FontHolder &fontHolder,
             const sf::Vector2i);
private:
    ////////////////////////////////////////////////////////////
/// \brief Loops through fading in and out a text object
///
/// \param text The sf:Text object to fade in and out
/// \param color The sf::Color to fade up to
/// \param frequency The frequency of the fade
/// \param frequency The frequency of the fade
/// \param clock A changing value to alter the time step
///
/// \see sf:Text
/// \see sf::Color
///
////////////////////////////////////////////////////////////
    void fadeTextInAndOut(sf::Text &text,
                          sf::Color color,
                          int frequency,
                          sf::Clock& clock);
};

#endif //PROJECT_SPLASHSCREEN_H