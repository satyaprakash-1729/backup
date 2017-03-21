import cv2
import numpy as np
cap = cv2.VideoCapture(0)
_,frame1 = cap.read()
kernel = np.array([[-1,-1,-1],[-1,8,-1],[-1,-1,-1]])
while True:
    a, frame = cap.read()

    frame[50:200][50:350] = frame1[50:200][50:350]
    frame[250:400][400:550] = frame1[250:400][400:550]

    cv2.imshow("frame", frame)
    k = cv2.waitKey(1) & 0xFF
    if k==27:
        break

cv2.destroyAllWindows()
cap.release()
