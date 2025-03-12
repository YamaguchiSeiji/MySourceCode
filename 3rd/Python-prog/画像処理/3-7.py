import numpy as np
import cv2
from google.colab.patches import cv2_imshow

image_file = 'Girl2.jpg'

def main():
    img = cv2.imread(image_file)

    if img is None:
        print('File Open Error.')
        return

    height, width, col = img.shape
    print(height, width, col)

    for i in range(width // 2, width):
        img[:, i] = img[:, width-i]

    cv2_imshow(img)

if __name__ == '__main__':
    main()
