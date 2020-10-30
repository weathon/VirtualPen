# https://medium.com/@jeppbautista/connect-android-camera-to-python-using-opencv-90fd19d838

import cv2
import numpy as np


import cython
print(cv2.useOptimized())
# @cython.boundscheck(False)
def main():
    cap = cv2.VideoCapture(0)
    ret, frame = cap.read()
    grayImage = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    height, width = grayImage.shape[:2]#keyihuancun

    while True:
        ret, frame = cap.read()
        grayImage = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        # for i in range(width-1):
        #     for j in range(height-1):
        #         grayImage[j,i]-=200
        # grayImage=255-grayImage
        # img = grayImage
        gray = img = grayImage #cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
        # ret,gray = cv2.threshold(gray,150,200,200)
        ret,gray = cv2.threshold(gray,np.mean(gray),255,cv2.THRESH_BINARY)
        gray2 = gray.copy()
        mask = np.zeros(gray.shape,np.uint8)

        contours, hier = cv2.findContours(gray,cv2.RETR_LIST,cv2.CHAIN_APPROX_SIMPLE)
        for cnt in contours:
            if 20<cv2.contourArea(cnt)<100:
                cv2.drawContours(img,[cnt],0,(0,255,0),2)
                cv2.drawContours(mask,[cnt],0,255,-1)
                
        # https://stackoverflow.com/questions/10262600/how-to-detect-region-of-large-of-white-pixels-using-opencv
        cv2.imshow("Capturing",gray2)
        cv2.resizeWindow("Capturing",600,600)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    cap.release()
    cv2.destroyAllWindows()

main()
# https://stackoverflow.com/questions/49978705/access-ip-camera-in-python-opencv

