import numpy as np
import cv2
from google.colab.patches import cv2_imshow
import matplotlib.pyplot as plt


image_file = 'Girl.jpg'

def main():
    img = cv2.imread(image_file)

    if img is None:
        print('File Open Error.')
        return

    cv2_imshow(img)

    img2 = cv2.cvtColor(img, cv2.COLOR_RGB2GRAY)
    cv2_imshow(img2)

    plt.hist(img2, bins = 100, range = (0,255))
    plt.show()

    img3 = cv2.equalizeHist(img2)
    cv2_imshow(img3)

    plt.hist(img3, bins = 100, range = (0,255))
    plt.show()

if __name__ == '__main__':
    main()
