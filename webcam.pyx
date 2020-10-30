# https://medium.com/@jeppbautista/connect-android-camera-to-python-using-opencv-90fd19d838

import cv2



import cython

# @cython.boundscheck(False)
cpdef void main():
# def main():
    # URL = "http://192.168.0.34:4747/video"
    # cap = cv2.VideoCapture(URL)
    cap = cv2.VideoCapture(0)
    ret, frame = cap.read()
    grayImage = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    height, width = grayImage.shape[:2]#keyihuancun

    while True:
        ret, frame = cap.read()
        grayImage = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        for i in range(width-1):
            for j in range(height-1):
                grayImage[j,i]-=200
        # grayImage=255-grayImage
        cv2.imshow("Capturing",grayImage)
        cv2.resizeWindow("Capturing",600,600)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    cap.release()
    cv2.destroyAllWindows()

main()
# https://stackoverflow.com/questions/49978705/access-ip-camera-in-python-opencv

