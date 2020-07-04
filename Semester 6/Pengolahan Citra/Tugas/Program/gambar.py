# 1. Import library
import cv2

# 2. Membaca gambar
img = cv2.imread('kucing.jpg')
negatif = 255 - img

# 3. Menampilkan gambar
cv2.imshow('gambar asli', img)
cv2.imshow('gambar negatif', negatif)

# 4. Menunda windows terdestroy
cv2.waitKey(0)

# 5. Mendestroy windows
cv2.destroyAllWindows()
