import sys
import zmq

port = "5555"
context = zmq.Context()
socket = context.socket(zmq.SUB)

print "Collecting updates from weather server..."

socket.connect ("tcp://localhost:%s" % port)
topicfilter = "9999"

if len(sys.argv) == 2:
	topicfilter = sys.argv[1]

socket.setsockopt(zmq.SUBSCRIBE, topicfilter)

total_value = 0
for update_nbr in range (5):
    string = socket.recv()
    topic, messagedata = string.split()
    total_value += int(messagedata)

    print(topic, messagedata)

print "Average messagedata value for topic '%s' was %d" % (topicfilter, total_value / update_nbr)