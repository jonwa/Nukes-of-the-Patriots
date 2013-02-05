#include "Client.h"
#include <iostream>
#include "Event.h"

Client::Client(unsigned short port, unsigned short serverPort, sf::IpAddress serverAddress):mUdpSocket(),mPort(port),mServerPort(serverPort),mServerAddress(serverAddress)
{
	mUdpSocket.bind(mPort);
	mUdpSocket.setBlocking(false);
}

void Client::sendData(sf::Packet packet)
{
	mStatus = mUdpSocket.send(packet, mServerAddress, mServerPort);
}

void Client::checkIfDataReceived()
{
	sf::IpAddress sender;
	unsigned short port;
	sf::Packet packet;
	sf::Socket::Status status = mUdpSocket.receive(packet, sender, port);
	if(status == sf::Socket::Done)
	{
		char eventName[1024];
		packet>>eventName;
		Event::triggerEvent(eventName, packet);
	}
}

void Client::checkIfDataSent()
{
	if(mStatus == sf::Socket::Done)
	{
		//std::cout<<"done sending data!"<<std::endl;
	}
}

void Client::triggerServerEvent(std::string eventName, sf::Packet packet)
{
	sf::Packet _packet;
	_packet<<eventName.c_str();
	_packet.append(packet.getData(), packet.getDataSize());
	sendData(_packet);
}