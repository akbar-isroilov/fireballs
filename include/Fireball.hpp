#ifndef FIREBALL_HPP
#define FIREBALL_HPP

#include <Entity.hpp>
#include <SFML/Graphics/CircleShape.hpp>

class Fireball : public Entity {
public:
	enum Type {
		Red,
		Green
	};

	Fireball(Type type);
	virtual unsigned int	getCategory() const;

private:
	virtual void			drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

	Type mType;
	sf::CircleShape mShape;
};

#endif // FIREBALL_HPP
