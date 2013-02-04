#ifndef _SERVER_H
#define _SERVER_H

#include <SFML\Network.hpp>
#include <string>
#include <functional>

class Server
{
public:
						Server(unsigned short port);
	unsigned short		getPort()const{ return mPort; }

	void				setPort(unsigned short port){ mPort = port; }
	void				sendData(sf::Packet packet, sf::IpAddress ipAddress, unsigned short port);
	void				checkIfDataReceived();
	void				triggerClientEvent(std::string eventName, sf::Packet packet, sf::IpAddress receivingAddress, unsigned short receivingPort);
						~Server(){};
private:
	sf::UdpSocket mUdpSocket;
	unsigned short mPort;
};

#endif