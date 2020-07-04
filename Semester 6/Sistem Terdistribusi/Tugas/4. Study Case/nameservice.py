import zerorpc

# kode program ini akan berperan menjadi sebuah sistem penamaan entitas (object RPC)
# yang akan memetakan nama entitas (object RPC) ke alamat nya masing masing.
# terdapat 4 prosedur yaitu register, update, remove dan lookup
 

ADDRESS = "tcp://0.0.0.0:12345"
data = {}

class NameService(object):

	def register(self, name, address):
		if name not in data.keys():
			data[name] = address
			print("Registration Success for %s -> %s" %(name,address))
			return True, "Registration Success for %s -> %s" %(name,address)
		else:
			return False, "Registration failed name already exists"

	def update(self, name, address):
		if name in data.keys():
			data[name] = address
			print("Update Successfully for %s -> %s" %(name,address))
			return True, "Update Successfully for %s -> %s" %(name,address)
		else:
			return False, "Update failed no name like that"
	
    
	def remove(self, name):
		if name in data.keys():
			data.pop(name)
			print("Removing Successfully for %s" %name)
			return True, "Removing Successfully for %s" %name
		else:
			return False, "Removing failed no name like that"

	def lookup(self,name):
		if name in data.keys():
			return data[name]
		else:
			return None

s = zerorpc.Server(NameService())
s.bind(ADDRESS)
s.run()
