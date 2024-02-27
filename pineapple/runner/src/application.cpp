#include "application.hpp"
#include <iostream>
namespace runner
{
    static const std::string kPlayerID  = "player";
    static const std::string kBallID      = "ball";
    static const std::string kBrickID     = "brick";
    static const std::string kFallingStarID = "fallingStar";
#pragma warning(push)
#pragma warning(disable : 26455)
    Application::Application() : m_window(sf::VideoMode(1280, 720), "Pineapple", sf::Style::Titlebar | sf::Style::Close)
        , m_AssetsManagement(),
        m_ball(*m_AssetsManagement.GetTexture("ball"), m_window.getSize().x, m_window.getSize().y, 0, 0),
        m_brick(*m_AssetsManagement.GetTexture("brick"), 13, 0, 100, 0.0f),
        m_player(*m_AssetsManagement.GetTexture("player"), 0.0f, static_cast<float>(m_window.getSize().x)),
        m_parallaxBackground(*m_AssetsManagement.GetTexture("fallingStar"))

    {
#pragma warning(push)
#pragma warning(disable : 26446)
        if (!m_window.isOpen()) {
            throw std::runtime_error("Failed to open SFML window");
        }
#pragma warning(pop)
        m_window.setKeyRepeatEnabled(false);

        m_CurrentGameState = TheGamesStates::pregame;

        // Made simple that function that just set indivual each sf::Text variable for text in the screen
        m_startMainuText = m_AssetsManagement.SetText("Press `space´ to start", 100, sf::Text::Bold, 250, 250);
        m_WinText = m_AssetsManagement.SetText("Winner", 50, sf::Text::Bold, 550, 300);
        m_LoseText = m_AssetsManagement.SetText("Game Over", 50, sf::Text::Bold, 550, 300);
        m_ScoreText = m_AssetsManagement.SetText("Score", 50, sf::Text::Bold, 1100, 5);
        m_highScoreText = m_AssetsManagement.SetText("", 50, sf::Text::Bold, 0, 5);

        m_currentScore = 0;
        m_highScoreInt = 0;
        m_minOfScreen = 0.0f;
        loadHighScore();

       
    }
#pragma warning(pop)
    void Application::run()
   {  
      while (m_window.isOpen()) {
         sf::Event event;
         
         while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::MouseMoved) {
               on_mouse_move({ static_cast<float>((event.mouseMove.x)), static_cast<float>((event.mouseMove.y)) });
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
               on_button_pressed(event.mouseButton.button);
            }
            else if (event.type == sf::Event::MouseButtonReleased) {
               on_button_released(event.mouseButton.button);
            } 
            else if (event.type == sf::Event::KeyPressed) {
               on_key_pressed(event.key.code);
            }
            else if (event.type == sf::Event::KeyReleased)
            {
               on_key_released(event.key.code);
            }
            else if (event.type == sf::Event::Closed) {
               m_window.close();
            }
         }
         
         if (!update()) {
            m_window.close();
         }

         render();
      }

      exit();
   }

   bool Application::enter() noexcept
   {
      return true;
   }

   void Application::exit() noexcept
   {
   }

   bool Application::update()
   {
      m_deltatime = m_clock.restart();
      if(m_CurrentGameState == TheGamesStates::running)
      {
        m_parallaxBackground.Update(m_deltatime.asSeconds(), static_cast<float>(m_window.getSize().y));
        m_ScoreText.setString("Score: " + intToString(m_currentScore));
        m_player.PlayerUpdate(m_deltatime.asSeconds());
        m_ball.BallUpdate(m_deltatime.asSeconds());
        CollisionCheck();
      } 
      else
      {
        m_highScoreText.setString("HighScore: " + intToString(m_highScoreInt));
      }
      
      if(m_brick.areBricksGone())
      {
        m_CurrentGameState = TheGamesStates::win;
      }

      return m_running;
   }

   void Application::render()
   {
      m_batch.clear();
      {}
      m_window.clear(sf::Color{ 0x44, 0x55, 0x66, 0xff });

      if(m_CurrentGameState == TheGamesStates::pregame)
      {
          m_window.draw(m_startMainuText);
      }

      if(m_CurrentGameState == TheGamesStates::running)
      {
        m_parallaxBackground.Draw(m_window);
        m_window.draw(m_ScoreText);
        m_player.Draw(m_window);
        m_ball.Draw(m_window);
        m_brick.Draw(m_window);
        
      }

      if(m_CurrentGameState == TheGamesStates::lose)
      {
        m_window.draw(m_LoseText);
        StoreHighScore();
      }
      
      if(m_CurrentGameState == TheGamesStates::win)
      {
          m_window.draw(m_WinText);
          StoreHighScore();
      }

      m_window.draw(m_highScoreText);

      m_batch.present(m_window);
      m_window.display();
   }

   void Application::on_mouse_move(const sf::Vector2f &position) noexcept
   {
      m_mouse_position = position;
   }

   void Application::on_key_pressed(const sf::Keyboard::Key key)
   {
      if (key == sf::Keyboard::Key::Escape) {
         m_running = false;
      }
      if(key == sf::Keyboard::Key::Left)
      {
          m_player.pressedLeft = true;
      } else
      {
          m_player.pressedLeft = false;
      }
      
      if(key == sf::Keyboard::Right)
      {
          m_player.pressedRight = true;
      }
      else
      {
          m_player.pressedRight = false;
      }

      if(m_CurrentGameState == TheGamesStates::pregame)
      {
          if (key == sf::Keyboard::Key::Space) {
              m_CurrentGameState = TheGamesStates::running;
          }
      }

      if(m_CurrentGameState == TheGamesStates::lose || m_CurrentGameState == TheGamesStates::win)
      {
          if (key == sf::Keyboard::Key::Space) {
              m_CurrentGameState = TheGamesStates::running;
              Restart();
          }
      }
   }

   void Application::on_key_released(const sf::Keyboard::Key key) noexcept
   {
       if (key == sf::Keyboard::Right)
       {
           m_player.pressedRight = false;
       }
       if (key == sf::Keyboard::Key::Left)
       {
           m_player.pressedLeft = false;
       }  
   }

   void Application::on_button_pressed(const  sf::Mouse::Button button) noexcept
   {

   }

   void Application::on_button_released(const sf::Mouse::Button button) noexcept
   {

   }

   void Application::Restart()
   {
       m_currentScore = 0;
       m_ball.Restart();
       m_player.Restart();
       m_brick.Restart();
       m_parallaxBackground.Restart();
   }

   void Application::CollisionCheck()
   {
       if (m_player.CheckCollisionWithBall(m_ball))
       {
           m_ball.FlipVertcialDirection();
       }

       auto collidedBrickIndices = m_brick.checkCollisionsWithBall(m_ball);
       for (const int index : collidedBrickIndices)
       {
               m_ball.FlipVertcialDirection();
               m_ball.IncreaseSpeed(10.0f);
               m_brick.deleteBrickAtIndex(index);
               ++m_currentScore;
       }

       if(m_ball.m_ballSprite.getPosition().y >= m_window.getSize().y)
       {
           m_CurrentGameState = TheGamesStates::lose;
       }
   }

   void Application::loadHighScore()
   {
       std::ifstream readFile;
       readFile.open("assets/HighScore.txt");
       if (readFile.is_open())
       {
           while (!readFile.eof())
           {
               readFile >> m_highScoreInt;
           }

       }
       readFile.close();
   };

   void Application::StoreHighScore()
   {

       std::ofstream writeFile("assets/HighScore.txt");
       if (writeFile.is_open())
       {
           if (m_currentScore > m_highScoreInt)
           {
               m_highScoreInt = m_currentScore;
           }
           writeFile << m_highScoreInt;
       }
       writeFile.close();
   }

   std::string Application::intToString(int score)
   {
       std::string string = std::to_string(score);
       return string;
   }
} // !runner
