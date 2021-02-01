import evdev

print("Available devices: ")
for path in evdev.list_devices():
    print path

# icontr = input("What device are you gonna use?")

gamepad = evdev.InputDevice(evdev.list_devices()[0])

print(gamepad)

tojump = False

for event in gamepad.read_loop():
    if not False:
        if event.type == 3: # joystick event
            print(event.type, event.code, event.value)
            if event.code == 1: # vertical
                if event.value < -200: # up 
                    print('w')
                    #udp_send_char('w')
                elif event.value > 200: #down
                    print('s')
                    #udp_send_char('s')
                else:
                    print('q')
                    #udp_send_char('q')
            if event.code == 0: # vertical
                if event.value < -200: # left 
                    print('a')
                    #udp_send_char('a')
                elif event.value > 200: # right
                    print('d')
                    #udp_send_char('d')
                else:
                    print('q')
                    #udp_send_char('q')
    tojump = not tojump
