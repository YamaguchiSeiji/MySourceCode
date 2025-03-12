import numpy as np
import cv2           # OpenCV
from google.colab.patches import cv2_imshow

image_file = 'Girl.jpg'

def main():
    img = cv2.imread(image_file)

    if img is None:
        print('File Open Error.')
        return

    img2 = cv2.cvtColor(img, cv2.COLOR_RGB2GRAY)

    cv2_imshow(img)
    cv2_imshow(img2)
    print('img', img.shape)
    print('img2', img2.shape)

if __name__ == '__main__':
    main()
