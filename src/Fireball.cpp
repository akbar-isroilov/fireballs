#include <Fireball.hpp>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

Fireball::Fireball(Type type)
	: mType(type)
{
	mShape.setRadius(15.f);
	mShape.setOutlineThickness(5.f);
	mShape.setFillColor(sf::Color::Transparent);

	switch (type)
	{
	case Fireball::Green:
		mShape.setOutlineColor(sf::Color::Blue);
	default:
		mShape.setOutlineColor(sf::Color::Blue);
		break;
	}
}

unsigned int Fireball::getCategory() const
{
	switch (mType)
	{
	case Green:
		return Category::PlayerAircraft;

	default:
		return Category::EnemyAircraft;
	}
}

void Fireball::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mShape, states);
}
