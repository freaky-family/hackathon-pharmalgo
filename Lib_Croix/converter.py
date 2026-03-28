#!/usr/bin/env python3
# /// script
# dependencies = [
#   "Pillow",
# ]
# ///

from PIL import Image
im = Image.open('200077414.png.converted')

rgb_im = im.convert('RGB')
width, height = rgb_im.size

with open("image.txt", "w+") as f:
    for y in range(height):
        for x in range(width):
            r, g, b = rgb_im.getpixel((x, y))

            if r == 0 and g == 0 and b == 0:
                f.write(".")
            else:
                f.write("x")
            # print(x, y, r, g, b)
        f.write("\n")

