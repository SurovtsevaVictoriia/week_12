#pragma once

#include <SFML/Graphics.hpp>

class View
{
public:

	explicit View(const sf::Vector2f center, const float width, const float height) noexcept :
		m_center(center), m_width(width), m_height(height)
	{}

	~View() noexcept = default;

public:

	void move(const sf::Vector2f delta) noexcept
	{
		m_center += delta;
	}

	void scale(const float factor) noexcept
	{
		m_width  *= factor; 
		m_height *= factor;
	}
	//---
	void change_real(const float factor) noexcept {
		m_c_real += factor;
	}
	void change_imaginary(const float factor) noexcept {
		m_c_imaginary += factor;
	}

    //---
	const auto center() const noexcept 
	{
		return m_center; 
	}

	const auto width () const noexcept 
	{ 
		return m_width;  
	}

	const auto height() const noexcept 
	{ 
		return m_height; 
	}

	const auto c_real() const noexcept
	{
		return m_c_real;
	}
	
	const auto c_imaginary() const noexcept
	{
		return m_c_imaginary;
	}

	


private:

	sf::Vector2f m_center;

	float m_width;
	float m_height;

	float m_c_real = 0.4f;
	float m_c_imaginary = 0.2f;


};