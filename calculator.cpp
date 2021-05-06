#include "calculator.hpp"

// =============================================================================

void Calculator::initialize()
{
	c_field.resize(c_height);

	for (auto & row : c_field)
		row.resize(c_width);
}

// =============================================================================

void Calculator::calculate(
	const sf::Vector2f center, const float width, const float height, const float c_real, const float c_imaginary)
{
	auto threads_number = std::thread::hardware_concurrency();//0

	auto dx = width  / c_width;
	//auto dy = height / m_height;
	auto dy = width / c_width;




	std::vector < std::thread > threads(threads_number);

	auto size = c_height / threads_number;
    auto tail = c_height - threads_number * size;

    auto function = [=](std::size_t id)
    {
        auto first_y = size * id;
        auto last_y  = first_y + size;

        last_y = last_y > c_height ? c_height : last_y;

		for (auto y = first_y; y < last_y; ++y)
		{
			for (auto x = 0U; x < c_width; ++x) 
			{
				/*std::complex < float > z(0.0f, 0.0f);
				std::complex < float > c(
					center.x - width  / 2.0f + dx * x,
					center.y - height / 2.0f + dy * y					
				);*/

				std::complex < float > z(center.x - width / 2.0f + dx * x,
					center.y - height / 2.0f + dy * y);
				std::complex < float > c(c_real, c_imaginary);

				//std::complex < float > c(0.0f, 1.0f	);

				auto iteration = 0U;

				for (; iteration < c_max_iterations && std::norm(z) < 4.0f; ++iteration)
				{
					z = z * z + c;
				}

				c_field[y][x] = iteration; // ?
			}
		}
    };

	for (auto i = 0U; i < threads_number; ++i)
	{
		threads[i] = std::thread(function, i);
	}

	if (tail > 0U)
	{
		function(threads_number);
	}

	for (auto i = 0U; i < threads_number; ++i)
	{
		threads[i].join();
	}
}

// =============================================================================