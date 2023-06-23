#include "ConfirmationSender.h"

namespace sdds
{
	//addition operator
	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
	{
		bool check = false;

		//if the array is empty, initialize it
		if (m_confirmations == nullptr)
			m_confirmations = new const Reservation*[m_maxReservations];

		//find out if the address already exists or not
		else
		{
			for (int x = 0; x < m_numReservations; x++)
			{
				if (&res == m_confirmations[x])
				{
					check = true;
					break;
				}
			}

		}

		//if the address does not exist in the array
		if (check == false)
		{
			if (m_numReservations >= m_maxReservations)
			{
				//resizing the array by making a temporary Reservation array 
				const Reservation** t_Res = new const Reservation*[m_numReservations];

				for (int i = 0; i < m_numReservations; i++)
					t_Res[i] = m_confirmations[i];

				delete[] m_confirmations;
				m_maxReservations = m_numReservations + 1; //set the new capacity
				m_confirmations = new const Reservation*[m_maxReservations];

				for (int i = 0; i < m_numReservations; i++)
					m_confirmations[i] = t_Res[i];

				//free the temporary array
				delete[] t_Res;
			}

			//add the new address
			m_confirmations[m_numReservations] = &res;
			m_numReservations++;
		}

		return *this;
	}

	//subtraction operator
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
	{
		int idx = 0;
		bool removed = false;

		for (int x = 0; x < m_numReservations; x++)
		{
			if (&res == m_confirmations[x])
			{
				m_confirmations[x] = nullptr;
				idx = x;
				removed = true;
			}

		}

		if (removed)
		{
			//resizing the array
			for (int i = idx; i < m_numReservations; i++)
			{
				//shift all elements one index backwards
				m_confirmations[i] = m_confirmations[i + 1];
			}
			//set the last pointer to null
			m_confirmations[m_numReservations - 1] = nullptr;
			m_numReservations--; //decrease the size by 1
		}


		return *this;
	}

	//insertion operator
	std::ostream& operator<<(std::ostream& ostr, const ConfirmationSender& con)
	{
		ostr << "--------------------------" << std::endl;
		ostr << "Confirmations to Send" << std::endl;
		ostr << "--------------------------" << std::endl;

		if (con.m_confirmations)
		{
			for (int x = 0; x < con.m_numReservations; x++)
				ostr << *(con.m_confirmations[x]);
		}

		else
			ostr << "There are no confirmations to send!\n";


		ostr << "--------------------------" << std::endl;

		return ostr;
	}

	//copy constructor
	ConfirmationSender::ConfirmationSender(ConfirmationSender &res)
	{
		m_confirmations = new const Reservation*[res.m_maxReservations];
		m_maxReservations = res.m_maxReservations;
		m_numReservations = res.m_numReservations;

		int x = 0;
		while (x < m_numReservations)
		{
			m_confirmations[x] = res.m_confirmations[x];
			x++;
		}
	}

	//copy assignment operatot
	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& res)
	{
		if (res.m_confirmations != nullptr)
		{
			if (this != &res)
			{
				//copy the resources
				m_maxReservations = res.m_maxReservations;
				m_numReservations = res.m_numReservations;

				//delete the currently allocated memory
				delete[] this->m_confirmations;

				//allocate new memory
				m_confirmations = new const Reservation*[m_numReservations];

				//copy the pointers
				int x = 0;
				while (x < m_numReservations)
				{
					m_confirmations[x] = res.m_confirmations[x];
					x++;
				}
			}
		}

		return *this;
	}

	//move constructor
	ConfirmationSender::ConfirmationSender(ConfirmationSender &&res)
	{
		m_numReservations = res.m_numReservations;
		m_confirmations = new const Reservation*[m_numReservations];
		m_maxReservations = res.m_maxReservations;

		//move resources from res to the current object
		m_confirmations = std::move(res.m_confirmations);

		//set source object to empty
		res.m_confirmations = nullptr;
		res.m_maxReservations = 0;
		res.m_numReservations = 0;
	}

	//move assignment operator
	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& res)
	{
		if (res.m_confirmations)
		{
			if (this != &res)
			{
				m_maxReservations = res.m_maxReservations;
				m_numReservations = res.m_numReservations;
				delete[] this->m_confirmations;

				//allocate new memory
				m_confirmations = new const Reservation*[m_numReservations];

				//move resources from res to the current object
				m_confirmations = std::move(res.m_confirmations);

				//emptying res
				res.m_confirmations = nullptr;
				res.m_maxReservations = 0;
				res.m_numReservations = 0;
			}
		}

		return *this;
	}




}