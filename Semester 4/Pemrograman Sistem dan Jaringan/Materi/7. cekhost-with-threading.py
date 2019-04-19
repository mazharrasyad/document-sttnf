import threading
import os
import time
class PingHost (threading.Thread):
	def __init__(self,name,ip):
		threading.Thread.__init__(self)
		self.name = name
		self.ip = ip
		self.hasil = ""
	def run(self):
		try:
			out = None
			pattern = "3 received"
			cmd = "ping -qc3 %s"%(self.ip)
			exe = os.popen(cmd)
			out = exe.read()
			status = "Down"
			if out.find(pattern) > -1:
				status = "Up"
			t = time.strftime("%Y-%m-%d %H:%M:%S")
			self.hasil = "%s;%s;%s\n" %(str(t),self.ip,status)
		except:
			self.hasil = None
	
fname = "ip.txt"
fout = "status.csv"
fd = open(fname)
fw = open(fout,"a")
ips = []
pattern = "3 received"
for ip in fd.readlines():
	#strip utk menghilangkan karakter \n
	ipx = ip.strip() 
	ips.append(ipx)
fd.close()
y = 1
ts = []
tstart = time.time()
for ip in ips:
	t = PingHost("thread-ping-%d"%y,ip)
	t.start()
	ts.append(t)	
	y += 1
	if t.isAlive():
		print('Thread %s is Running'%(t.getName()) )

for th in ts:
	th.join()
	if th.hasil is None:
		pass
	else:
		fw.write(th.hasil)

fw.close()
tend = time.time()
print("Durasi:%s sec"%(str(tend-tstart)) ) 
