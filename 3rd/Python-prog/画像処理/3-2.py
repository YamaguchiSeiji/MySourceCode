import numpy as np
import cv2           # OpenCV
from google.colab.patches import cv2_imshow

def main():
    img = np.zeros((400, 600, 3), np.uint8)

    img[:, :] = [127, 127, 127]
    cv2_imshow(img)


if __name__ == '__main__':
    main()
