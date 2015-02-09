#ifndef Z_LOGGER_H
#define Z_LOGGER_H

#include <iostream>

#define Z_INFO( msg ) std::cout <<  "INFO [" << __FILE__ << ":" << __LINE__ << "] " << msg << std::endl 
#define Z_WARN( msg ) std::cout <<  "WARN [" << __FILE__ << ":" << __LINE__ << "] " << msg << std::endl 
#define Z_ERROR( msg ) std::cout << "ERROR [" << __FILE__ << ":" << __LINE__ << "] " << msg << std::endl 

#endif
