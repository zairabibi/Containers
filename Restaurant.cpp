#include <cstddef>
#include "Restaurant.h"

namespace sdds {

	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt)
	{
		if (cnt > 0) {
			m_cnt = cnt;
			m_reservations = new Reservation[cnt];

			for (size_t i = 0; i < m_cnt; i++)
			{
				m_reservations[i] = *(reservations[i]);
			}
		}
		else
		{
			m_cnt = 0;
			m_reservations = nullptr;
		}
	}

	Restaurant::Restaurant(Restaurant& res)
	{
		m_cnt = res.m_cnt;
		m_reservations = new Reservation[m_cnt];

		for (size_t i = 0; i < m_cnt; i++)
			m_reservations[i] = res.m_reservations[i];
	}

	Restaurant& Restaurant::operator=(const Restaurant& res)
	{
		if (this != &res)
		{
			m_cnt = res.m_cnt;
			delete[] m_reservations;

			m_reservations = new Reservation[m_cnt];

			for (size_t i = 0; i < m_cnt; i++)
				m_reservations[i] = res.m_reservations[i];
		}

		return *this;
	}

	Restaurant::Restaurant(Restaurant&& res)
	{
		m_cnt = res.m_cnt;
		m_reservations = res.m_reservations;

		//emptying source object
		res.m_cnt = 0;
		res.m_reservations = nullptr;
	}

	//move assignment operator
	Restaurant& Restaurant::operator=(Restaurant&& res)
	{
		if (this != &res)
		{
			m_cnt = res.m_cnt;

			delete[] m_reservations;
			m_reservations = res.m_reservations;

			//emptying source object
			res.m_cnt = 0;
			res.m_reservations = nullptr;
		}
		return *this;
	}

	size_t Restaurant::size() const
	{
		return m_cnt;
	}

	Restaurant::~Restaurant()
	{
		delete[] m_reservations;
	}

	std::ostream& operator<<(std::ostream& os, const Restaurant& rt)
	{
		static int CALL_CNT = 0;
		os << "--------------------------\nFancy Restaurant(" << ++CALL_CNT << ")\n--------------------------" << std::endl;

		if (!rt.m_reservations)
			os << "This restaurant is empty!\n";

		else
		{
			for (size_t i = 0; i < rt.size(); i++)
			{
				os << rt.m_reservations[i];
			}
		}

		os << "--------------------------\n";
		return os;
	}
}