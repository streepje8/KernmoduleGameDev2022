#include "ParachutePanic.h"
#include "Debug.h"
#include "Macros.h"
#include "Vector3.h"
#include "Quaternion.h"
#include "Matrix4x4.h"
#include "Math.h"
#include <SFML/Graphics.hpp>

void ParachutePanic::Awake() {
	FUNCBEGIN(Awake);
	Vector3 meh(1,0,0);
    Matrix4x4 mat = Matrix4x4::Rotate(Vector3(0, 90, 0));
    mat = mat * Matrix4x4::Inverse(mat);
	Debug::Log(Matrix4x4::Rotate(Vector3(0, 90, 0)).to_string());
	Debug::Log((mat).to_string());
    /*
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
	*/
}