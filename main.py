import cv2
from cvzone.HandTrackingModule import HandDetector
import socket
import time

ip1 = "192.168.137.19"
f1 = [0,0,0,0,0]
cap = cv2.VideoCapture(0)
ip_port = 4210
mess1 = "1"
mess2 = "11"
mess3 = "111"
mess4 = "1111"
mess5 = "11111"
print("message: %s" % mess1)
print("message: %s" % mess2)
print("message: %s" % mess3)
print("message: %s" % mess4)

detector = HandDetector(detectionCon=0.8, maxHands=2)
while True:
    success, img = cap.read()
    hands, img = detector.findHands(img)
    if hands:
        hand1 = hands[0]  # gives us first hand
        lmList1 = hand1["lmList"]  # List of 21 landmarks
        bbox1 = hand1["bbox"]  # x,y,w,h of bounding box
        centerPoint1 = hand1["center"]  # center of the hand cx,cy
        handType1 = hand1["type"]
        finger1 = detector.fingersUp(hand1)
        #print(finger1)
        f1= finger1
        #print(handType1)
    if f1 == [0, 0, 0, 0, 0]:
        print("select the BOT ")

    elif f1 == [0, 1, 0, 0, 0]:
        sock = socket.socket(socket.AF_INET,  # Internet
                             socket.SOCK_DGRAM)  # UDP
        sock.sendto(mess2.encode(), (ip1, ip_port))
        print("BOT 1 forword")

    elif f1 == [0, 1, 0, 0, 0]:
        sock = socket.socket(socket.AF_INET,  # Internet
                             socket.SOCK_DGRAM)  # UDP
        sock.sendto(mess3.encode(), (ip1, ip_port))
        print("BOT 1 Backward")
    elif f1 ==[0,1,1,0,0]:
        sock = socket.socket(socket.AF_INET,  # Internet
                             socket.SOCK_DGRAM)  # UDP
        sock.sendto(mess4.encode(), (ip1, ip_port))
        print("BOT 1 Left")
    elif f1==[0,1,1,1,0]:
        sock = socket.socket(socket.AF_INET,  # Internet
                             socket.SOCK_DGRAM)  # UDP
        sock.sendto(mess5.encode(), (ip1, ip_port))
        print("BOT 1 Right")


    cv2.imshow("Image", img)
    cv2.waitKey(100)


