import numpy as np
import cv2
from google.colab.patches import cv2_imshow

image_file = 'Girl.jpg'

def main():
    img = cv2.imread(image_file)

    if img is None:
        print('File Open Error.')
        return

    cv2_imshow(img)

    img2 = cv2.cvtColor(img, cv2.COLOR_RGB2GRAY)
    cv2_imshow(img2)

    ret, img2bin = cv2.threshold(img2, 50, 255, cv2.THRESH_BINARY)
    cv2_imshow(img2bin)

if __name__ == '__main__':
    main()
