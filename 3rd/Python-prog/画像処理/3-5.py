import numpy as np
import cv2           # OpenCV
from google.colab.patches import cv2_imshow

image_file = 'Girl.jpg'

def RGB2GRAY(img):
    print(img.shape)
    height, width, col = img.shape

    dist_img = np.zeros((height, width), np.uint8)

    for j in range(height):
        for i in range(width):
            B, G, R = img[i,j]
            dist_img[i,j] = 0.21 * R + 0.72 * G + 0.07 * B

    return dist_img

def main():
    img = cv2.imread(image_file)

    if img is None:
        print('File Open Error.')
        return

    img2 = RGB2GRAY(img)

    cv2_imshow(img)
    cv2_imshow(img2)

if __name__ == '__main__':
    main()
