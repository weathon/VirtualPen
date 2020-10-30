import cv2
image = cv2.imread("test.jpg")
pixel= image[200, 550]
grayImage = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
# image.save("out.jpg")
cv2.imshow("gray",grayImage)
cv2.waitKey(0)
cv2.imwrite("out.jpg", grayImage) 
# fan guolai? zhi you da mian ji bai se cia? ji yi?fang zhi shan shuo?

