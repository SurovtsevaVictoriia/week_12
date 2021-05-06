#pragma once

#include <complex>
#include <iostream>
#include <thread>
#include <vector>

#include <SFML/Graphics.hpp>

class Calculator
{
public:

    using field_t = std::vector < std::vector < std::size_t > > ;

public:

    explicit Calculator(
		const std::size_t width, const std::size_t height, const std::size_t max_iterations) :
		c_width(width), c_height(height), c_max_iterations(max_iterations)
	{
		initialize();
	}

	~Calculator() noexcept = default;

private:

	void initialize();

public:

    const auto & field() const noexcept 
	{ 
		return c_field; 
	}

	const auto width () const noexcept 
	{ 
		return c_width;  
	}

	const auto height() const noexcept 
	{ 
		return c_height; 
	}

	const auto max_iterations() const noexcept 
	{ 
		return c_max_iterations; 
	}

	


public:

	void calculate(const sf::Vector2f center, const float width, const float height, const float c_real, const float c_imaginary);

private:

	std::size_t c_width;
	std::size_t c_height;

    std::size_t c_max_iterations;

	field_t c_field;
};