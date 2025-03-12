import numpy as np
import cv2           # OpenCV

def main():
    img = np.zeros((400, 600, 3), np.uint8)

    cv2.imshow('Image', img)

    cv2.waitKey(0)
    cv2.destroyAllWindows()

if __name__ == '__main__':
    main()
