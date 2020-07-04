import zerorpc


NAMESERVER = "tcp://127.0.0.1:12345"

def register(name,address):
	c = zerorpc.Client()
	c.connect(NAMESERVER)
	status, message = c.register(name,address)
	if not status:
		status, message = c.update(name,address)
	c.close()
	return status 

class Hitung(object):
	def luas(self, panjang, lebar):
		return panjang * lebar

	def keliling(self, panjang, lebar):
		return (panjang * 2) + (lebar * 2)

name = "RPC-Hitung"
address = "tcp://0.0.0.0:6000"
if register(name,address):
	s = zerorpc.Server(Hitung())
	s.bind(address)
	s.run()
