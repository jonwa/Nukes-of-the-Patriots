#ifndef _CLIENT_H
#define _CLIENT_H

#include <SFML\Network.hpp>
#include <string>
#include <functional>
#include <stdarg.h>

class Client
{
public:
						Client(unsigned short port, unsigned short serverPort, sf::IpAddress serverAddress);
	unsigned short		getPort()const{ return mPort; }
	sf::IpAddress		getReceivingAddress()const{ return mServerAddress; }

	void				setPort(unsigned short port){ mPort = port; }
	void				setReceivingAddress(std::string serverAddress){ mServerAddress = sf::IpAddress::IpAddress(serverAddress); }
	void				sendData(sf::Packet packet);
	void				checkIfDataReceived();
	void				checkIfDataSent();

	void				triggerServerEvent(std::string eventName, sf::Packet packet);
						~Client(){};
private:
	sf::UdpSocket mUdpSocket;
	unsigned short mPort, mServerPort;
	sf::IpAddress mServerAddress;
	sf::Socket::Status mStatus;
};

#endif