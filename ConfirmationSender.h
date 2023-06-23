#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H
#include <iostream>
#include "Reservation.h"

namespace sdds
{
	class ConfirmationSender
	{
		const Reservation** m_confirmations{ nullptr };
		int m_numReservations{ 0 };
		int m_maxReservations{ 5 };

	public:

		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		friend std::ostream& operator<<(std::ostream&, const ConfirmationSender&);

		ConfirmationSender() {};
		ConfirmationSender(ConfirmationSender &);
		ConfirmationSender& operator=(const ConfirmationSender&);
		ConfirmationSender(ConfirmationSender &&);
		ConfirmationSender& operator=(ConfirmationSender&&);

		//destructor
		~ConfirmationSender() { delete[] m_confirmations; };

	};

}

#endif
