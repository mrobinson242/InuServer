// Headers
#include <winSock2.h>
#include <ws2tcpip.h>
#include <iostream>

// Need to link with ws2_32.lib
#pragma comment(lib, "ws2_32.lib")

// Namespaces
using namespace std;

class ImageServer
{
public:
	
	/**
	 * Constructor
	 */
	ImageServer();

	/**
	 * Destructor
	 */
	~ImageServer();

	/**
	 * startServer - Starts the Server Code
	 */
	void startServer();
};

