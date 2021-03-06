
#include "include/MQTTAsync.h"
#include "include/MQTTClientPersistence.h"
#include "include/pubsub_opts.h"
#include "include/Publisher.h"
#include "include/Subscriber.h"
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>


#if defined(_WIN32)
#include <windows.h>
#define sleep Sleep
#else
#include <sys/time.h>
#include <unistd.h>
#endif

#if defined(_WRS_KERNEL)
#include <OsWrapper.h>
#endif

int main()
{
	MQTTAsync client;
	MQTTAsync_createOptions create_opts = MQTTAsync_createOptions_initializer;
	//MQTTAsync_willOptions will_opts = MQTTAsync_willOptions_initializer;
	//MQTTAsync_SSLOptions ssl_opts = MQTTAsync_SSLOptions_initializer;
	char* url = NULL;
	int x = subscribe(&client, create_opts, url);
	ConnectPublisher(&client);
	disconnect(&client);
}