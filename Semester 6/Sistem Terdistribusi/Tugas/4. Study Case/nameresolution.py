import zerorpc
import socket
import time

# Kode program ini akan berperan sebagai sebuah service/server
# yang akan menerima permintaan name resolution atau penerjemahan
# nama entitas menjadi alamat entitas (object RPC)

NAMESERVER = "tcp://127.0.0.1:12345"
def lookup(name):
	c = zerorpc.Client()
	c.connect(NAMESERVER)
	address = c.lookup(name)
	c.close()
	return address

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP) 
# Enable broadcasting mode
s.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)

s.bind(("", 54321))
while True:
	data, addr = s.recvfrom(128)
	if data is not None:
		name = data.decode()
		name = name.strip()
		address = lookup(name)
		print(name, address)
		s.sendto(address.encode(),addr)
