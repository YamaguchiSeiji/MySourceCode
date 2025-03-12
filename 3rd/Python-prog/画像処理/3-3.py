import numpy as np
import cv2           # OpenCV
from google.colab.patches import cv2_imshow

def main():
    img = np.zeros((400, 600, 3), np.uint8)

    img[:, :] = [255, 0, 0]

    cv2.line(img, (50, 50), (250, 350), (255, 255, 255))
    cv2.line(img, (50, 350), (250, 50), (255, 255, 255), 10)

    cv2_imshow(img)


if __name__ == '__main__':
    main()
