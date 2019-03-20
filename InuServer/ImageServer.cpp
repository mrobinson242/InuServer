// Headers
#include "ImageServer.h"

/**
 * Constructor
 */
ImageServer::ImageServer()
{
	// N/A
}

/**
 * Destructor
 */
ImageServer::~ImageServer()
{
	// N/A
}

/**
 * startServer - Starts the Server Code
 */
void ImageServer::startServer()
{
	// Debug Statement
	std::cout << "Awaiting Client Connections" << std::endl;

	// Windows Socket Startup
	WSADATA wsaData;
	WORD DllVersion = MAKEWORD(2, 1);

	// If WSAStartup returns anything other than 0
	// then that means an error has occured upon WinSock Startup
	if (WSAStartup(DllVersion, &wsaData) != 0)
	{
		// Log Error
		MessageBoxA(NULL, "Winsock startup failed", "Error", MB_OK | MB_ICONERROR);
		exit(1);
	}

	// Initialize Socket Information
	SOCKADDR_IN addr;							   // Address that we will bind our listening socket to
	int addrlen = sizeof(addr);					   // Length of the address (required for accept call)

	// Set the IP Address
	unsigned ipAddress;
	inet_pton(AF_INET, "127.0.0.1", &ipAddress);
	addr.sin_addr.s_addr = ipAddress;

	// Set the Port and Socket Type
	addr.sin_port = htons(1111); // Port
	addr.sin_family = AF_INET;	 // IPv4 Socket

	// Create socket to listen for new connections
	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);

	// Bind the address to the socket
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));

	// Places th Socket in a state in which it is listening for an incoming connection
	listen(sListen, SOMAXCONN);

	SOCKET newConnection; // Socket to hold the client's connection
	newConnection = accept(sListen, (SOCKADDR*)&addr, &addrlen); // Accept a new connection

	// Check if Connected with Client
	if (newConnection == 0)
	{
		// Log Error
		std::cout << "Failed to accept the client's connection" << std::endl;
	}
	else
	{
		// Debug Statement
		std::cout << "Client Connected!" << std::endl;

		// Create Buffer with Message of the Day
		char MOTD[256] = "now connected to ARCS Server";

		// Send Message Buffer 
		send(newConnection, MOTD, sizeof(MOTD), NULL);
	}
}
