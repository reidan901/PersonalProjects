#include <SFML/Graphics.hpp>
#include "Rasterizer.h"
#include "CameraSingleton.h"
int main(void) {

    Rasterizer x;
    sf::Image image=x.Rasterization();
    sf::RenderWindow window(sf::VideoMode(512,512),"Rasterizer");
    sf::Texture texture;
    texture.loadFromImage(image);    
    sf::Sprite sprite;
    sprite.setTexture(texture);
    while (window.isOpen())
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            CameraSingleton::GetInstance().MoveLeft();
            image = x.Rasterization();
            texture.loadFromImage(image);
            sprite.setTexture(texture);
        }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                CameraSingleton::GetInstance().MoveRight();
                image = x.Rasterization();
                texture.loadFromImage(image);
                sprite.setTexture(texture);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                CameraSingleton::GetInstance().MoveUp();
                image = x.Rasterization();
                texture.loadFromImage(image);
                sprite.setTexture(texture);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                CameraSingleton::GetInstance().MoveDown();
                image = x.Rasterization();
                texture.loadFromImage(image);
                sprite.setTexture(texture);
            }
      
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                CameraSingleton::GetInstance().MoveForwards();
                image = x.Rasterization();
                texture.loadFromImage(image);
                sprite.setTexture(texture);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                CameraSingleton::GetInstance().MoveBackwards();
                image = x.Rasterization();
                texture.loadFromImage(image);
                sprite.setTexture(texture);
            }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
            CameraSingleton::GetInstance().RotateLeft();
            image = x.Rasterization();
            texture.loadFromImage(image);
            sprite.setTexture(texture);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        {
            CameraSingleton::GetInstance().RotateRight();
            image = x.Rasterization();
            texture.loadFromImage(image);
            sprite.setTexture(texture);
        }
        window.clear();
        window.draw(sprite);
        window.display();
    }
    return 0;
}
