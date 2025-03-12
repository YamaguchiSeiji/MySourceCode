~
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

    img2 = np.zeros((width, height, 3), np.uint8)

    for i in range(height):
        for j in range(width):
            img2[width-j-1, i] = img[i,j]

    cv2_imshow(img)
    cv2_imshow(img2)

if __name__ == '__main__':
    main()
