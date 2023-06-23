#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H
#include <iostream>
#include <cstddef>
#include "Reservation.h"

namespace sdds
{
	class Restaurant
	{
		Reservation* m_reservations;
		size_t m_cnt;

	public:
		Restaurant(const Reservation* reservations[], size_t cnt);

		//Copy constructor
		Restaurant(Restaurant& res);

		//copy assignment operator
		Restaurant& operator=(const Restaurant& res);

		//move constructor
		Restaurant(Restaurant&& res);

		//move assignment operator
		Restaurant& operator=(Restaurant&& res);

		size_t size() const;
		~Restaurant();
		friend std::ostream& operator<<(std::ostream& os, const Restaurant&);

	};


}

#endif