import numpy as np
import cv2
from google.colab.patches import cv2_imshow

def main():

    S = 50
    H = 50*8
    W = 50*12

    img = np.zeros((H, W, 3), np.uint8)
    img[:, :] = [0, 0, 0]

    for j in range(H // S):
        for i in range(W // S):
            if (i + j) % 2 == 0:
                img[j*S:(j+1)*S, i*S:(i+1)*S] = [50, 190, 80]

    cv2_imshow(img)

if __name__ == '__main__':
    main()
