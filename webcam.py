# import urllib.request
# import cv2
# import numpy as np
# import time
# # URL = "http://192.168.43.1:8080"
# URL = "rtsp://192.168.0.34:8080/h264_ulaw.sdp"

# while True:
#     img_arr = np.array(bytearray(urllib.request.urlopen(URL).read()),dtype=np.uint8)
#     img = cv2.imdecode(img_arr,-1)
#     cv2.imshow('IPWebcam',img)
    
#     if cv2.waitKey(1):
#         break

# https://medium.com/@jeppbautista/connect-android-camera-to-python-using-opencv-90fd19d838

import cv2

#print("Before URL")
URL = "http://192.168.0.34:4747/video"

# cap = cv2.VideoCapture('rtsp://admin:123456@192.168.1.216/H264?ch=1&subtype=0')
cap = cv2.VideoCapture(URL)

#print("After URL")

while True:

    #print('About to start the Read command')
    ret, frame = cap.read()
    #print('About to show frame of Video.')
    cv2.imshow("Capturing",frame)
    #print('Running..')

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()

# https://stackoverflow.com/questions/49978705/access-ip-camera-in-python-opencv