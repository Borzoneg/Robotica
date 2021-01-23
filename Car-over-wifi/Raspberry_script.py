import socket

ipAddress = "192.168.1.40"

serverAddressPort = (ipAddress, 1025)

# Create a UDP socket at client side
UDPClientSocket = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)

command = input()
while command != "\\":
	BToSend = str.encode(command)
	UDPClientSocket.sendto(BToSend, serverAddressPort)
	command = input()
