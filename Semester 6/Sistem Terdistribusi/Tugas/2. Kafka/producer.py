from kafka import KafkaProducer
bootstrap_servers = ['localhost:9092']
topicName = 'myTopic'
producer = KafkaProducer(bootstrap_servers = bootstrap_servers)
producer = KafkaProducer()

msg = b'Hello World!!!!!!!!'
ack = producer.send(topicName, msg)
metadata = ack.get()
print("Topic : ", metadata.topic)
print("Partition : ", metadata.partition)
print("Message : ", msg)

producer = KafkaProducer(bootstrap_servers = bootstrap_servers, retries = 5,value_serializer=lambda m: json.dumps(m).encode('ascii'))
