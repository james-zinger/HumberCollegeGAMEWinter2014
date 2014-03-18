///////////////////////////////////////////////////////////
//  Server.cpp
//  Implementation of the Class Server
//  Created on:      14-Mar-2014 5:29:07 PM
//  Original author: James
///////////////////////////////////////////////////////////

#include "Server.h"

#include <iostream>
#include <boost/thread.hpp>

using std::cout;
using std::endl;

Server::Server( const int port )
{
	ListenPort( port );

	m_wsaData = new WSADATA();
	int iResult = WSAStartup( 0x0202, m_wsaData );
	if ( iResult != 0 )
	{
		cout << "WSAStartup Failed, Error Code: " << iResult << endl;
		system( "pause" );
		exit( iResult );
	}

	Debugging( false );
	ListenPort( port );
	ListenSocket( INVALID_SOCKET );
	ThreadGroup( new boost::thread_group() );

}

Server::~Server()
{
	closesocket( ListenSocket() );
	WSACleanup();
}

