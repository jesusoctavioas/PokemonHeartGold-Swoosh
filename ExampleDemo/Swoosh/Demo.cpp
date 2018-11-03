// Swoosh.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <SFML/Window.hpp>
#include <Swoosh/ActivityController.h>
#include "DemoActivities/MainMenuScene.h"

using namespace swoosh;

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 600), "HeartGold Swoosh");
  window.setFramerateLimit(60); // call it once, after creating the window
  window.setMouseCursorVisible(false);

  ActivityController app(window);
  app.push<MainMenuScene>();

  // run the program as long as the window is open
  float elapsed = 0.0f;
  sf::Clock clock;

  srand((unsigned int)time(0));

  while (window.isOpen())
  {
    clock.restart();

    // check all the window's events that were triggered since the last iteration of the loop
    sf::Event event;
    while (window.pollEvent(event))
    {
      // "close requested" event: we close the window
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    window.clear();
    app.update(elapsed);
    app.draw();

    window.display();

    elapsed = static_cast<float>(clock.getElapsedTime().asSeconds());
  }

  return 0;
}