#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <memory>

struct shapesSpeed
{
    float x;
    float y;
};

enum class Color { Red, Green, Blue };
enum class shape_type { Rectangle, Circle, Polygon};

class Shape
{
    std::shared_ptr<sf::Shape> sfShape;
    shapesSpeed speed;
    float xSize;
    float ySize;

    void setColor(Color color)
    {
        switch(color) {
            case Color::Red:
                sfShape->setFillColor(sf::Color(250, 30, 30));
                break;
            case Color::Green:
                sfShape->setFillColor(sf::Color(25, 250, 30));
                break;
        }
    }

public:
    Shape(float xS, float yS, shape_type shape_t, Color color) : xSize{xS * 2}, ySize{yS * 2} 
    {
        int shape_s = 1;
        switch(shape_t) {
            case shape_type::Circle:
                sfShape = std::make_shared<sf::CircleShape>(xS);
                break;
            case shape_type::Rectangle:
                sfShape = std::make_shared<sf::RectangleShape>(sf::Vector2f(xS, yS));
                break;
            default:
                sfShape = std::make_shared<sf::CircleShape>(xS, 4);
        }

        sfShape->setPosition(100.0f,100.0f);
        setColor(color);
        speed.x = speed.y = 1.0f;
    }

    void checkBorder(float w, float h)
    {
        if(w <= sfShape->getPosition().x + xSize || 0 >= sfShape->getPosition().x)
            speed.x *= -1.0f;
        if(h <= sfShape->getPosition().y + ySize || 0 >= sfShape->getPosition().y)
            speed.y *= -1.0f;
    }

    void updatePos(float w, float h)
    {
        sfShape->setPosition(sfShape->getPosition().x + speed.x, sfShape->getPosition().y + speed.y);
        checkBorder(w,h);
    }
    float getXSize() { return xSize; }
    float getYSize() { return ySize; }
    //std::shared_ptr<sf::Shape> getSfShape() { return sfShape; }
    sf::Shape& getSfShape() { return *sfShape; }
    void setXSpeed(float Xspeed) { speed.x = Xspeed; }
    void setYSpeed(float Yspeed) { speed.y = Yspeed; }
};


void check_border(sf::Shape &shape, const int wWidth, const int wHeigth, shapesSpeed &speed)
{

    if(shape.getPosition().x <= 0 || shape.getPosition().x >= wWidth)
    {
        speed.x *= -1;
    }
    if(shape.getPosition().y <= 0 || shape.getPosition().y >= wHeigth)
    {
        speed.y *= -1;
    }
}


int main(int agrc, char **argv)
{

    /* Create a new game window */
    const int wWidth = 640;
    const int wHeight = 480;
    sf::RenderWindow window(sf::VideoMode(wWidth,wHeight), "SFML_works");
    window.setFramerateLimit(60);

    std::vector<std::shared_ptr<Shape>> shapes;

    /* Load font*/
    sf::Font myFont;
    if(!myFont.loadFromFile("fonts/tech.ttf"))
    {
        std::cout << "Error loading font\n";
    }
    sf::Text text("Sample text", myFont, 60);
    text.setPosition(180, 150);

    std::shared_ptr<Shape> shape = std::make_shared<Shape>(40.0f, 40.0f, shape_type::Circle, Color::Red);
    shapes.push_back(shape);
    std::shared_ptr<Shape> shape_2 = std::make_shared<Shape>(20.0f, 20.0f, shape_type::Polygon, Color::Green);
    shapes.push_back(shape_2);

    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        for(auto& shape : shapes)
        {
                shape->updatePos(wWidth, wHeight);
                window.draw(shape->getSfShape()); // Drawing our shape.

                // ToDo: Check for collison
                for(auto& tmp_shape : shapes) {
                        if(shape == tmp_shape)
                          continue;
                }
        }

        window.draw(text); // Drawing our shape.
        window.display();
    }
    return 0;
}
