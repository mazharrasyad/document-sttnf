import zerorpc
import socket

def lookup(name):
	s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP)
	# Enable broadcasting mode
	s.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
	s.settimeout(0.2)
	s.sendto(name.encode(), ('255.255.255.255', 54321))
	address = s.recv(128)
	return address.decode()

address = lookup('RPC-Hitung')

c = zerorpc.Client()
c.connect(address)
panjang = 20
lebar = 15

print( c.luas(panjang, lebar) )
print( c.keliling(panjang, lebar) )
