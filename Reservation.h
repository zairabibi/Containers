#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H
#include <iostream>
#include <cstddef>
#include <string>

namespace sdds
{
	class Reservation {
		char m_id[15];
		std::string m_name;
		std::string m_email;
		size_t m_people;
		unsigned m_day;
		unsigned m_hour;
		std::string trimmer(std::string&) const;

	public:
		Reservation();
		void update(int day, int time);
		Reservation(const std::string& res);
		friend std::ostream& operator<<(std::ostream& os, const Reservation& rs);
	};


}

#endif