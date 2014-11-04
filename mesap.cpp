
// mesap (messenger application)

// nemo (network mobilizer)
// Copyright (C) 2012-2014 Damien Magoni

/*
    This file is part of nemo.

    nemo is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as 
    published by the Free Software Foundation, either version 3 of 
    the License, or (at your option) any later version.

    nemo is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with nemo.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "mesap.h"

namespace mesap
{
	messenger::messenger()
	{
		output_mode = console;
		pause_mode = true;
	}

	messenger::messenger(std::string filename, messages_output_type startup_output_mode, bool startup_pause_mode)
	{
		output_mode = startup_output_mode;
		pause_mode = startup_pause_mode;
		log_file.open(filename.c_str());
		if ( !log_file.is_open() )
		{
			std::cout << "could not create log file\n";
		}
	}

	messenger::~messenger()
	{
		log_file.close();
	}

	messenger & messenger::operator<<(const std::string & s)
	{
		if ( output_mode & console )
		{
			std::cout << s;
			std::cout.flush();
		}
		if ( output_mode & logging )
		{
			log_file << s;
			log_file.flush();
		}
		if ( pause_mode )
			util::pause();
		return *this;
	}

	messenger & messenger::operator<<(const char * s)
	{
		if ( output_mode & console )
		{
			std::cout << s;
			std::cout.flush();
		}
		if ( output_mode & logging )
		{
			log_file << s;
			log_file.flush();
		}
		if ( pause_mode )
			util::pause();
		return *this;
	}

	messenger & messenger::operator<<(const int & i)
	{
		if ( output_mode & console )
		{
			std::cout << i;
			std::cout.flush();
		}
		if ( output_mode & logging )
		{
			log_file << i;
			log_file.flush();
		}
		if ( pause_mode )
			util::pause();
		return *this;
	}

	messenger & messenger::operator<<(const long & i)
	{
		if ( output_mode & console )
		{
			std::cout << i;
			std::cout.flush();
		}
		if ( output_mode & logging )
		{
			log_file << i;
			log_file.flush();
		}
		if ( pause_mode )
			util::pause();
		return *this;
	}

	messenger & messenger::operator<<(const unsigned char & i)
	{
		if ( output_mode & console )
		{
			std::cout << i;
			std::cout.flush();
		}
		if ( output_mode & logging )
		{
			log_file << i;
			log_file.flush();
		}
		if ( pause_mode )
			util::pause();
		return *this;
	}

	messenger & messenger::operator<<(const unsigned int & i)
	{
		if ( output_mode & console )
		{
			std::cout << i;
			std::cout.flush();
		}
		if ( output_mode & logging )
		{
			log_file << i;
			log_file.flush();
		}
		if ( pause_mode )
			util::pause();
		return *this;
	}

	messenger & messenger::operator<<(const unsigned long & i)
	{
		if ( output_mode & console )
		{
			std::cout << i;
			std::cout.flush();
		}
		if ( output_mode & logging )
		{
			log_file << i;
			log_file.flush();
		}
		if ( pause_mode )
			util::pause();
		return *this;
	}

	messenger & messenger::operator<<(const double & d)
	{
		if ( output_mode & console )
		{
			std::cout << d;
			std::cout.flush();
		}
		if ( output_mode & logging )
		{
			log_file << d;
			log_file.flush();
		}
		if ( pause_mode )
			util::pause();
		return *this;
	}

	void messenger::flush()
	{
		log_file.flush();
		std::cout.flush();
	}

	void messenger::precision(int p)
	{
		log_file.precision(p);
		std::cout.precision(p);
	}
}
