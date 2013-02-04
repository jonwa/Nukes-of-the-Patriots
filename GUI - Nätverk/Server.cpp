#include "Server.h"
#include <iostream>
#include <stdarg.h>
#include "Event.h"

Server::Server(unsigned short port):mUdpSocket(),mPort(port)
{
	mUdpSocket.bind(mPort);
	mUdpSocket.setBlocking(false);
}

void Server::sendData(sf::Packet packet, sf::IpAddress ipAddress, unsigned short port)
{
	mUdpSocket.send(packet, ipAddress, port);
}

void Server::checkIfDataReceived()
{
	sf::IpAddress sender;
	unsigned short port;
	sf::Packet packet;
	sf::Socket::Status status = mUdpSocket.receive(packet, sender, port);
	if(status == sf::Socket::Done)
	{
		char eventName[1024];
		char data[1024];
		packet>>eventName;
		Event::triggerEvent(eventName, packet);
	}
}




void Server::triggerClientEvent(std::string eventName, sf::Packet packet, sf::IpAddress receivingAddress, unsigned short receivingPort)
{
	sf::Packet _packet;
	_packet<<eventName.c_str();
	_packet.append(packet.getData(), packet.getDataSize());
	sendData(_packet, receivingAddress, receivingPort);
}