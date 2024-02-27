#pragma once

#include <fstream>
#include <string>
#include "batch.hpp"
#include "PlayerCharacter.h"
#include "Ball.h"
#include "Brick.h"
#include "AssetsManagment.h"
#include "ParallaxBackground.h"
#include "Utility.h"

namespace runner
{
   class Application final
   {
   public:
      Application();

      void run();

   private:
      enum class TheGamesStates
      {
          win, lose, running, pregame
      };
      enum class TextureName
      {
          Texture_player, Texture_ball, Texture_brick  
      };
      bool enter() noexcept;
      void exit() noexcept;
      bool update();
      void render();
      void CollisionCheck();
      void Restart();
   private:
      void on_mouse_move(const sf::Vector2f &position) noexcept;
      void on_key_pressed(const sf::Keyboard::Key key);
      void on_key_released(const sf::Keyboard::Key key) noexcept;
      void on_button_pressed(const sf::Mouse::Button button) noexcept;
      void on_button_released(const sf::Mouse::Button button) noexcept;
      void loadHighScore();
      void StoreHighScore();
      std::string intToString(int score);
      bool AxisAlignedBoundingBox(const sf::Sprite& box1, const sf::Sprite& box2);


   private:
      sf::RenderWindow   m_window;
      PrimitiveBatch     m_batch;
      bool               m_running = true;
      sf::Clock          m_clock;
      sf::Time           m_deltatime;
      sf::Vector2f       m_mouse_position;
      AssetsManagement   m_AssetsManagement{};
      sf::Sprite         m_sprite{};
      PlayerCharacter    m_player;
      Ball               m_ball;
      BrickContainer     m_brick;
      parallaxBackground m_parallaxBackground;
      
      TheGamesStates   m_CurrentGameState;
      sf::Text m_startMainuText, m_WinText, m_LoseText, m_ScoreText, m_highScoreText;
      int m_highScoreInt, m_currentScore;
      float m_minOfScreen;
   };
} // !runner
