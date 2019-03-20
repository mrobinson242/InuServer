// Headers
#include "ImageServer.h"

/**
 * main
 */
int main()
{
	// Initialize MJPG Image Server
	ImageServer *imageServer = new ImageServer();

	// Start the Image Server
	imageServer->startServer();

	// Pause the System Thread
	system("pause");

	return 0;
}