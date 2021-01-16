import socket

ipAddress = "192.168.1.x"

serverAddressPort = (ipAddress, 1025)

# Create a UDP socket at client side
UDPClientSocket = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)

while True:
	command = input()
	BToSend = str.encode(command)
	UDPClientSocket.sendto(BToSend, serverAddressPort)
