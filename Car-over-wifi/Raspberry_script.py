import evdev
import socket

ipAddress = "192.168.1.40"
port = 1025
serverAddressPort = (ipAddress, port) # define where the server is
UDPClientSocket = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM) # Create a UDP socket at client side

threshold = 100

def udp_send_char(command):	
	BToSend = str.encode(command)
	UDPClientSocket.sendto(BToSend, serverAddressPort)
        # print("Sending ", command)


def device_setup():
	print("Available devices: ")
	for path in evdev.list_devices():
	    print(path)

	icontr = input("What device are you gonna use?")
	gamepad = evdev.InputDevice(evdev.list_devices()[icontr])
	print(gamepad)
	return gamepad


def device_setup(nr_device):
	gamepad = evdev.InputDevice(evdev.list_devices()[nr_device])
	print(gamepad)
        return gamepad

def event_manager(event):
	if event.type == 3: # joystick event
		if event.value > threshold or event.value < -threshold: # if the value is enough to activate
			print(event.type, event.code, event.value) 
			if event.code == 1: # vertical
				if event.value < -threshold: # up 
					udp_send_char('e')
					udp_send_char('w')
				elif event.value > threshold: #down
					udp_send_char('e')
					udp_send_char('s')
				
			if event.code == 0: # horizontal
				if event.value < -threshold: # left 
					udp_send_char('e')
					udp_send_char('a')
				elif event.value > threshold: # right
					udp_send_char('e')
					udp_send_char('d')
								
		else: # if the value is to low
                        print("Q")
			udp_send_char('q')

cmd = raw_input()
while cmd != "r":
    udp_send_char(cmd)
    cmd = raw_input()

# Main script
controller = device_setup(0)
for event in controller.read_loop():
	event_manager(event)
    
