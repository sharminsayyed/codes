import requests

Contact_URL = "http://127.0.0.1:8000/enquiry_api/"
data1=requests.get(url=Contact_URL)
result1 = data1.json()
print("contact data :")
for x in result1:
    print(x)


Booking_URL ="http://127.0.0.1:8000/booking_api/"
data2=requests.get(url=Booking_URL)
result2=data2.json()
print(" table booking data :")
for x in result2:
    print(x)

Event_URL ="http://127.0.0.1:8000/event_api/"
data3=requests.get(url=Event_URL)
result3=data3.json()
print("event data :")
for x in result3:
    print(x)
